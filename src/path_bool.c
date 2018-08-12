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

int is_occupied(char *room_name, char **ocupied_rooms)
{
	/* check if room will be occupied on certain turn num */


	if (ft_strcmp(room_name, ocupied_rooms[0]) == 0)
		return (1);
	else
		return (0);
}

int isinpath(char *room_name, t_stack *rooms_visted)
{

	if (ft_strinstack(room_name, rooms_visted) == 1)
		return (1);
	return (0);
}
