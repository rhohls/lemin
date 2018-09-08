/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_to_matrix.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhohls <rhohls@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/07 09:55:12 by rhohls            #+#    #+#             */
/*   Updated: 2018/09/08 14:06:03 by rhohls           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lemin.h"

char	**create_key(t_lemin *lemin)
{
	char	**key;
	t_list	*node;
	int		i;
	char	*room_name;

	key = (char **)ft_memalloc((lemin->room_list->length + 1) * sizeof(char *));
	key[lemin->room_list->length] = NULL;
	key[0] = lemin->start;
	key[lemin->room_list->length - 1] = lemin->end;
	i = 1;
	node = lemin->room_list->start;
	while (node)
	{
		room_name = node->content;
		if (!(ft_strcmp(room_name, lemin->start) == 0 ||
			ft_strcmp(room_name, lemin->end) == 0))
		{
			key[i] = room_name;
			i++;
		}
		node = node->next;
	}
	return (key);
}

int		**create_matrix(t_lemin *lemin)
{
	int	**matrix;
	int i;

	i = 0;
	matrix = (int **)malloc((lemin->room_list->length) * sizeof(int *));
	while (i < lemin->room_list->length)
	{
		matrix[i] = ft_memalloc((lemin->room_list->length) * sizeof(int));
		i++;
	}
	return (matrix);
}

int		key_ind(char **key, char *room_name)
{
	int i;

	i = 0;
	while (key[i])
	{
		if (ft_strcmp(key[i], room_name) == 0)
			return (i);
		i++;
	}
	ft_printf("Error making matrix, no room %s found\n", room_name);
	exit(0);
}

void	adjust_matrix_line(int *line, char *line_roomname, t_lemin *lemin)
{
	char	**room_con_list;
	int		num_connections;
	int		i;

	room_con_list = get_char_con_list(line_roomname, lemin->connections,
									&num_connections);
	i = 1;
	while (i < lemin->num_rooms)
	{
		line[i] = ft_strinlist(KEY[i], room_con_list, num_connections);
		i++;
	}
}

void	assign_matrix(t_lemin *lemin)
{
	int x;
	int y;

	x = 0;
	while (x < lemin->num_rooms)
	{
		adjust_matrix_line(MATRIX[x], KEY[x], lemin);
		x++;
	}
}
