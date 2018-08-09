/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inits.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhohls <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/07 09:02:02 by rhohls            #+#    #+#             */
/*   Updated: 2018/08/07 09:02:27 by rhohls           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../includes/lemin.h"



int ft_strinstack(char *str, t_stack *stack_x)
{
	t_list	*lst;
	
	lst = stack_x->start;
	while (lst)
	{
		if (ft_strcmp(str, (char *)(lst->content)) == 0)
			return (1);
		lst = lst->next;
	}
	return(0);
}

void delete_var(t_pathend *self)
{
	/* free all the variables */
	free(self);
}

t_pathend *duplicate_var(t_pathend *self)
{
	/* duplicate all the variables */
	t_pathend *new;
	new = self;
	new = NULL;

	return (new);
}

char **gen_con_list(char *room_name, void *all_connections)
{
	/* make char ** list of all rooms connected to current room (room name) */
	char **ret;
	all_connections = room_name;
	ret = NULL;
	return (ret);
}

void add_room_tolist(char *room_name, void *path_list)
{
	/* add the room to the path list */
	path_list = room_name;
}

void update_shrtpth(void *curr_path_list, t_stack *shortest_path)
{
	/* change shortest path to something else */
	shortest_path->start = curr_path_list;
}

int ft_strstrlen(char **strlist)
{
	int length;

	length = 0;
	return (length);
}

int is_occupied(char *room_name, void *turn_moves, int turn_num)
{
	/* check if room will be occupied on certain turn num */
	char moves;
	moves = ((char *)turn_moves)[turn_num];

	if (*room_name == moves)
		return (1);
	else
		return (0);
}

int isinpath(char *room_name, t_stack *rooms_visted)
{

	if ((char *)rooms_visted->start == room_name)
		return (1);
	return (0);
}

void make_new_branch(t_pathend *self, t_stack *shortest_path)
{
	char	**room_con_list;
	int i;
	i = 0;
	room_con_list = gen_con_list(self->room_name, self->all_connections);
	self->turn_num += 1;
	
	while (i < ft_strstrlen(room_con_list))
	{
		self->room_name = room_con_list[i];
		if (!is_occupied(room_con_list[i], self->turn_moves, self->turn_num) && 
			!(isinpath(room_con_list[i], self->curr_path_list)))
			path_to_end(duplicate_var(self), shortest_path);
		i++;
	}
	free (room_con_list);
}
/*
** Recuresive function
** Branches and runs down each branch to find the end
** updates the shortest path to reflect this.
*/

void path_to_end(t_pathend *self, t_stack *shortest_path)
{
	if (self->curr_path_list->length > shortest_path->length)
	{
		delete_var(self);
		return ;
	}

	add_room_tolist(self->room_name, self->curr_path_list);
	
	if (ft_strcmp(self->end, self->room_name) == 0)
		update_shrtpth(self->curr_path_list, shortest_path);
	else
		make_new_branch(self, shortest_path);
	delete_var(self);
}

void init_self(t_pathend *self)
{
	/*Assign stuff */
	self->end = NULL;
}

void find_path(void *turn_moves)
{
	t_stack shortest_path;
	t_pathend self;
	
	//init
	shortest_path.start = NULL;
	shortest_path.length = 0;
	init_self(&self);
	self.turn_moves = turn_moves;
	while(shortest_path.start == NULL)
	{
		path_to_end(&self, &shortest_path);
		self.turn_num++;
	}
}

/*

void play_game()
{
	for each ant
		ant->path = find_pathturn_moves
		add ant->path to turn_moves

	print all moves
}




void main()
{
	void	*data;

	data = capture_data();
	error_check_data(data); //exit inside also use stderr etc.
	play_game(data);
	return ;
}
*/