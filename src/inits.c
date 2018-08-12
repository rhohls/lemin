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

t_pathend *init_self(t_lemin* lemin)
{
	// pass variable to assign start, end etc
	t_pathend *self;

	self = (t_pathend *)malloc(sizeof(t_pathend));
	self->end = lemin->end;
	self->all_connections = lemin->connections;
	self->turn_moves = lemin->turn_moves;
	self->turn_start = -1;
	self->room_name = NULL;
	self->curr_path_list = ft_stacknew();
	self->turn_num = -1;

	return (self);
}

t_stack *init_shortest_path(void)
{
	t_stack *shortest_path;

	shortest_path = ft_stacknew();
	shortest_path->length = INTMAX;
}

