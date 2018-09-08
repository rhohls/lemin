/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_room.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhohls <rhohls@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/13 07:47:25 by rhohls            #+#    #+#             */
/*   Updated: 2018/09/08 13:40:55 by rhohls           ###   ########.fr       */
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
	// printf("\nin add_room with str %s and room name %s\n", str, room_name);
	if (room_name[0] == 'L' || ft_strinstack(room_name, lemin->room_list))
	{
		ft_printf("Error: Invalid room \"%s\"\n", room_name);
		exit(0);
	}
	// printf("len of name: %zu \n", ft_strlen(room_name));
	ft_stackpush(lemin->room_list,
					ft_lstnew(room_name, ft_strlen(room_name) + 1));
	add_con_struct(room_name, lemin);
	ft_del_chararr(room_details, 4);
	// printf("top room_list in add_room %s\n", lemin->room_list->start->content);
}

void	add_special_room(char *str, t_lemin *lemin, t_list **node)
{
	char	*line;
	char	*room_name;
	
	
	if (ft_strcmp(str, "printadjust") == 0)
	{
		lemin->print_path = 1;
		return ;
	}
	else if (ft_strcmp(str, "start") != 0 && ft_strcmp(str, "end") != 0)
		return ;
	// while (*node && (*node)->content && ((char *)((*node)->content))[0] == '#')
	*node = (*node)->next;
	line = (*node)->content;
	add_room(line, lemin);
	room_name = (char *)(lemin->room_list->start->content);
	if (ft_strcmp(str, "start") == 0)
	{
		if (lemin->start != NULL)
			exit_redefine_special();
		lemin->start = ft_strdup(room_name);
		// printf("added start %s from %s\n", lemin->start, room_name);
	}
	else if (ft_strcmp(str, "end") == 0)
	{
		if (lemin->end != NULL)
			exit_redefine_special();
		lemin->end = ft_strdup(room_name);
	}
}
