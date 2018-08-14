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
	// printf("Copying |%s| with length : %lu",node->content, node->content_size);
	ft_memcpy(new->content, node->content, node->content_size);
	new->content_size = node->content_size;
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
		// printf("node str |%s|\n", node->content);
		node_new = ft_lstdup(node);
		// printf("new node str |%s|\n", node_new->content);
		ft_stackqueue(new, node_new);
		node = node->next;
	}
	// printf("duplicated the stack:\n");
	// print_str_stack(stack);
	// printf("The duplicate stack:\n");
	// print_str_stack(new);	
	return(new);
}

void		ft_stackdel(t_stack *stack)
{
	//printf("!!!! NOT CODED YET !!!!\n");
	stack = NULL;
}

