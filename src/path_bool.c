/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_bool.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhohls <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/13 07:48:17 by rhohls            #+#    #+#             */
/*   Updated: 2018/08/13 07:48:20 by rhohls           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lemin.h"

int	is_occupied(char *room_name, t_stack *ocupied_rooms)
{
	/* check if room will be occupied on certain turn num */
	if (ft_strinstack(room_name, ocupied_rooms) == 1)
		return (1);
	return (0);

}

int	isinpath(char *room_name, t_stack *rooms_visted)
{
	// printf("Checking if in path\n");
	if (ft_strinstack(room_name, rooms_visted) == 1)
		return (1);
	return (0);
}
