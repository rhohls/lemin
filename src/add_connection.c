
#include "../includes/lemin.h"
#include <stdio.h>

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