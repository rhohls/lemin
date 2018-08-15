/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_room.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhohls <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/13 07:47:25 by rhohls            #+#    #+#             */
/*   Updated: 2018/08/13 07:47:27 by rhohls           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lemin.h"

void add_room(char *str, t_lemin *lemin)
{
	/* 
	str_split ensure there is 3 (name, x, y)
	add to room list
	and coonection list
	*/
	char **room_details;
	char *room_name;

	printf("Adding room from string : \"%s\"\n", str);
	printf("start add 1 |%s| add %p\n", lemin->start, lemin->start);
	room_details = ft_strsplit(str, ' ');
	printf("start add 2 |%s| add %p\n", lemin->start, lemin->start);
	printf("Adding room from string : \"%s\" with room name |%s|\n", str, room_details[0]);
	
	if (room_details[3] != NULL)
	{
		printf("Issue with deatials of room (Incorrect number of arguments)\n");
		exit(0);
	}
	room_name = room_details[0];
	// check its name not already in list
	ft_stackpush(lemin->room_list,
					ft_lstnew(room_name, ft_strlen(room_name)));
	add_con_struct(room_name, lemin);
	ft_del_chararr(room_details, 3);
	printf("start add 3 |%s|\n", lemin->start);
}

void add_special_room(char *str, t_lemin *lemin, int fd)
{
	char	*line;
	char	*room_name;

	if (get_next_line(fd, &line) != 1) // do i need this?
	{
		printf("bad gnl\n");
		exit(0);		
	}
	printf("line spec:|%s|\n", line);
	add_room(line, lemin);
	room_name = (char *)(lemin->room_list->start->content);
	printf("got room name :|%s| from linked list\n", room_name);
	if (ft_strcmp(str, "start") == 0)
	{
		printf("adding to start with: %s\n", room_name);
		lemin->start = room_name;
	}
	else if (ft_strcmp(str, "end") == 0)
	{
		lemin->end = room_name;
	}
	else
	{
		printf("Bad command: |##%s|", str);
		exit(0);		
	}
	printf("special start |%s|\n", lemin->start);
	// free(line);
}
