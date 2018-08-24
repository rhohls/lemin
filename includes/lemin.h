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
# include "./lemin_struct.h"
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>

t_lemin		*capture_data(int fd);
void		update_capture(t_lemin *lemin);

void		add_con_struct(char *room_name, t_lemin *lemin);
t_con		*find_con(t_stack *connections, char *room_name);
void		add_connection(char *str, t_lemin *lemin);

void		add_special_room(char *str, t_lemin *lemin, int fd);
void		add_room(char *str, t_lemin *lemin);

void		delete_var(t_pathend **self);
void		ft_del_chararr(char **array, int amt);

int			ft_strinstack(char *str, t_stack *stack_x);
int			ft_strinlist(char *str, char **list, int list_len);

t_pathend	*init_self(t_lemin* lemin);
t_stack		*init_shortest_path(void);
void		init_lemin(t_lemin *lemin);

int			isinpath(char *room_name, t_stack *rooms_visted);
int			is_occupied(char *room_name, t_stack *ocupied_rooms);

char		**ft_stacktochar(t_stack *stack);
t_pathend	*duplicate_var(t_pathend *self);
char		**get_char_con_list(char *room_name, void *all_connections, int *num_con);
void		add_room_to_pathlist(char *room_name, t_stack *path_list);
void		update_shrtpth(t_stack *curr_path_list, t_stack **shortest_path);
t_stack		*get_ocupied_rooms(t_stack *turn_moves, int turn_num);

void		path_to_end(t_pathend *self, t_stack *shortest_path);
void		run_new_branchs(t_pathend *self, t_stack *shortest_path);
void		find_path(t_lemin *lemin, t_ant *ant);

void		print_lemin(t_lemin *lemin);
void		print_ant_details(t_ant *ant);
void		print_str_connection(t_stack *stack);
void		print_turnmoves(t_stack *turn_moves);
void		print_str_stack(t_stack *stack);

t_stack		*ft_stackdup(t_stack *stack);
void		ft_stackdel(t_stack **stack);
void		ft_stackrev(t_stack *stack);

void	print_moves(t_stack *moves, int num_ants);

#endif
