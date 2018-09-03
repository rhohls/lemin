/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhohls <rhohls@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/13 07:48:57 by rhohls            #+#    #+#             */
/*   Updated: 2018/09/03 08:12:47 by rhohls           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lemin.h"

void	print_ant_details(t_ant *ant)
{
	printf("Number: %i\n", ant->number);
	printf("Turn start: %i\n", ant->turn_num);
	printf("Ant moves:\n");
	print_str_stack(ant->path);
}


void	print_str_stack(t_stack *stack)
{
	t_list *node;

	if (!stack || !stack->start)
	{
		printf("\tNothing to print\n");
		return ;
	}
	node = stack->start;
	while(node)
	{
		printf("\t%s\n", (char *)(node->content));
		node = node->next;
	}
}

void	print_str_connection(t_stack *con_list_stack)
{
	t_list  *connection;

	if (!con_list_stack || !con_list_stack->start)
	{
		printf("\t\tNo connections\n");
		return ;
	}
	connection = con_list_stack->start;
	while(connection)
	{
		printf("\t\t%s\n", (char *)(connection->content));
		connection = connection->next;
	}
}

void	print_char_starstar(char** str_list, int num_str)
{
	int i;

	i = 0;
	while (i < num_str)
	{
		printf("\t\t%s\n", str_list[i]);
		i++;
	}
}

void	print_turnmoves(t_stack *turn_moves)
{
	t_list  *turn;
	int     i;

	if (!turn_moves || !turn_moves->start)
		return ;
	turn = turn_moves->start;
	i = 0;
	while(turn)
	{
		printf("\tTurn number: -%i-\n", i);
		print_char_starstar(turn->content, turn->content_size);
		turn = turn->next;
		i++;
	}
}

void	print_connections(t_stack *conections)
{
	t_list  *node;
	t_con   *conn;

	if (!conections || !conections->start)
		return ;
	node = conections->start;
	while(node)
	{
		conn = node->content;
		printf("\tRooms connected to: \"%s\"\n", conn->name);
		print_str_connection(conn->connect_list);
		node = node->next;
	}
}

void    print_lemin(t_lemin *lemin)
{
	printf("\n\n~~~  LEMIN DETAILS  ~~~\n");
	printf("Start |%s|\n", lemin->start);
	printf("End   |%s|\n", lemin->end);
	printf("Number of ants :%i:\n", lemin->num_ants);
	printf("\nAll room names:\n");
	print_str_stack(lemin->room_list);
	printf("\t-done-\n");

	printf("\nTurn moves:\n");
	print_turnmoves(lemin->turn_moves);
	
	printf("\nConnections:\n");
	print_connections(lemin->connections);

}