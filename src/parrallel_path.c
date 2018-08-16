/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parrallel_path.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhohls <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/16 06:50:15 by rhohls            #+#    #+#             */
/*   Updated: 2018/08/16 06:50:20 by rhohls           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

	
#include "../includes/lemin.h"

t_stack	*get_all_paths(t_graphpath *cur_graph)
{
	return(NULL);
}

int		get_parrallel_path(t_graphpath *cur_graph, t_parallel *para, int recurse_num) //bool success
{
	int			res;
	t_stack		*list_graphpath;
	t_list		*node;
	t_graphpath *curr;

	if (recurse_num == para->max_parallel)
	{
		res = get_shortest_path(cur_graph); //update inside struct
		return (res); // 1 or 0
	}
	else
	{
		list_graphpath = get_all_paths(cur_graph);
		node = list_graphpath->start;
		while(node)
		{
			curr = node->content;
			res = get_parrallel_path(curr, para, recurse_num + 1);
			if (res == 1)
				return (1);
			node = node->next;
		}
		update_best();
	}
	return (0); //what if not short but updated in middle
}

int main()
{
	t_graphpath best;
	t_parallel	para;
	// best= malloc(sizeof(t_graphpath));
	para.max_parallel = 1;
	para.recurse_num = 1;
	best.graph = ft_stacknew();
	best.all_paths = ft_stacknew();

	get_parrallel_path(&best, &para, para.recurse_num);

}