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

t_lemin		*capture_data(void);

void		add_con_struct(char *room_name, t_lemin *lemin);
void		add_connection(char *str, t_lemin *lemin);

void		add_special_room(char *str, t_lemin *lemin, int fd);
void		*add_room(char *str, t_lemin *lemin);

void		delete_var(t_pathend *self);
void		ft_del_chararr(char **array, int amt);

int			ft_strinstack(char *str, t_stack *stack_x);
int			ft_strinlist(char *str, char **list, int list_len);

t_pathend	*init_self(t_lemin* lemin);
t_stack		*init_shortest_path(void);
void		init_lemin(t_lemin *lemin);

int			isinpath(char *room_name, t_stack *rooms_visted);
int			is_occupied(char *room_name, char **ocupied_rooms);

t_pathend	*duplicate_var(t_pathend *self);
t_stack		*ft_stackdup(t_stack *stack);
char		**gen_con_list(char *room_name, void *all_connections, int *num_con);
void		add_room_to_pathlist(char *room_name, void *path_list);
void		update_shrtpth(void *curr_path_list, t_stack *shortest_path);
void		*get_ocupied_rooms(t_stack *turn_moves, int turn_num);

void		path_to_end(t_pathend *self, t_stack *shortest_path);
void		run_new_branchs(t_pathend *self, t_stack *shortest_path);
t_stack		*find_path(t_lemin* lemin);

#endif
