/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inits.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhohls <rhohls@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/13 07:48:07 by rhohls            #+#    #+#             */
/*   Updated: 2018/08/30 07:18:28 by rhohls           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lemin.h"

void		init_ant(t_ant *ant)
{
	ant->number = 1;
	ant->turn_num = 0;
	ant->path = NULL;
}

t_pathend	*init_self(t_lemin *lemin)
{
	t_pathend *self;

	self = (t_pathend *)malloc(sizeof(t_pathend));
	self->end = lemin->end;
	self->room_name = ft_strdup(lemin->start);
	self->all_connections = lemin->connections;
	self->turn_moves = lemin->turn_moves;
	self->turn_start = -1;
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

t_lemin		*init_lemin(void)
{
	t_lemin *lemin;

	lemin = (t_lemin *)malloc(sizeof(t_lemin));
	lemin->start = NULL;
	lemin->end = NULL;
	lemin->num_ants = 0;
	lemin->map_feed = NULL;
	lemin->room_list = ft_stacknew();
	lemin->ant_list = ft_stacknew();
	lemin->turn_moves = ft_stacknew();
	lemin->connections = ft_stacknew();
	return (lemin);
}
