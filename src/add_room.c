/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_room.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhohls <rhohls@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/13 07:47:25 by rhohls            #+#    #+#             */
/*   Updated: 2018/08/29 08:44:58 by rhohls           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lemin.h"

void	exit_redefine_special(void)
{
	ft_putstr("Error: Redefined start/end room\n");
	exit(0);
}

void	room_error_check(char **room_details, char *str)
{
	int error;

	error = 0;
	if (room_details[0] == NULL || room_details[1] == NULL
		|| room_details[2] == NULL)
		error = 4;
	else if ((ft_atoi_long(room_details[1]) == 0) &&
			(ft_strcmp(room_details[1], "0\0") != 0))
		error = 2;
	else if ((ft_atoi_long(room_details[2]) == 0) &&
			(ft_strcmp(room_details[2], "0\0") != 0))
		error = 3;
	else if (room_details[3] != NULL)
		error = 1;
	if (error != 0)
	{
		ft_printf("Error: Issue with line\nLine: \"%s\"\n", str);
		exit(0);
	}
}

void	add_room(char *str, t_lemin *lemin)
{
	char **room_details;
	char *room_name;

	room_details = ft_strsplit(str, ' ');
	room_error_check(room_details, str);
	room_name = room_details[0];
	ft_stackpush(lemin->room_list,
					ft_lstnew(room_name, ft_strlen(room_name)));
	add_con_struct(room_name, lemin);
	ft_del_chararr(room_details, 4);
}

void	add_special_room(char *str, t_lemin *lemin, t_list **node)
{
	char	*line;
	char	*room_name;

	if (ft_strcmp(str, "start") != 0 && ft_strcmp(str, "end") != 0)
		return ;
	while (*node && (*node)->content && ((char *)((*node)->content))[0] == '#')
		*node = (*node)->next;
	line = (*node)->content;
	add_room(line, lemin);
	room_name = (char *)(lemin->room_list->start->content);
	if (ft_strcmp(str, "start") == 0)
	{
		if (lemin->start != NULL)
			exit_redefine_special();
		lemin->start = ft_strdup(room_name);
	}
	else if (ft_strcmp(str, "end") == 0)
	{
		if (lemin->end != NULL)
			exit_redefine_special();
		lemin->end = ft_strdup(room_name);
	}
}
