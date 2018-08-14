/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_free.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhohls <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/13 07:47:46 by rhohls            #+#    #+#             */
/*   Updated: 2018/08/13 07:47:48 by rhohls           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lemin.h"
/*
typedef struct	s_pathend
{
	char		*end;
	t_stack		*all_connections; //stack pointing to t_con
	t_stack		*turn_moves; //see above
	int			turn_start;
	 ^-const   v-delta 
	t_stack		*curr_path_list; 	
	char		*room_name;
	int			turn_num;
}				t_pathend;
*/

t_pathend	*duplicate_var(t_pathend *self)
{
	/* duplicate all the variables */
	t_pathend *new;

	new = (t_pathend *)malloc(sizeof(t_pathend));
	new->end = self->end;
	new->all_connections = self->all_connections;
	new->turn_moves = self->turn_moves;
	new->turn_start = self->turn_start;

	new->curr_path_list = ft_stackdup(self->curr_path_list);
	new->room_name = ft_strdup(self->room_name);

	return (new);
}

void    delete_var(t_pathend *self)
{
	/* free only the following variables */

	free(self->room_name);
	ft_stackdel(self->curr_path_list);
	free(self);
	self = NULL;
}

void    ft_del_chararr(char **array, int amt)
{
	int i;

	i = 0;
	if (!array)
		return ;
	while (i < amt)
	{
		if (array[i])
			free(array[i]);
		i++;
	}
	free(array);
	array = NULL;
}