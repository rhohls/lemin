/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turn_moves.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhohls <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/13 07:48:57 by rhohls            #+#    #+#             */
/*   Updated: 2018/08/13 07:49:00 by rhohls           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lemin.h"
#define  TURN_NUM content_size

void	add_turns(t_lemin *lemin, t_ant *ant)
{
	t_stack	*turn;
	t_list	*node;

	while ((ant->turn_start + ant->path->length - 2) >
			lemin->turn_moves->length)
	{
		node = ft_lstnew(NULL, 0);
		turn = ft_stacknew();
		node->content = turn;
		ft_stackqueue(lemin->turn_moves, node);
		node->TURN_NUM = lemin->turn_moves->length - 1;
	}
}

void	update_turn_moves(t_lemin *lemin, t_ant *ant)
{
	t_list	*turn;
	t_list	*moves;
	t_list	*node;
	int		i;

	add_turns(lemin, ant);

	turn = lemin->turn_moves->start;
	while (turn && (int)(turn->TURN_NUM) != ant->turn_start)
		turn = turn->next;

	t_list *ant_move;
	ant_move = ant->path->start;

	while (ant_move)
	{
		moves = NULL;
		break;
	}
}