/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_collection.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhohls <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/13 07:47:34 by rhohls            #+#    #+#             */
/*   Updated: 2018/08/13 07:47:39 by rhohls           ###   ########.fr       */
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

t_lemin *capture_data(int fd)
{
	t_lemin *lemin;
	char	*line;

	lemin = (t_lemin *)malloc(sizeof(t_lemin));
	init_lemin(lemin);
	if (get_next_line(fd, &line) != 1)
	{
		printf("Bad gnl return\n");
		exit(0);
	}
	//atoi str cmp for 0 !!!
	lemin->num_ants = ft_atoi(line);
	if (lemin->num_ants == 0)
	{
		printf("Bad number of ants\n");
		exit(0);		
	}
	free(line);

	while(get_next_line(fd, &line) == 1)
	{
		printf("gnl line :|%s|\n", line);
		// printf("start |%s|\n", lemin->start);
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
			add_special_room(line + 2, lemin, fd);
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
		printf("check leaks\n\n");
		sleep(1);
		free(line);
	}
	update_capture(lemin);
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