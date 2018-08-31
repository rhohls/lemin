/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pathing_func.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhohls <rhohls@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/13 07:48:44 by rhohls            #+#    #+#             */
/*   Updated: 2018/08/31 14:20:40 by rhohls           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lemin.h"

char		**ft_stacktochar(t_stack *stack)
{
	int		i;
	char	**ret;
	t_list	*node;

	i = stack->length;
	ret = (char **)ft_memalloc(sizeof(char *) * (i + 1));
	node = stack->start;
	i--;
	while (i >= 0 && node)
	{
		ret[i] = (char *)node->content;
		i--;
		node = node->next;
	}
	return (ret);
}

char		**get_char_con_list(char *room_name,
								void *all_connections, int *num_con)
{
	t_con	*connection;
	char	**ret;
	
	printf("in pathing!! with room name %s\n", room_name);

	connection = find_con(all_connections, room_name);
	ret = connection->conections;
	*num_con = connection->num_connections;
	return (ret);
}

void		update_shrtpth(t_stack *curr_path_list, t_stack **shortest_path)
{
	t_stack *new;

	if (curr_path_list->length < (*shortest_path)->length)
	{
		ft_lstdel(&((*shortest_path)->start), delete);
		new = ft_stackdup(curr_path_list);
		(*shortest_path)->start = new->start;
		(*shortest_path)->length = new->length;
		free(new);
	}
}

t_stack		*get_ocupied_rooms(t_stack *turn_moves, int turn_num)
{
	int		i;
	t_list	*node;

	i = 0;
	node = turn_moves->start;
	while (i < turn_num && node)
		node = node->next;
	return ((t_stack *)node);
}

void		add_room_to_pathlist(char *room_name, t_stack *path_list)
{
	t_list	*node;

	node = ft_lstnew(room_name, ft_strlen(room_name));
	ft_stackpush(path_list, node);
}
