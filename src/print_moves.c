/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_moves.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhohls <rhohls@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/23 07:30:30 by rhohls            #+#    #+#             */
/*   Updated: 2018/08/30 10:05:59 by rhohls           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lemin.h"

void	print_moves(t_stack *moves, int num_ants)
{
	int		i;
	t_list	*node;

	if (!moves || !(moves->start) || !(moves->start->next))
		return ;
	i = 1;
	while (i <= num_ants)
	{
		node = moves->start->next;
		while (node)
		{
			ft_printf("L%i-%s\n", i, node->content);
			node = node->next;
		}
		i++;
	}
}
