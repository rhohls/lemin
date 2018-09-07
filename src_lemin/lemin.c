/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lemin.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhohls <rhohls@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/07 08:56:17 by rhohls            #+#    #+#             */
/*   Updated: 2018/09/07 14:31:35 by rhohls           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lemin.h"
#include <unistd.h>

void		post_data_collect(t_lemin *lemin)
{
	if (lemin->start == NULL)
		ft_putstr("Error: missing start room\n");
	else if (lemin->end == NULL)
		ft_putstr("Error: missing end room\n");
	else
		return ;
	exit(0);
}

static void	free_node(t_list **node)
{
	if (node && *node)
	{
		if ((*node)->content)
			free((*node)->content);
		free(*node);
		*node = NULL;
	}
}

void		print_matrix(t_lemin *lemin)
{
	int x=0;
	int y=0;
	
	while (x < lemin->room_list->length)
	{
		y = 0;
		printf("[");
		while (y < lemin->room_list->length)
		{
			if (y == lemin->room_list->length - 1)
				printf("%d", MATRIX[x][y]);
			else
				printf("%d, ", MATRIX[x][y]);
			
			y++;
		}
		printf("]\n");
		x++;
	}	
}

void	init_path(t_path *path, t_lemin *lemin)
{
	int i;
	
	path->length = 0;
	path->path = malloc(sizeof(int) * lemin->num_rooms);
	i = 0;
	while (i < lemin->num_rooms)
	{
		path->path[i] = -1;
		i++;
	}
}

void	print_path(t_path path)
{
	int i;
	
	i = 0;
	printf("Path:\n");
	while (i < path.length)
	{ 
		ft_printf("%d ", path.path[i]);
		i++;
	}
	printf("\n");
}

int			main(void)
{
	t_ant	ant;
	t_lemin *lemin;
	t_list	*node;

	lemin = capture_data(0);
	post_data_collect(lemin);
	print_lemin(lemin);
	
	lemin->key = create_key(lemin);
	lemin->matrix = create_matrix(lemin);
	
	char	**key;
	int		**matrix;
	key = lemin->key;
	matrix = lemin->matrix;
	
	
	int i = 0;
	while (key[i])
	{
		printf("Key at %i is |%s|\n", i, key[i]);
		i++;
	}

	
	assign_matrix(lemin);
	print_matrix(lemin);
	
	init_path(&(lemin->curr_path), lemin);
	init_path(&(lemin->shortest_path), lemin);
	printf("init path\n");
	print_path(lemin->curr_path);
	
	matrix_find_path(lemin, 0, 0);
	
	printf("Shortest");
	print_path(lemin->shortest_path);
	
	// init_ant(&ant);
	// find_path(lemin, &ant);
	// if (ant.path == NULL || ant.path->start == NULL)
	// {
	// 	ft_dprintf(1, "Error: No path found\n");
	// 	exit(0);
	// }
	// node = ft_stackpop(ant.path);
	// free_node(&node);
	// assign_path(lemin, ant.path);
	// node = lemin->map_feed;
	// while (node)
	// {
	// 	ft_putendl(node->content);
	// 	node = node->next;
	// }
	// ft_putchar('\n');
	// print_ant_moves(lemin);
	return (1);
}
