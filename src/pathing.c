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
** Recursive function
** Branches and runs down each branch to find the end
** updates the shortest path to reflect this.
*/

#include <unistd.h>
void path_to_end(t_pathend *self, t_stack *shortest_path)
{
	dprintf(2, "now in roomname: %s\n",  self->room_name);
	// char *line;
	// get_next_line(0, &line);
	// if (line)
	// 	free(line);
	// sleep(5);
	// dprintf(2, "- address: %p\n", self);
	// dprintf(2, "rooms that have been visited at address \n");
	// print_str_stack(self->curr_path_list);
	// dprintf(2, "\tdone\n");
	if ((self->curr_path_list->length + 1) > (shortest_path->length))
	{
		printf("Path too long leaving \n");
		delete_var(self);
		return ;
	}
	// printf("adding room\n");
	add_room_to_pathlist(self->room_name, self->curr_path_list);
	
	// dprintf(2, "added room to list, curr rooms:\n");
	// print_str_stack(self->curr_path_list);
	// dprintf(2, "\tdone\n\n");
	// dprintf(2, "point - 2\n");
	// printf("checking end\n");
	if (ft_strcmp(self->end, self->room_name) == 0)
	{
		// printf("at end room\n");
		update_shrtpth(self->curr_path_list, &shortest_path);
	}
	else
	{
		printf("not end running new braches\n");
		run_new_branchs(self, shortest_path);
	}
	// dprintf(2, "at end of path to end for [%s]\n", self->room_name);
	// printf("in pte path shortest path adress - %p\n", shortest_path);
	// printf("in pte path shortest path start adress - %p\n", (shortest_path)->start);
	delete_var(self);
}

void run_new_branchs(t_pathend *self, t_stack *shortest_path)
{
	char	**room_con_list;
	t_stack	*ocupied_rooms;
	int 	num_connections;
	int 	i;
	i=0;

	// printf("getting char con list\n");
	room_con_list = get_char_con_list(self->room_name, self->all_connections,
									&num_connections);
	// printf("getiing ocupied\n");
	ocupied_rooms = get_ocupied_rooms(self->turn_moves, self->turn_num);
	self->turn_num += 1;
	// printf("num of connections: %i\n", num_connections);
	// printf("first in conn |%s|", room_con_list[0]);
	// printf("here\n");
	
	// printf("\n");
	while (i < num_connections)
	{
		// printf("in while loop shortest path adress - %p\n", shortest_path);
		// printf("in while loop shortest path start adress - %p\n", (shortest_path)->start);		
		// printf("i: %i  - roomname %s \n", i, room_con_list[i]);
		self->room_name = room_con_list[i];
		if (!is_occupied(room_con_list[i], ocupied_rooms) && 
			!(isinpath(room_con_list[i], self->curr_path_list)))
			path_to_end(duplicate_var(self), shortest_path);
		i++;
	}
	// free(room_con_list);
	room_con_list = NULL;
}

void find_path(t_lemin* lemin, t_ant *ant)
{
	t_stack *shortest_path;
	t_pathend *self;

	self = init_self(lemin);
	shortest_path = init_shortest_path();
	// change so that if path == null - no path and then erro exit
	while(shortest_path->start == NULL)
	{
		self->turn_num++;
		self->turn_start++;
		path_to_end(self, shortest_path);
		printf("\n printf ---- shorteset path --- %p\n", shortest_path->start);
		print_str_stack(shortest_path);
		// printf("\n\n!!!!!!\tStep in while loop\t!!!!!!!!\n\n");
		break ;
	}
	// delete_var(self);
	ant->turn_start = self->turn_start;
	ft_stackrev(shortest_path);
	ant->path = shortest_path;


	// return(shortest_path);
}

