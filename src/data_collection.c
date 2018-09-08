/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_collection.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhohls <rhohls@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/13 07:47:34 by rhohls            #+#    #+#             */
/*   Updated: 2018/09/08 14:24:25 by rhohls           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lemin.h"

int			bad_command(char *str)
{
	if (str == NULL || str[0] == '\0' || str[0] == '\n')
		return (1);
	else
		return (0);
}

void		read_data(t_lemin *lemin, int fd)
{
	char	*line;
	int		gnl_ret;
	t_list	*temp;

	while ((gnl_ret = get_next_line(fd, &line)) == 1)
	{
		temp = ft_lstnew(line, ft_strlen(line) + 1);
		ft_lstaddfront(&(lemin->map_feed), temp);
		free(line);
	}
	if (gnl_ret == -1)
	{
		ft_printf("Error reading data\n");
		exit(0);
	}
	else if (gnl_ret == 0 && (lemin->map_feed == NULL))
	{
		ft_printf("Error reading data\n");
		exit(0);
	}
}

static void	capture_data_1(int fd, t_lemin **lemin, char **line, t_list **node)
{
	read_data(*lemin, fd);
	*node = (*lemin)->map_feed;
	while (*node && (*node)->content && ((char *)((*node)->content))[0] == '#')
		*node = (*node)->next;
	*line = (*node)->content;
	if (bad_command(*line))
	{
		ft_printf("Error:\nBad line: |%s|\n", *line);
		exit(0);
	}
	(*lemin)->num_ants = ft_atoi_long(*line);
	if ((*lemin)->num_ants <= 0)
	{
		ft_printf("Error: Bad number of ants\n");
		ft_printf("string %s\n", *line);
		exit(0);
	}
	*node = (*node)->next;
}

t_lemin		*capture_data(int fd)
{
	t_lemin *lemin;
	char	*line;
	t_list	*node;

	lemin = init_lemin();
	capture_data_1(fd, &lemin, &line, &node);
	while (node)
	{
		line = node->content;
		if (bad_command(line))
		{
			ft_printf("Error:\nBad line: |%s|\n", line);
			exit(0);
		}
		else if (line[0] == '#' && line[1] == '#')
			add_special_room(line + 2, lemin, &node);
		else if (line[0] != '#' && ft_strchr(line, '-'))
			add_connection(line, lemin);
		else if (line[0] != '#')
			add_room(line, lemin);
		node = node->next;
	}
	update_capture(lemin);
	return (lemin);
}

void		update_capture(t_lemin *lemin)
{
	t_list	*node;
	t_con	*con;

	node = lemin->connections->start;
	while (node)
	{
		con = node->content;
		con->num_connections = con->connect_list->length;
		con->conections = ft_stacktochar(con->connect_list);
		node = node->next;
	}
	lemin->num_rooms = lemin->room_list->length;
}
