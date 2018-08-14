/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pathing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhohls <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/13 07:48:28 by rhohls            #+#    #+#             */
/*   Updated: 2018/08/13 07:48:30 by rhohls           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lemin.h"

/*
** Recuresive function
** Branches and runs down each branch to find the end
** updates the shortest path to reflect this.
*/

void path_to_end(t_pathend *self, t_stack *shortest_path)
{
	if ((self->curr_path_list->length + 1) > (shortest_path->length))
	{
		delete_var(self);
		return ;
	}
	ft_stackpush(self->curr_path_list, 
				ft_lstnew(self->room_name, ft_strlen(self->room_name)));
	// add_room_to_pathlist(self->room_name, self->curr_path_list);

	if (ft_strcmp(self->end, self->room_name) == 0)
		update_shrtpth(self->curr_path_list, shortest_path);
	else
		run_new_branchs(self, shortest_path);
	delete_var(self);
}

void run_new_branchs(t_pathend *self, t_stack *shortest_path)
{
	char	**room_con_list;
	t_stack	*ocupied_rooms; // t_stack?
	int 	num_connections;
	int 	i;
	i=0;

	room_con_list = get_char_con_list(self->room_name, self->all_connections,
									&num_connections);
	ocupied_rooms = get_ocupied_rooms(self->turn_moves, self->turn_num);
	self->turn_num += 1;
	
	while (i < num_connections)
	{
		self->room_name = room_con_list[i];
		if (!is_occupied(room_con_list[i], ocupied_rooms) && 
			!(isinpath(room_con_list[i], self->curr_path_list)))
			path_to_end(duplicate_var(self), shortest_path);
		i++;
	}
	free(room_con_list);
}

void find_path(t_lemin* lemin, t_ant *ant)
{
	t_stack *shortest_path;
	t_pathend *self;
	
	self = init_self(lemin);
	shortest_path = init_shortest_path();
	while(shortest_path->start == NULL)
	{
		self->turn_num++;
		self->turn_start++;
		path_to_end(self, shortest_path);
	}
	delete_var(self);
	ant->turn_start = self->turn_start;
	ant->path = shortest_path;
	// return(shortest_path);
}

