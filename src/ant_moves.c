/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ant_moves.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhohls <rhohls@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/27 07:05:11 by rhohls            #+#    #+#             */
/*   Updated: 2018/09/08 10:55:26 by rhohls           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lemin.h"
#define A_PTH ant->path
#define A_TRN_NUM ant->turn_num

t_list	*make_ant(int ant_num, t_stack *path, int turn_start)
{
	t_ant	*ret_ant;
	t_list	*ret;

	ret_ant = malloc(sizeof(t_ant));
	ret_ant->number = ant_num;
	ret_ant->path = path;
	ret_ant->turn_num = turn_start;
	ret = ft_lstnew(NULL, 0);
	ret->content = ret_ant;
	return (ret);
}

/*
** Change to accept and assign multiple paths
** nested while for each path given
*/

void	assign_path(t_lemin *lemin, t_stack *path)
{
	int		i;
	t_list	*ant_node;

	i = 1;
	// printf("number of ants is: %d\n", lemin->num_ants);
	// printf("lemin queue adress is %p\n", lemin->ant_list);
	while (i <= lemin->num_ants)
	{
		// printf("making ant number %d\n", i);
		ant_node = make_ant(i, path, 1 - i);
		// printf("ant node made %p\n", ant_node);
		ft_stackqueue(lemin->ant_list, ant_node);
		// printf("ant node queued \n");
		i++;
	}
}

char	*room_name(t_stack *path, int index)
{
	int		i;
	t_list	*node;

	node = path->start;
	i = 0;
	while (i < index)
	{
		node = node->next;
		if (node == NULL)
		{
			ft_putstr("Error with printing an ant path\n");
			exit(0);
		}
		i++;
	}
	return (node->content);
}

void	print_ant_moves(t_lemin *lemin)
{
	int		i;
	int		print;
	t_list	*ant_node;
	t_ant	*ant;
	
	// printf("0\n");
	while (1)
	{
		ant_node = lemin->ant_list->start;
		print = 0;
		i = 0;
		// printf("1\n");
		while (ant_node)
		{
			// printf("2\n");
			ant = ant_node->content;
			// printf("3\n");
			// printf
			
			if (ant->turn_num >= 0 && ant->turn_num < (int)(ant->path->length))
			{
				ft_printf("L%i-%s ", ant->number, room_name(A_PTH, A_TRN_NUM));
				print = 1;
			}
			ant->turn_num++;
			ant_node = ant_node->next;
		}
		if (print == 0)
			break ;
		ft_putchar('\n');
	}
}
