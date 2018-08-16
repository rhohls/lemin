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

int get_shortest_path(t_graphpath *cur_graph)
{
	/* if there is a path change cur_graph to reflect */
	return(0);
}

void update_best(t_graphpath *cur_graph, t_parallel *para)
{
	t_graphpath *dup;

	/* delete the old one */
	dup = (t_graphpath *)malloc(sizeof(t_graphpath));
	dup->graph = ft_stackdup(cur_graph->graph);
	dup->graph = ft_stackdup(cur_graph->graph);

	para->best = dup; 
}

int		get_parrallel_path(t_graphpath *cur_graph, t_parallel *para, int recurse_num) //bool success
{
	int			res;
	t_stack		*list_graphpath;
	t_list		*node;
	t_graphpath *curr;

	if (recurse_num == para->max_parallel)
	{
		res = get_shortest_path(cur_graph); //update cur_graph inside function
		if (res)
		{
			update_best(cur_graph, para);
			return (1);
		}
		return (0); 
	}
	else
	{
		list_graphpath = get_all_paths(cur_graph); //have results ordered
		// ft_stackorder(list_graphpath);
		node = list_graphpath->start;
		while(node)
		{
			curr = node->content;
			res = get_parrallel_path(curr, para, recurse_num + 1);
			if (res == 1)
				return (1);
			node = node->next;
		}
		update_best(cur_graph, para);
	}
	return (0); //what if not short but updated in middle
}

int main()
{
	t_graphpath *initial;
	t_parallel	para;
	t_stack		*allpaths;
	// best= malloc(sizeof(t_graphpath));
	para.max_parallel = 1;
	para.recurse_num = 1;

	initial = (t_graphpath *)malloc(sizeof(t_graphpath));
	initial->graph = ft_stacknew();
	initial->all_paths = ft_stacknew();

	get_parrallel_path(initial, &para, para.recurse_num);

}

// max paths to enter
// max paths to leave
