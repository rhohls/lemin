/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pathing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhohls <rhohls@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/13 07:48:28 by rhohls            #+#    #+#             */
/*   Updated: 2018/08/29 08:56:28 by rhohls           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lemin.h"

/*
** Recursive function
** Branches and runs down each branch of node to find the end
** updates the shortest path to reflect this.
** Depth first for big room number, else breadth first search
*/

#include <unistd.h>

int		del_ret(t_pathend *self, int ret)
{
	delete_var(&self);
	return (ret);
}

int		path_to_end(t_pathend *self, t_stack *shortest_path, int stop)
{
	int res;

	if ((self->curr_path_list->length + 1) > (shortest_path->length))
	{
		delete_var(&self);
		return (0);
	}
	add_room_to_pathlist(self->room_name, self->curr_path_list);
	if (ft_strcmp(self->end, self->room_name) == 0)
	{
		update_shrtpth(self->curr_path_list, &shortest_path);
		delete_var(&self);
		return (1);
	}
	else
		res = run_new_branchs(self, shortest_path, stop);
	delete_var(&self);
	return (res);
}

int		run_new_branchs(t_pathend *self, t_stack *shortest_path, int stop)
{
	char	**room_con_list;
	t_stack	*ocupied_rooms;
	int		num_connections;
	int		i;
	int		res;

	i = 0;
	room_con_list = get_char_con_list(self->room_name, self->all_connections,
									&num_connections);
	ocupied_rooms = get_ocupied_rooms(self->turn_moves, self->turn_num);
	while (i < num_connections)
	{
		free(self->room_name);
		self->room_name = ft_strdup(room_con_list[i]);
		if (!is_occupied(room_con_list[i], ocupied_rooms) &&
				!(isinpath(room_con_list[i], self->curr_path_list)))
		{
			res = path_to_end(duplicate_var(self), shortest_path, stop);
			if (res && stop)
				return (1);
		}
		i++;
	}
	room_con_list = NULL;
	return (0);
}

void	find_path(t_lemin *lemin, t_ant *ant)
{
	t_stack		*shortest_path;
	t_pathend	*self;
	int			stop;

	self = init_self(lemin);
	shortest_path = init_shortest_path();
	stop = (lemin->room_list->length > 350) ? 1 : 0;
	while (shortest_path->start == NULL)
	{
		self->turn_num++;
		self->turn_start++;
		path_to_end(self, shortest_path, stop);
		break ;
	}
	ant->turn_num = self->turn_num;
	ft_stackrev(shortest_path);
	ant->path = shortest_path;
}
