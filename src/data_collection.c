/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inits.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhohls <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/07 09:02:02 by rhohls            #+#    #+#             */
/*   Updated: 2018/08/07 09:02:27 by rhohls           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../includes/lemin.h"

void add_connection(char *str, t_lemin *lemin)
{
	char **rooms;

	/*
	check room is in room list (str in stack)
		return "room doesnt exit"
	string split the line
	add connection to room 1
	add connection to room 2
	free strsplit
	*/
}

void add_room(char *str, t_lemin *lemin)
{
	/* 
	str_split ensure there is 3 (name, x, y)
	add to room list
	and coonection list
	*/
}
void add_special_room(char *str, t_lemin *lemin, int fd)
{
	char *line;

	if (get_next_line(fd, &line) != 1)
	{
		printf("bad gnl\n");
		exit(0);		
	}	
	if (ft_strcmp(str, "start") == 0)
		lemin->start = ft_strdup(line); // not going to work (need strsplit)
	else if (ft_strcmp(str, "end") == 0)
		lemin->end = ft_strdup(line);
	else
	{
		printf("Bad command: |##%s|", str);
		exit(0);		
	}
	add_room(line, lemin);
	free(line);
}

int bad_command(char *str)
{
	if (str == NULL || str[0] == "\0" || str[0] == "\n")
		return (1);
	else
		return (0);
}

t_lemin *capture_data(void)
{
	t_lemin *lemin;
	char	*line;
	int		fd;

	fd = 0;
	lemin = (t_lemin *)malloc(sizeof(t_lemin));
	if (get_next_line(fd, &line) != 1)
	{
		printf("bad");
		exit(0);
	}
	//atoi str cmp for 0
	lemin->num_ants = ft_atoi(line);
	free(line);

	while(get_next_line(fd, &line) == 1)
	{
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
			// break into new gnl loop
			// maybe - cause all conns come after rooms
			add_connection(line, lemin);
		}
		else if (line[0] != '#')
		{
			// its a room! (add it) - not sure if going to 
			add_room(line, lemin);
		}
		free(line);
	}
	return(lemin);
}