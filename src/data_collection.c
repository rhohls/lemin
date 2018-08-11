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
#include <stdio.h>

void init_lemin(t_lemin *lemin)
{
	lemin->start = NULL;
	lemin->end = NULL;
	lemin->num_ants = 0;
	lemin->room_list = ft_stacknew();
	lemin->ant_list = ft_stacknew();
	lemin->turn_moves = ft_stacknew();
	lemin->connections = ft_stacknew();
}

void add_con_struct(char *room_name, t_lemin *lemin)
{
	t_con	*new;
	t_list	*node;

	new = (t_con *)malloc(sizeof(t_con));
	new->name = ft_strdup(room_name);
	new->conections = NULL;
	new->num_connections = 0;
	new->connect_list = ft_stacknew();

	node = ft_lstnew(NULL, 0);
	node->content = (void *)new;

	ft_stackpush(lemin->connections, node);

	// printf("detail add construct\n %p - %s \n", ((t_con *)lemin->connections->start->content)->name,(char*)((t_con *)lemin->connections->start->content)->name);
	}

t_con *find_con(t_stack *connections, char *room_name)
{
	t_list	*node;
	t_con	*connect;

	node = connections->start;
	while(node)
	{
		connect = node->content;
		printf("comparing input |%s| with conn name |%s|\n", room_name, connect->name);
		if (ft_strcmp(connect->name, room_name) == 0)
			return(connect);
		node = node->next;
	}
	ft_putstr("exiting cause:\n");
	printf("No room |%s| found when trying to add connection\n", room_name);
	exit(0);
}

void add_connection(char *str, t_lemin *lemin)
{
	/*
	check room is in room list (str in stack)
		return "room doesnt exit"
	string split the line
	add connection to room 1
	add connection to room 2
	free strsplit
	*/
	char **con_details;
	t_con *room_con;


	printf("printing all con names\n");
	print_str_connection(lemin->connections);

	ft_putstr("1\n");
	printf("line in : %s\n", str);

	if (!(con_details = ft_strsplit(str, '-')))
	{
		printf("fail malloc strsplit for connection\n");
		exit(0);
	}
	if (con_details[2] != NULL)
	{
		printf("Issue with adding a connection (more than 2 arguments)\n");
		exit(0);
	}
	printf("room1 |%s| room2 |%s|\n", con_details[0], con_details[2]);
	ft_putstr("2\n");
	room_con = find_con(lemin->connections, con_details[0]);
	ft_stackpush(room_con->connect_list,
				ft_lstnew(con_details[0], ft_strlen(con_details[0])));
	room_con = find_con(lemin->connections, con_details[1]);
	ft_stackpush(room_con->connect_list,
				ft_lstnew(con_details[1], ft_strlen(con_details[1])));
	// printf("detail addconection2\n %s \n", (char*)((t_con *)lemin->connections->start->content)->name);
	// ft_del_chararr(con_details, 2);			
}

void *add_room(char *str, t_lemin *lemin)
{
	/* 
	str_split ensure there is 3 (name, x, y)
	add to room list
	and coonection list
	*/
	char **room_details;
	char *room_name;

	room_details = ft_strsplit(str, ' ');
	if (room_details[3] != NULL)
	{
		printf("Issue with deatials of room (more than 3 arguments)\n");
		exit(0);
	}
	room_name = room_details[0];
	// check its name not already in list
	ft_stackpush(lemin->room_list,
					ft_lstnew(room_name, ft_strlen(room_name)));
	add_con_struct(room_name, lemin);
	ft_del_chararr(room_details, 3);
	// printf("detail addroom\n %p - %s \n", ((t_con *)lemin->connections->start->content)->name,(char*)((t_con *)lemin->connections->start->content)->name);

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
	add_room(line, lemin);
	room_name = (char *)(lemin->room_list->start->content);
	if (ft_strcmp(str, "start") == 0)
		lemin->start = room_name;
	else if (ft_strcmp(str, "end") == 0)
		lemin->end = room_name;
	else
	{
		printf("Bad command: |##%s|", str);
		exit(0);		
	}
	free(line);
}

int bad_command(char *str)
{
	if (str == NULL || str[0] == '\0' || str[0] == '\n')
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
	init_lemin(lemin);
	if (get_next_line(fd, &line) != 1)
	{
		printf("bad gnl return\n");
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

int main()
{
	t_lemin *lemin;
	lemin = capture_data();
	// printf("rooms? %p\n", lemin->room_list);
	print_lemin(lemin);
	return (1);
}