/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lemin.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhohls <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/07 08:56:17 by rhohls            #+#    #+#             */
/*   Updated: 2018/08/07 09:00:43 by rhohls           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lemin.h"

void play_game(t_lemin* lemin)
{
	int		i;
	t_ant	*ant;
	i = 0;

	while (i < lemin->num_ants)
	{
		ant = get_ant(lemin, i);
		ant->path = find_path(lemin);
		update_moves(ant->path);
		i++;
	}
}

void main()
{
	ft_putstr("I am lemin\n");
	t_lemin	*lemin;

	lemin = capture_data();
	// error_check_data(data); //exit inside also use stderr etc.
	play_game(lemin);

	print_moves(lemin);

	return ;
}
