/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lemin.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhohls <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/07 08:56:17 by rhohls            #+#    #+#             */
/*   Updated: 2018/08/07 09:00:43 by rhohls           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lemin.h"

t_ant *get_ant(t_lemin* lemin, int ant_num)
{
	if (ant_num < 0)
		lemin->num_ants = ant_num;
	return (NULL);		
}

void play_game(t_lemin* lemin)
{
	int		i;
	// t_ant	*ant;
	i = 0;

	while (i < lemin->num_ants)
	{
		// ant = get_ant(lemin, i);
		// ant->path = find_path(lemin);
		// update_moves(ant->path);
		i++;
	}
}

#include <unistd.h>
int main()
{
	t_ant	ant;
	t_lemin *lemin;
	char *line;

	lemin = capture_data(0);
	get_next_line(0, &line);
	if (line)
		free(line);

	print_lemin(lemin);
	printf("---- lemin deatils done ----\n\n");
	// printf("all data captured?, check leaks?\n");
	// sleep(5);
	// t_con *connect = lemin->connections->start->content;
	// char **list;
	// int i = 0;
	// list = connect->conections;
	// while (i < connect->connect_list->length)
	// {
	// 	printf("room: %s\n", list[i]);
	// 	i++;
	// }	
	

	get_next_line(0, &line);
	if (line)
		free(line);
	
	ant.number = 1;
	ant.path = NULL;
	ant.turn_start = 0;
	find_path(lemin, &ant);
	if (ant.path == NULL)
	{
		
	}
	printf("\n-- Ant details --\n");
	print_ant_details(&ant);
	printf("\nPrinting offcial path\n");
	print_moves(ant.path, lemin->num_ants);
	while(1)
	{}
	return (1);
}
