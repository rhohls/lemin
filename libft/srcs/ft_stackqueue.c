/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stackqueue.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhohls <rhohls@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/12 15:05:06 by rhohls            #+#    #+#             */
/*   Updated: 2018/09/08 10:46:39 by rhohls           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

// #include <stdio.h>
void	ft_stackqueue(t_stack *stack, t_list *new_node)
{
	t_list *temp;

	if (stack && new_node)
	{
		// printf("11\n");
		if (!(stack->start) || stack->length == 0)
			stack->start = new_node;
		else
		{
			// printf("22\n");
			temp = stack->start;
			while (temp->next)
				temp = temp->next;
			temp->next = new_node;
		}
		// printf("44\n");
		new_node->next = NULL;
		stack->length++;
		// printf("55\n");
	}
}
