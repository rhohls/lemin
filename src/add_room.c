
#include "../includes/lemin.h"
#include <stdio.h>

void *add_room(char *str, t_lemin *lemin)
{
	/* 
	str_split ensure there is 3 (name, x, y)
	add to room list
	and coonection list
	*/
	char **room_details;
	char *room_name;

	room_details = ft_strsplit(str, ' ');
	if (room_details[3] != NULL)
	{
		printf("Issue with deatials of room (more than 3 arguments)\n");
		exit(0);
	}
	room_name = room_details[0];
	// check its name not already in list
	ft_stackpush(lemin->room_list,
					ft_lstnew(room_name, ft_strlen(room_name)));
	add_con_struct(room_name, lemin);
	ft_del_chararr(room_details, 3);
	// printf("detail addroom\n %p - %s \n", ((t_con *)lemin->connections->start->content)->name,(char*)((t_con *)lemin->connections->start->content)->name);

}

void add_special_room(char *str, t_lemin *lemin, int fd)
{
	char	*line;
	char	*room_name;

	if (get_next_line(fd, &line) != 1) // do i need this?
	{
		printf("bad gnl\n");
		exit(0);		
	}
	add_room(line, lemin);
	room_name = (char *)(lemin->room_list->start->content);
	if (ft_strcmp(str, "start") == 0)
		lemin->start = room_name;
	else if (ft_strcmp(str, "end") == 0)
		lemin->end = room_name;
	else
	{
		printf("Bad command: |##%s|", str);
		exit(0);		
	}
	free(line);
}