/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhohls <rhohls@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/13 07:52:16 by rhohls            #+#    #+#             */
/*   Updated: 2018/08/27 11:57:19 by rhohls           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/lemin.h"


// int main()
// {
// 	t_ant	ant;
// 	t_lemin *lemin;
// 	lemin = capture_data(0);
// 	print_lemin(lemin);
// 	printf("lemin deatils done ----\n\n");

// 	// t_con *connect = lemin->connections->start->content;
// 	// char **list;
// 	// int i = 0;
// 	// list = connect->conections;
// 	// while (i < connect->connect_list->length)
// 	// {
// 	// 	printf("room: %s\n", list[i]);
// 	// 	i++;
// 	// }	

	
// 	ant.number = 1;
// 	ant.path = NULL;
// 	ant.turn_start = 0;
// 	find_path(lemin, &ant);
// 	printf("\n-- Ant details --\n");
// 	print_ant_details(&ant);
// 	printf("\nPrinting offcial path\n");
// 	print_moves(ant.path, lemin->num_ants);
// 	while(1)
// 	{}
// 	return (1);
// }


// void miniprint(char *str)
// {
// 	printf("in mini with |%s|\n",str);

// 	char *line;
// 	get_next_line(0, &line);
// 	printf("mini line:|%s|\n", line);
// 	free(line);
// }

int main()
{
		char *line;
		while (get_next_line(0, &line))
		{	
			printf("line sp:|%s|\n", line);
			if (ft_strcmp(line, "exit") == 0)
				break ;
			free(line);
		}
		return (1);
}