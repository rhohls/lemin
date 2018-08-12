/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inits.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhohls <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/07 09:02:02 by rhohls            #+#    #+#             */
/*   Updated: 2018/08/07 09:02:27 by rhohls           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../includes/lemin.h"



t_pathend *duplicate_var(t_pathend *self)
{
	/* duplicate all the variables */
	t_pathend *new;
	new = self;
	new = NULL;

	return (new);
}

t_stack *ft_stackdup(t_stack *stack)
{
	return(stack);
}

char **gen_con_list(char *room_name, void *all_connections, int *num_con)
{
	/* make char ** list of all rooms connected to current room (room name) */
	char **ret;
	all_connections = room_name;
	ret = NULL;
	*num_con = 1;
	return (ret);
}

void add_room_to_pathlist(char *room_name, void *path_list)
{
	/* add the room to the path list */
	path_list = room_name;
}

void update_shrtpth(void *curr_path_list, t_stack *shortest_path)
{
	/* change shortest path to something else */
	shortest_path->start = curr_path_list;
}
