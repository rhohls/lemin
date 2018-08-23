/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_functions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhohls <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/14 08:01:35 by rhohls            #+#    #+#             */
/*   Updated: 2018/08/14 08:01:40 by rhohls           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../includes/lemin.h"

t_list	*ft_lstdup(t_list *node)
{
	t_list	*new;

	if (!(new = (t_list *)malloc(sizeof(t_list))))
		return (NULL);
	if (!(new->content = malloc(sizeof(node->content_size))))
	{
		free(new);
		return (NULL);
	}
	ft_memcpy(new->content, node->content, node->content_size);
	new->content_size = node->content_size;
	new->next = NULL;
	return (new);
}

t_stack		*ft_stackdup(t_stack *stack)
{
	t_stack *new;
	t_list	*node;
	t_list	*node_new;

	new = ft_stacknew();
	node = stack->start;
	while(node)
	{
		node_new = ft_lstdup(node);
		ft_stackqueue(new, node_new);
		node = node->next;
	}
	return(new);
}

void		delete(void *content, size_t size)
{
	printf("deleting %s", content);
	if (size > 0)
	{
		free (content);
	}
}

void		ft_stackdel(t_stack **stack)
{
	// printf("!!!! NOT CODED YET !!!!\n");
	ft_lstdel(&((*stack)->start), delete);
	printf("12\n");
	free(*stack);
	*stack = NULL;
}

void		ft_stackrev(t_stack *stack)
{
	t_stack	*new;
	t_list	*node;
	int		i;

	i = stack->length;
	if (!stack || !(stack->start))
		return;
	new = ft_stacknew();
	node = stack->start;
	while (i > 0 && node)
	{
		node = ft_stackpop(stack);
		ft_stackpush(new, node);
		i--;
	}
	stack->start = new->start;
	stack->length = new->length;
	free(new);
}
