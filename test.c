/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhohls <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/13 07:52:16 by rhohls            #+#    #+#             */
/*   Updated: 2018/08/13 07:52:19 by rhohls           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/lemin.h"


int main()
{
	t_ant	ant;
	t_lemin *lemin;
	lemin = capture_data(0);
	print_lemin(lemin);

	find_path(lemin, &ant);
	print_ant_details(&ant);

	return (1);
}


// void miniprint(char *str)
// {
// 	printf("in mini with |%s|\n",str);

// 	char *line;
// 	get_next_line(0, &line);
// 	printf("mini line:|%s|\n", line);
// 	free(line);
// }
// int main()
// {
// 	char *line;
// 	while (get_next_line(0, &line))
// 	{	
// 		printf("line sp:|%s|\n", line);
// 		free(line);
// 	}
// 	return (1);
// }