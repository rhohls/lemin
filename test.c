/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhohls <rhohls@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/13 07:52:16 by rhohls            #+#    #+#             */
/*   Updated: 2018/08/29 08:41:14 by rhohls           ###   ########.fr       */
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

int main(int argc, char **argv)
{
	int result;
	if (argc != 2)
		return (0);
	result = ft_atoi_long(argv[1]);
	printf("result %d\n", result);
	return (1);
}