/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lemin_struct.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhohls <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/14 07:44:37 by rhohls            #+#    #+#             */
/*   Updated: 2018/08/14 07:44:43 by rhohls           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEMIN_STUCT_H
# define LEMIN_STUCT_H

# include "../libft/includes/libft.h"
/* Will only need if printing 
typedef struct	s_room
{
	char		*name;
	int			x_pos;
	int			y_pos;
}				t_room;
*/

/*
** room list is
*/

typedef struct	s_lemin
{
	char		*start;
	char		*end;
	int			num_ants;
	t_stack		*room_list;
	t_stack		*ant_list;
	t_stack		*turn_moves;
	t_stack		*connections;
}				t_lemin;

typedef struct	s_ant
{
	int			number;
	t_stack		*path;
	int			turn_start;
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
	t_stack		*all_connections; //stack pointing to t_con
	t_stack		*turn_moves; //see above
	int			turn_start;
	/* ^-const   v-delta */
	t_stack		*curr_path_list; 	
	char		*room_name;
	int			turn_num;
}				t_pathend;

#endif