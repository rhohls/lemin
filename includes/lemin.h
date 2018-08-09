/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lemin.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhohls <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/07 08:57:02 by rhohls            #+#    #+#             */
/*   Updated: 2018/08/07 10:15:50 by rhohls           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEMIN_H
# define LEMIN_H

# include "../libft/includes/libft.h"
# include <stdlib.h>

typedef struct	s_room
{
	char		*name;
	int			occupied;
	int			num_connections;
	char		**conections;
}				t_room;

typedef struct	s_path
{
	char		**path;
	int			path_step;
}				t_path;

// typedef t_stack t_path;

typedef struct	s_ant
{
	int			number;
	t_path		path;
}				t_ant;

typedef struct	s_lemin
{
	char		*start;
	char		*end;
	t_room		*room_list;
	int			num_ants;
	t_ant		*ant_list;
}				t_lemin;

typedef struct	s_connection
{
	char		*name;
	char		**conections;
	int			num_connections;
}				t_con;

/* 
** turn moves is a stack of char **
** each link in list is a single turn
** each link contains the list of moves 
** specifically the rooms that will be occupied that turn
*/


typedef struct	s_pathend
{
	char		*end;
	t_con		**all_connections; //list with all connections
	t_stack		*turn_moves; //see above
	int			turn_start;

	t_stack		*curr_path_list; //stack	
	char		*room_name;
	int			turn_num;
}				t_pathend;

void path_to_end(t_pathend *self, t_stack *shortest_path);

void delete_var(t_pathend *self);
t_pathend *duplicate_var(t_pathend *self);
// char **gen_con_list(char *room_name, void *all_connections);

void add_room_tolist(char *room_name, void *path_list);
void update_shrtpth(void *curr_path_list, t_stack *shortest_path);
int ft_strstrlen(char **strlist);
int isinpath(char *room_name, t_stack *rooms_visted);

void make_new_branch(t_pathend *self, t_stack *shortest_path);
void path_to_end(t_pathend *self, t_stack *shortest_path);
void find_path(void *turn_moves);



#endif
