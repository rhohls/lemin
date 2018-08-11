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
#include <stdio.h>

int bad_command(char *str)
{
	if (str == NULL || str[0] == '\0' || str[0] == '\n')
		return (1);
	else
		return (0);
}

t_lemin *capture_data(void)
{
	t_lemin *lemin;
	char	*line;
	int		fd;

	fd = 0;
	lemin = (t_lemin *)malloc(sizeof(t_lemin));
	init_lemin(lemin);
	if (get_next_line(fd, &line) != 1)
	{
		printf("bad gnl return\n");
		exit(0);
	}
	//atoi str cmp for 0
	lemin->num_ants = ft_atoi(line);
	free(line);

	while(get_next_line(fd, &line) == 1)
	{
		if (bad_command(line))
		{
			printf("bad command: |%s|", line);
			exit(0);
		}
		else if (line[0] == '#' && line[1] == '#')
		{
			add_special_room(line + 2, lemin, fd);
		}
		else if (ft_strchr(line, '-'))
		{
			// break into new gnl loop
			// maybe - cause all conns come after rooms
			add_connection(line, lemin);
		}
		else if (line[0] != '#')
		{
			// its a room! (add it) - not sure if going to 
			add_room(line, lemin);
		}
		free(line);
	}
	return(lemin);
}

int main()
{
	t_lemin *lemin;
	lemin = capture_data();
	// printf("rooms? %p\n", lemin->room_list);
	print_lemin(lemin);
	return (1);
}