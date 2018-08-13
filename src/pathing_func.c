/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pathing_func.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhohls <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/13 07:48:44 by rhohls            #+#    #+#             */
/*   Updated: 2018/08/13 07:48:48 by rhohls           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lemin.h"

t_pathend	*duplicate_var(t_pathend *self)
{
	/* duplicate all the variables */
	printf("!!!! NOT CODED YET !!!!");
	t_pathend *new;
	new = self;
	new = NULL;

	return (new);
}

t_stack		*ft_stackdup(t_stack *stack)
{
	printf("!!!! NOT CODED YET !!!!");
	return(stack);
}

char		**gen_con_list(char *room_name, void *all_connections, int *num_con)
{
	/* make char ** list of all rooms connected to current room (room name) */
	printf("!!!! NOT CODED YET !!!!");
	char **ret;
	all_connections = room_name;
	ret = NULL;
	*num_con = 1;
	return (ret);
}

void		add_room_to_pathlist(char *room_name, void *path_list)
{
	/* add the room to the path list */
	printf("!!!! NOT CODED YET !!!!");
	path_list = room_name;
}

void		update_shrtpth(void *curr_path_list, t_stack *shortest_path)
{
	/* change shortest path to something else */
	printf("!!!! NOT CODED YET !!!!");
	shortest_path->start = curr_path_list;
}

void		*get_ocupied_rooms(t_stack *turn_moves, int turn_num)
{
	/* prob make return t_stack else can make char**(harder) */
	turn_num++;
	printf("!!!! NOT CODED YET !!!!");
	return((void *)turn_moves);
}
