/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_test.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhohls <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/14 09:38:40 by rhohls            #+#    #+#             */
/*   Updated: 2018/08/14 09:38:44 by rhohls           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "./includes/lemin.h"

int main()
{
	t_list *node;
	t_stack *stack = ft_stacknew();
	char *str = ft_memalloc((sizeof(char) * 50));

	str = "test1\0";
	node = ft_lstnew(str, ft_strlen(str));
	ft_stackpush(stack, node);

	str = "2nd str\0\0";
	node = ft_lstnew(str, ft_strlen(str));
	ft_stackpush(stack, node);

	str = "best string\0";
	node = ft_lstnew(str, ft_strlen(str));
	ft_stackpush(stack, node);

	str = "12345\0";
	node = ft_lstnew(str, ft_strlen(str));
	ft_stackpush(stack, node);

	str = "Hellow\0";
	node = ft_lstnew(str, ft_strlen(str));
	ft_stackpush(stack, node);

	str = "World\0";
	node = ft_lstnew(str, ft_strlen(str));
	ft_stackpush(stack, node);

	printf("stack1: %p\n", stack);
	print_str_stack(stack);

	
	t_stack *stack2;
	stack2 = ft_stackdup(stack);
	printf("\nstack2: %p\n", stack2);
	print_str_stack(stack2);	


	return (1);


}