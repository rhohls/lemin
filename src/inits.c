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



t_pathend *duplicate_var(t_pathend *self)
{
	/* duplicate all the variables */
	t_pathend *new;
	new = self;
	new = NULL;

	return (new);
}

t_stack *ft_stackdup(t_stack *stack)
{
	return(stack);
}

char **gen_con_list(char *room_name, void *all_connections, int *num_con)
{
	/* make char ** list of all rooms connected to current room (room name) */
	char **ret;
	all_connections = room_name;
	ret = NULL;
	*num_con = 1;
	return (ret);
}

void add_room_to_pathlist(char *room_name, void *path_list)
{
	/* add the room to the path list */
	path_list = room_name;
}

void update_shrtpth(void *curr_path_list, t_stack *shortest_path)
{
	/* change shortest path to something else */
	shortest_path->start = curr_path_list;
}

int is_occupied(char *room_name, char **ocupied_rooms)
{
	/* check if room will be occupied on certain turn num */


	if (ft_strcmp(room_name, ocupied_rooms[0]) == 0)
		return (1);
	else
		return (0);
}

int isinpath(char *room_name, t_stack *rooms_visted)
{

	if (ft_strinstack(room_name, rooms_visted) == 1)
		return (1);
	return (0);
}

/*
** Recuresive function
** Branches and runs down each branch to find the end
** updates the shortest path to reflect this.
*/

void path_to_end(t_pathend *self, t_stack *shortest_path)
{
	if ((self->curr_path_list->length + 1) > (shortest_path->length))
	{
		delete_var(self);
		return ;
	}
	add_room_to_pathlist(self->room_name, self->curr_path_list);

	if (ft_strcmp(self->end, self->room_name) == 0)
		update_shrtpth(self->curr_path_list, shortest_path);
	else
		run_new_branchs(self, shortest_path);
	delete_var(self);
}
void run_new_branchs(t_pathend *self, t_stack *shortest_path)
{
	char	**room_con_list;
	char	**ocupied_rooms;
	int 	num_connections;
	int 	i;
	i=0;

	room_con_list = gen_con_list(self->room_name, self->all_connections,
									&num_connections);
	ocupied_rooms = get_ocupied_rooms(self->turn_moves, self->turn_num);
	self->turn_num += 1;
	
	while (i < num_connections)
	{
		self->room_name = room_con_list[i];
		if (!is_occupied(room_con_list[i], ocupied_rooms) && 
			!(isinpath(room_con_list[i], self->curr_path_list)))
			path_to_end(duplicate_var(self), shortest_path);
		i++;
	}
	free (room_con_list);
}

t_pathend *init_self(t_lemin* lemin)
{
	// pass variable to assign start, end etc
	t_pathend *self;

	self = (t_pathend *)malloc(sizeof(t_pathend));
	self->end = lemin->end;
	self->all_connections = lemin->connections;
	self->turn_moves = lemin->turn_moves;
	self->turn_start = -1;
	self->room_name = NULL;
	self->curr_path_list = ft_stacknew;
	self->turn_num = -1;

	return (self);
}

t_stack *init_shortest_path(void)
{
	t_stack *shortest_path;

	shortest_path = ft_stacknew;
	shortest_path->length = INTMAX;
}

t_stack *find_path(t_lemin* lemin)
{
	t_stack *shortest_path;
	t_pathend *self;
	
	self = init_self(lemin);
	shortest_path = init_shortest_path();
	while(shortest_path->start == NULL)
	{
		self->turn_num++;
		self->turn_start++;
		path_to_end(self, shortest_path);
	}
	delete_var(self);
	return(shortest_path);
}


void play_game(t_lemin* lemin)
{
	int		i;
	t_ant	*ant;
	i = 0;

	while (i < lemin->num_ants)
	{
		ant = get_ant(lemin, i);
		ant->path = find_path(lemin);
		update_moves(ant->path);
		i++;
	}
}

void print_all_moves(t_lemin* lemin)
{
	// for debug maybe?
	t_list	*turn;
	char	*move;
	int 	i;

	turn = lemin->turn_moves->start;
	while (turn)
	{
		i = 0;
		
		while (i < turn->content_size) //check this
		{
			move = turn->content; //lol idk
			printf("%s", move); // what about and number and L
		}
	}

}

void main()
{
	t_lemin	*lemin;

	lemin = capture_data();
	// error_check_data(data); //exit inside also use stderr etc.
	play_game(lemin);

	print_moves(lemin);

	return ;
}
