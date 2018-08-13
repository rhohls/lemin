/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inits.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhohls <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/13 07:48:07 by rhohls            #+#    #+#             */
/*   Updated: 2018/08/13 07:48:10 by rhohls           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lemin.h"

t_pathend	*init_self(t_lemin* lemin)
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

t_stack		*init_shortest_path(void)
{
	t_stack *shortest_path;

	shortest_path = ft_stacknew();
	shortest_path->length = INTMAX;
	return (shortest_path);
}

void		init_lemin(t_lemin *lemin)
{
	lemin->start = NULL;
	lemin->end = NULL;
	lemin->num_ants = 0;
	lemin->room_list = ft_stacknew();
	lemin->ant_list = ft_stacknew();
	lemin->turn_moves = ft_stacknew();
	lemin->connections = ft_stacknew();
}
