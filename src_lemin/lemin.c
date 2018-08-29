/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lemin.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhohls <rhohls@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/07 08:56:17 by rhohls            #+#    #+#             */
/*   Updated: 2018/08/29 09:00:17 by rhohls           ###   ########.fr       */
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
	t_list	*node;
	
	lemin = capture_data(0);
	post_data_collect(lemin);	
	ant.number = 1;
	ant.path = NULL;
	find_path(lemin, &ant);
	if (ant.path == NULL || ant.path->start == NULL)
	{
		ft_dprintf(1, "Error: No path found\n");
		exit(0);
	}
	node = ft_stackpop(ant.path);
	if (node)
	{
		if (node->content)
			free(node->content);
		free(node);
	}
	assign_path(lemin, ant.path);
	node = lemin->map_feed;
	while(node)
	{
		ft_putendl(node->content);
		node = node->next;	
	}
	ft_putchar('\n');
	print_ant_moves(lemin);
	return (1);
}
