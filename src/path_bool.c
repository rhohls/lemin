/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_bool.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhohls <rhohls@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/13 07:48:17 by rhohls            #+#    #+#             */
/*   Updated: 2018/08/29 09:10:15 by rhohls           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lemin.h"

int	is_occupied(char *room_name, t_stack *ocupied_rooms)
{
	if (ft_strinstack(room_name, ocupied_rooms) == 1)
		return (1);
	return (0);

}

int	isinpath(char *room_name, t_stack *rooms_visted)
{
	if (ft_strinstack(room_name, rooms_visted) == 1)
		return (1);
	return (0);
}
