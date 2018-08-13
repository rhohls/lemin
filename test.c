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
	t_lemin *lemin;
	lemin = capture_data();
	// printf("rooms? %p\n", lemin->room_list);
	print_lemin(lemin);
	return (1);
}
