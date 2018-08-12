
#include "../includes/lemin.h"

int	ft_strinstack(char *str, t_stack *stack_x)
{
	t_list	*lst;

	if (!str || !stack_x)	
		return (0);
	lst = stack_x->start;
	while (lst)
	{
		if (ft_strcmp(str, (char *)(lst->content)) == 0)
			return (1);
		lst = lst->next;
	}
	return(0);
}

int	ft_strinlist(char *str, char **list, int list_len)
{
	int i;

	i = 0;
	while(i < list_len)
	{
		if (ft_strcmp(str, list[i]) == 0)
			return (1);
		i++;
	}
	return (0);
}