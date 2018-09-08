/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_path.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhohls <rhohls@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/07 11:43:28 by rhohls            #+#    #+#             */
/*   Updated: 2018/09/08 14:21:45 by rhohls           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lemin.h"

int			not_visted(int key_index, t_path path)
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

void		adjust_shortest_path(t_lemin *lemin)
{
	int i;

	i = 0;
	if (lemin->curr_path.length < lemin->shortest_path.length)
	{
		if (lemin->print_path)
		{
			ft_printf("Adjusting path, new length: %d\n",
			lemin->curr_path.length);
		}
		while (i < lemin->num_rooms)
		{
			lemin->shortest_path.path[i] = lemin->curr_path.path[i];
			i++;
		}
		lemin->shortest_path.length = lemin->curr_path.length;
	}
}

static void	exit_str(char *str)
{
	ft_putstr(str);
	exit(0);
}

void		matrix_find_path(t_lemin *lemin, int ind_of_pth, int key_index)
{
	int i;

	i = lemin->num_rooms - 1;
	if (ind_of_pth > lemin->num_rooms)
		exit_str("Index of path out of range\n");
	lemin->curr_path.path[ind_of_pth] = key_index;
	lemin->curr_path.length++;
	if (lemin->curr_path.length < lemin->shortest_path.length)
	{
		if (key_index == lemin->num_rooms - 1)
			adjust_shortest_path(lemin);
		else
		{
			while (i > 0)
			{
				if (MATRIX[key_index][i] == 1 &&
						not_visted(i, lemin->curr_path))
					matrix_find_path(lemin, ind_of_pth + 1, i);
				i--;
			}
		}
	}
	lemin->curr_path.path[ind_of_pth] = -1;
	lemin->curr_path.length--;
}
