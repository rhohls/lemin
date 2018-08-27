/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lemin.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhohls <rhohls@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/07 08:56:17 by rhohls            #+#    #+#             */
/*   Updated: 2018/08/27 08:15:55 by rhohls           ###   ########.fr       */
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
	// char *line;

	lemin = capture_data(0);

	printf("main rooms:\n");
	print_str_stack(lemin->room_list);
	printf("\tdone\n");

	print_lemin(lemin);
	printf("---- lemin deatils done ----\n\n");
	// printf("all data captured?, check leaks?\n");
	// sleep(5);
	
	ant.number = 1;
	ant.path = NULL;
	// ant.turn_start = 0;
	find_path(lemin, &ant);

	if (ant.path == NULL || ant.path->start == NULL)
	{
		ft_dprintf(2, "No path found\n");
		exit(0);
	}
	printf("\n-- Ant details --\n");
	print_ant_details(&ant);
	printf("\n~~!!  Printing offcial path  !!~~\n");

	// t_list *node;
	// node = lemin->map_feed;
	// while(node)
	// {
	// 	printf("%s\n",node->content);
	// 	node = node->next;	
	// }

	// ft_putstr("\n");
	// print_moves(ant.path, lemin->num_ants);
	// while(1)
	// {}
	
	t_list	*node;
	
	node = ft_stackpop(ant.path);
	free(node->content);
	free(node);
	assign_path(lemin, ant.path);
	printf("assigned paths\n");
	
	print_ant_moves(lemin);
	
	
	return (1);
}
