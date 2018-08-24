/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_collection.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhohls <rhohls@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/13 07:47:34 by rhohls            #+#    #+#             */
/*   Updated: 2018/08/24 14:55:24 by rhohls           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lemin.h"

int bad_command(char *str)
{
	if (str == NULL || str[0] == '\0' || str[0] == '\n')
		return (1);
	else
		return (0);
}

void	ft_lstaddfront(t_list **alst, t_list *new_lst)
{
	t_list *node;

	if(!alst || !new_lst)
		return ;
	if (*alst == NULL)
	{
		*alst = new_lst;
		return;
	}
	node = *alst;
	while(node->next != NULL)
		node = node->next;
	node->next = new_lst;
}

void	read_data(t_lemin *lemin, int fd)
{
	char	*line;
	int		gnl_ret;
	t_list	*temp;

	while ((gnl_ret = get_next_line(fd, &line)) == 1)
	{
		// printf("add line: |%s|\n", line);
		temp = ft_lstnew(line, ft_strlen(line) + 1);
		// printf("stored content: |%s|\n", temp->content);
		ft_lstaddfront(&(lemin->map_feed), temp);
		free(line);
	}

	if (get_next_line(fd, &line) == -1)
	{
		printf("Error reading\n");
		exit(0);
	}
}


t_lemin *capture_data(int fd)
{
	t_lemin *lemin;
	char	*line;
	t_list	*node;

	lemin = (t_lemin *)malloc(sizeof(t_lemin));
	init_lemin(lemin);

	read_data(lemin, fd);
	
	node = lemin->map_feed;
	while(node)
	{
		line = node->content;
		printf("line: |%s|\n",line);
		node = node->next;	
	}

	node = lemin->map_feed;
	line = node->content;
	node = node->next;	

	printf("line is: %s\n", line);
	lemin->num_ants = ft_atoi(line);
	if (lemin->num_ants == 0)
	{
		ft_dprintf(2, "Error: Bad number of ants\n");
		exit(0);		
	}

	while(node)
	{
		line = node->content;
		printf("gnl line :|%s|\n", line);
		printf("room_list:\n");
		print_str_stack(lemin->room_list);
		printf("\tdone\n");
		if (bad_command(line))
		{
			printf("bad command: |%s|", line);
			exit(0);
		}
		else if (line[0] == '#' && line[1] == '#')
		{
			add_special_room(line + 2, lemin, &node);
		}
		else if (ft_strchr(line, '-'))
		{
			// break into new gnl loop -- do this !!!!
			// maybe - cause all conns come after rooms
			add_connection(line, lemin);
		}
		else if (line[0] != '#')
		{
			printf("adding from room :%s\n", line);
			// printf("not #1 |%s|\n", lemin->start);
			add_room(line, lemin);
			// printf("not #2 |%s|\n", lemin->start);
		}
		// printf("check leaks\n\n");
		// sleep(1);
		// free(line);
		node =node->next;
	}
	update_capture(lemin);

	printf("room_list:\n");
	print_str_stack(lemin->room_list);
	printf("\tdone\n");
	return(lemin);
}

void		update_con(t_lemin *lemin)
{
	t_list	*node;
	t_con	*con;

	node = lemin->connections->start;
	while(node)
	{
		con = node->content;
		con->num_connections = con->connect_list->length;
		con->conections = ft_stacktochar(con->connect_list);
		node = node->next;
	}	
}
void		update_capture(t_lemin *lemin)
{
	update_con(lemin);
}