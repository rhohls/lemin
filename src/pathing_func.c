/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pathing_func.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhohls <rhohls@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/13 07:48:44 by rhohls            #+#    #+#             */
/*   Updated: 2018/08/28 09:59:41 by rhohls           ###   ########.fr       */
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

char		**get_char_con_list(char *room_name, void *all_connections, int *num_con)
{
	/* make char ** list of all rooms connected to current room (room name) */
	t_con	*connection;
	char	**ret;

	// printf("getting connection\n");
	connection = find_con(all_connections, room_name);
	// printf("got con\n");
	ret = connection->conections;
	// printf("ret address %p \n", ret);
	// printf("string is 0 |%s|\n", ret[0]);
	*num_con = connection->num_connections;
		
	return (ret);
}

void		update_shrtpth(t_stack *curr_path_list, t_stack **shortest_path)
{
	/* change shortest path to something else */
	t_stack *new;
	if (curr_path_list->length < (*shortest_path)->length)
	{
		// printf("old shortest path start adress - %p\n", (*shortest_path)->start);
		// printf("\n\x1B[1;32m\t\t!!making new shortest path here!! Old path length %zu and rooms:\033[0m\n", (*shortest_path)->length);
		// print_str_stack(*shortest_path);
		// printf("\tdone\n");
		// ft_stackdel(shortest_path);
		ft_lstdel(&((*shortest_path)->start), delete);
		// printf("deleted path\n");
		new = ft_stackdup(curr_path_list);
	
		(*shortest_path)->start = new->start;
		(*shortest_path)->length = new->length;
		free(new);
		// printf("new shortest path adress - %p\n", shortest_path);
		// printf("new shortest path start adress - %p\n", (*shortest_path)->start);
	}
}

t_stack		*get_ocupied_rooms(t_stack *turn_moves, int turn_num)
{
	/* return t_list (stack?)  */
	int i;
	// t_stack *ret;
	t_list	*node;

	i = 0;
	node = turn_moves->start;
	while (i < turn_num && node)
		node = node->next;

	return((t_stack *)node);
}

void		add_room_to_pathlist(char *room_name, t_stack *path_list)
{
	t_list	*node;

	node = ft_lstnew(room_name, ft_strlen(room_name));
	ft_stackpush(path_list, node);
}

