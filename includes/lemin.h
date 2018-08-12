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
# include <stdio.h>

void ft_del_chararr(char **array, int amt);

/* might not need 
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
	t_stack		*connect_list; //convert to send to path
	int			num_connections;
}				t_con;

/*
** turn moves = rooms ocupied that turn
** turn moves is a stack
** each link in list is a single turn
** each link contains a char **
** the content size is number of char *
** each char* is the room name
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
t_stack *find_path(t_lemin* lemin);

int ft_strinstack(char *str, t_stack *stack_x);


t_lemin *capture_data(void);
void print_lemin(t_lemin *lemin);
void print_str_connection(t_stack *stack);

void add_con_struct(char *room_name, t_lemin *lemin);
t_pathend *init_self(t_lemin* lemin);
t_stack *ft_stackdup(t_stack *stack);
t_pathend *duplicate_var(t_pathend *self);




#endif
