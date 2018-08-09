

#include "./libft/includes/libft.h"
// #include "../includes/lemin.h"
#include <stdio.h>

int main()
{
	char str[] = "lol";
	char str1[] = "new ";
	char *list[2];

	list[1] = str;
	list[0] = str1;
	void *ptr;
	char **check;

	printf("string1: %s ", list[0]);
	printf("string2: %s \n", list[1]);

	ptr = (void *)list;

	check = (char **)ptr;

	
	printf("string1: %s ", check[0]);
	printf("string2: %s ", check[1]);
}