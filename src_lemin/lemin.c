/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lemin.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhohls <rhohls@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/07 08:56:17 by rhohls            #+#    #+#             */
/*   Updated: 2018/08/28 13:48:16 by rhohls           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lemin.h"

t_ant *get_ant(t_lemin* lemin, int ant_num)
{
	if (ant_num < 0)
		lemin->num_ants = ant_num;
	return (NULL);		
}

void	post_data_collect(t_lemin *lemin)
{
	if (lemin->start == NULL)
		ft_putstr("Error: missing start room\n");
	else if (lemin->end == NULL)
		ft_putstr("Error: missing end room\n");
	else
		return ;
	exit(0);
}

#include <unistd.h>
int main()
{
	t_ant	ant;
	t_lemin *lemin;
	// char *line;
	// printf("1\n");
	lemin = capture_data(0);
	// printf("2\n");
	post_data_collect(lemin);
	// printf("2.5\n");
	// printf("main rooms:\n");
	// print_str_stack(lemin->room_list);
	// printf("\tdone\n");

	// print_lemin(lemin);
	// printf("---- lemin deatils done ----\n\n");
	// printf("all data captured?, check leaks?\n");
	// sleep(5);
	
	ant.number = 1;
	ant.path = NULL;
	// ant.turn_start = 0;
	find_path(lemin, &ant);
	// printf("2.75\n");
	if (ant.path == NULL || ant.path->start == NULL)
	{
		ft_dprintf(1, "Error: No path found\n");
		exit(0);
	}
	// printf("\n-- Ant details --\n");
	// print_ant_details(&ant);
	// printf("\n-~~~!!  Printing offcial info  !!~~~-\n\n");

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
	// printf("3\n");
	t_list	*node;
	
	node = ft_stackpop(ant.path);
	if (node)
	{
		if (node->content)
			free(node->content);
		free(node);
	}
	assign_path(lemin, ant.path);
	// printf("assigned paths\n");
	
	// printf("4\n");
	node = lemin->map_feed;
	while(node)
	{
		ft_putendl(node->content);
		// printf("line: |%s|\n",line);
		node = node->next;	
	}
	ft_putchar('\n');
	// printf("5\n");
	print_ant_moves(lemin);
	// printf("6\n");
	return (1);
}
