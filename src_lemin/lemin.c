/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lemin.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhohls <rhohls@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/07 08:56:17 by rhohls            #+#    #+#             */
/*   Updated: 2018/09/08 13:41:28 by rhohls           ###   ########.fr       */
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

void	path_to_stack(t_lemin *lemin, t_path path, t_stack *path_stack)
{
	int i;
	t_list	*node;
	
	i = 1;
	while (i < path.length && path.path[i] != -1)
	{
		node = ft_lstnew(NULL, 0);
		// printf("path key: %d\n", path.path[i]);
		// printf("path room_name: %s\n", lemin->key[path.path[i]]);
		node->content = lemin->key[path.path[i]];
		ft_stackqueue(path_stack, node);
		i++;
	}	
}

void	print_path(t_path path)
{
	int i;
	
	i = 0;
	printf("Path with length:%d\n",path.length );
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
	// print_lemin(lemin);
	
	lemin->key = create_key(lemin);
	lemin->matrix = create_matrix(lemin);
	
	char	**key;
	int		**matrix;
	key = lemin->key;
	matrix = lemin->matrix;
	
	
	// int i = 0;
	// while (lemin->key[i])
	// {
	// 	printf("Key at %i is |%s|\n", i, lemin->key[i]);
	// 	i++;
	// }
	// printf("- %d\n", lemin->print_path);
	// if (lemin->print_path == 1)
	// 	printf("I am going to print adjutments\n");
	
	assign_matrix(lemin);
	
	// print_matrix(lemin);
	
	init_path(&(lemin->curr_path), lemin);
	init_path(&(lemin->shortest_path), lemin);
	lemin->shortest_path.length = INTMAX;
	
	// printf("init path\n");
	// print_path(lemin->curr_path);
	
	matrix_find_path(lemin, 0, 0);
	
	// printf("Shortest");
	// print_path(lemin->shortest_path);


	if (lemin->shortest_path.length == INTMAX || lemin->shortest_path.path[0] == -1)
	{
		ft_dprintf(1, "Error: No path found\n");
		exit(0);
	}
	t_stack	*stack_path;
	
	stack_path = ft_stacknew();
	
	path_to_stack(lemin, lemin->shortest_path, stack_path);
	// printf("path is stacked\n\n");
	// printf("path str stack:\n");
	// print_str_stack(stack_path);
	
	// printf("lemin queue adress is %p\n", lemin->ant_list);
		
	assign_path(lemin, stack_path);	
	node = lemin->map_feed;
	while (node)
	{
		ft_putendl(node->content);
		node = node->next;
	}
	ft_putchar('\n');
	
	print_ant_moves(lemin);
	// sleep(10);
	exit(0);
	return (1);
}
