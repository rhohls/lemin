/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_connection.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhohls <rhohls@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/13 07:47:15 by rhohls            #+#    #+#             */
/*   Updated: 2018/08/31 14:22:10 by rhohls           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lemin.h"
#include <stdio.h>

void	add_con_struct(char *room_name, t_lemin *lemin)
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
}

t_con	*find_con(t_stack *connections, char *room_name)
{
	t_list	*node;
	t_con	*connect;
	
	node = connections->start;
	while (node)
	{
		connect = node->content;
		if (ft_strcmp(connect->name, room_name) == 0)
		{
			return (connect);
		}
		node = node->next;
	}
	ft_putstr("exiting cause:\n");
	ft_printf("No room |%s| found when trying to add connection\n", room_name);
	exit(6);
}

void	add_connection(char *str, t_lemin *lemin)
{
	char	**con_details;
	t_con	*room_con;
	t_list	*node;

	if (!(con_details = ft_strsplit(str, '-')))
	{
		ft_printf("Error:\nFail malloc\n");
		exit(0);
	}
	if (con_details[2] != NULL)
	{
		ft_printf("Error:\nIssue with adding a connection\n");
		exit(0);
	}
	room_con = find_con(lemin->connections, con_details[0]);
	node = ft_lstnew(con_details[1], ft_strlen(con_details[1]));
	ft_stackpush(room_con->connect_list, node);
	room_con = find_con(lemin->connections, con_details[1]);
	node = ft_lstnew(con_details[0], ft_strlen(con_details[0]));
	ft_stackpush(room_con->connect_list, node);
	ft_del_chararr(con_details, 3);
}
