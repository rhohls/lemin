/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lemin_struct.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhohls <rhohls@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/14 07:44:37 by rhohls            #+#    #+#             */
/*   Updated: 2018/09/07 11:45:27 by rhohls           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEMIN_STRUCT_H
# define LEMIN_STRUCT_H

# include "../libft/includes/libft.h"

/*
** Will only need if printing
** typedef struct	s_room
** {
** 	char		*name;
** 	int			x_pos;
** 	int			y_pos;
** }				t_room;
*/

typedef struct	s_lemin
{
	char		*start;
	char		*end;
	int			num_ants;
	t_list		*map_feed;
	t_stack		*room_list;
	t_stack		*ant_list;
	t_stack		*turn_moves;
	t_stack		*connections;
	int			num_rooms;
	char		**key;
	int			**matrix;
}				t_lemin;

typedef struct	s_ant
{
	int			number;
	t_stack		*path;
	int			turn_num;
}				t_ant;

typedef struct	s_connection
{
	char		*name;
	char		**conections;
	t_stack		*connect_list;
	int			num_connections;
}				t_con;

/*
** turn moves = rooms ocupied that turn
** turn moves is a stack
** each link in list is a single turn
** each link contains a t_stack
** each link in that stack is an occupied room
** containing room name
*/

typedef struct	s_pathend
{
	char		*end;
	t_stack		*all_connections;
	t_stack		*turn_moves;
	int			turn_start;

	t_stack		*curr_path_list;
	char		*room_name;
	int			turn_num;
}				t_pathend;

typedef struct	s_vertex
{
	char		*name;
	char		**char_connect;
	t_stack		*stack_connect;
	int			num_connections;
	int			visited;
}				t_vertex;

typedef struct	s_graphpath
{
	t_stack		*graph;
	t_stack		*all_paths;
}				t_graphpath;

typedef t_stack	t_path;

typedef struct	s_parallel
{
	int			max_parallel;
	int			recurse_num;
	t_graphpath	*best;
}				t_parallel;

typedef struct	s_shrt_path
{
	int			*path;
	int			length;	
}				s_shrt_path;

#endif
