/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_free.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhohls <rhohls@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/13 07:47:46 by rhohls            #+#    #+#             */
/*   Updated: 2018/09/05 16:16:26 by rhohls           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lemin.h"

t_pathend	*duplicate_var(t_pathend *self)
{
	t_pathend *new;
	
	printf("in duplicate with roomname %s  @ %p\n", self->room_name, self->room_name);

	new = (t_pathend *)ft_memalloc(sizeof(t_pathend));
	new->end = self->end;
	new->all_connections = self->all_connections;
	new->turn_moves = self->turn_moves;
	new->turn_start = self->turn_start;
	printf("in duplicate with roomname %s  @ %p\n", self->room_name, self->room_name);
	new->curr_path_list = ft_stackdup(self->curr_path_list);
	printf("dup roomname %s  @ %p\n", self->room_name, self->room_name);
	new->room_name = ft_strdup(self->room_name);
	printf("new %s and self %s  @ %p", new->room_name, self->room_name, self->room_name);
	new->turn_num = self->turn_num + 1;
	return (new);
}

void		delete_var(t_pathend **self)
{
	// free((*self)->room_name);
	// ft_del_onlystack(&((*self)->curr_path_list));
	// free(*self);
	// *self = NULL;
	void *a;
	a = *self;
}

void		ft_del_chararr(char **array, int amt)
{
	int i;

	i = 0;
	if (!array)
		return ;
	while (i < amt)
	{
		if (array[i])
		{
			free(array[i]);
			array[i] = NULL;
		}
		i++;
	}
	free(array);
	array = NULL;
}
