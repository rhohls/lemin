/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_delfunctions.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhohls <rhohls@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/14 08:01:35 by rhohls            #+#    #+#             */
/*   Updated: 2018/09/08 14:26:13 by rhohls           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lemin.h"

void		delete(void *content, size_t size)
{
	if (size > 0)
	{
		free(content);
	}
}

void		ft_stackdel(t_stack **stack)
{
	if (stack && *stack)
	{
		ft_lstdel(&((*stack)->start), delete);
		free(*stack);
		*stack = NULL;
	}
}

void		ft_del_onlylist(t_list **alst)
{
	if (alst && *alst)
	{
		if ((*alst)->next != NULL)
			ft_del_onlylist(&((*alst)->next));
		free(*alst);
	}
}

void		ft_del_onlystack(t_stack **stack)
{
	if (stack && *stack)
	{
		ft_del_onlylist(&((*stack)->start));
		free(*stack);
		*stack = NULL;
	}
}
