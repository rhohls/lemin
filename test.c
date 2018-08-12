
#include "../includes/lemin.h"

int main()
{
	t_lemin *lemin;
	lemin = capture_data();
	// printf("rooms? %p\n", lemin->room_list);
	print_lemin(lemin);
	return (1);
}