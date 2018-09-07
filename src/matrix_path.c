/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_path.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhohls <rhohls@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/07 11:43:28 by rhohls            #+#    #+#             */
/*   Updated: 2018/09/07 14:29:32 by rhohls           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lemin.h"
//	add index of room to curr path
//
//	if in the end room
// 		adjust shortest path
//	else
//		i = num_rooms
//		if path length < shortest path length
// 			while i >= 0 
// 				if (i is in curr path)
// 					skip
// 				else
// 					find_path (index)
//	curr_path[index] = -1
//	return
//

int		not_visted(int key_index, t_path path)
{
	int i;
	
	i = 0;
	while (i < path.length)
	{
		if (path.path[i] == key_index)
			return (0);
		i++;
	}
	return (1);
}

void	adjust_shortest_path(t_lemin *lemin)
{
	int i;
	
	i = 0;
	printf("adjusting path\n");
	if (lemin->curr_path.length < lemin->shortest_path.length)
	{
		while (i < lemin->num_rooms)
		{
			lemin->shortest_path.path[i] = lemin->curr_path.path[i];
			i++;
		}
		lemin->shortest_path.length = lemin->curr_path.length;
	}
}

void	matrix_find_path(t_lemin *lemin, int ind_of_pth, int key_index)
{
	int i;
	i = lemin->num_rooms;
	if (ind_of_pth > lemin->num_rooms)
	{
		ft_printf("Index of path out of range\n");
		exit(0);
	}
	lemin->curr_path.path[ind_of_pth] = key_index;
	if (key_index == lemin->num_rooms - 1) // at end room
		adjust_shortest_path(lemin);
	else
	{
		while (i > 0)
		{
			if (MATRIX[key_index][i] == 1 && not_visted(i, lemin->curr_path))
				matrix_find_path(lemin, ind_of_pth + 1, i);	
			i--;			
		}
	}
	lemin->curr_path.path[ind_of_pth] = -1;
}