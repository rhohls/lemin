/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_collection.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhohls <rhohls@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/13 07:47:34 by rhohls            #+#    #+#             */
/*   Updated: 2018/08/29 08:45:26 by rhohls           ###   ########.fr       */
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
		printf("Error reading data\n");
		exit(0);
	}
	else if (gnl_ret == 0 && (lemin->map_feed == NULL))
	{
		printf("Error reading data\n");
		exit(0);
	}
}

static void	capture_data_1(int fd, t_lemin **lemin, char **line, t_list **node)
{
	*lemin = init_lemin();
	read_data(*lemin, fd);
	*line = (*lemin)->map_feed->content;
	*node = (*lemin)->map_feed->next;
	(*lemin)->num_ants = ft_atoi_long(*line);
	if ((*lemin)->num_ants <= 0)
	{
		ft_dprintf(1, "Error: Bad number of ants\n");
		exit(0);
	}
}

t_lemin		*capture_data(int fd)
{
	t_lemin *lemin;
	char	*line;
	t_list	*node;

	capture_data_1(fd, &lemin, &line, &node);
	while (node)
	{
		line = node->content;
		if (bad_command(line))
		{
			printf("Error:\n Bad line: |%s|\n", line);
			exit(0);
		}
		else if (line[0] == '#' && line[1] == '#')
			add_special_room(line + 2, lemin, &node);
		else if (ft_strchr(line, '-'))
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
}
