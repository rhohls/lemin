

#include "../includes/lemin.h"

void delete_var(t_pathend *self)
{
	/* free all the variables */
	free(self);
}

void ft_del_chararr(char **array, int amt)
{
    int i;

    i = 0;
    if (!array)
        return ;
    while (i < amt)
    {
        if (array[i])
            free(array[i]);
        i++;
    }
    free(array);
}