

#include "./libft/includes/libft.h"
#include "./includes/lemin.h"
#include <stdio.h>

t_stack *make_stack(void)
{
	t_list *node;
	t_stack *stack; 
	stack = ft_stacknew();

	char test[] = "new string";
	// char *test = ft_strdup("new string");
	node = ft_lstnew((void *)test, ft_strlen(test));
	ft_stackpush(stack, node);
	char test1[] = "2nd str";
	// char *test1 = ft_strdup("2nd str");
	node = ft_lstnew((void *)test1, ft_strlen(test1));
	ft_stackpush(stack, node);
	char test2[] = "hello";
	// char *test2 = ft_strdup("hello");
	node = ft_lstnew((void *)test2, ft_strlen(test2));
	ft_stackpush(stack, node);
	char test3[] = "world wow";
	// char *test3 = ft_strdup("world wow");
	node = ft_lstnew((void *)test3, ft_strlen(test3));
	ft_stackpush(stack, node);

	return (stack);
}
void stringin_test(t_stack *stack)
{
	t_stack test;
	printf("Test string in stack\n");
	if (ft_strinstack("bad", stack) == 1)
		printf("fail test 0\n");
	if (ft_strinstack("new string", stack) == 0)
		printf("fail test 1\n");
	if (ft_strinstack("2nd str", stack) == 0)
		printf("fail test 2");
	if (ft_strinstack("hello", stack) == 0)
		printf("fail test 3");
	if (ft_strinstack("world wow", stack) == 0)
		printf("fail test 4\n");
	if (ft_strinstack(NULL, stack) == 1)
		printf("fail test 5\n");
	if (ft_strinstack("hello", NULL) == 1)
		printf("fail test 6\n");
	if (ft_strinstack("\0", stack) == 1)
		printf("fail test 7\n");
	test.start = NULL;
	if (ft_strinstack("hello", &test) == 1)
		printf("fail test 8\n");
}

// void print_str_stack(t_stack *stack)
// {
//     t_list *node;

//     if (!stack)
//         return ;
//     node = stack->start;
//     while(node)
//     {
//         printf("\t%s\n", (char *)(node->content));
//         node = node->next;
//     }
// }

int main()
{
	printf("~~~ Doing tests ~~~\n");
	t_stack *stack = make_stack();
	// stringin_test(stack);
	printf("Stack length: %zu   - address: %p\n",stack->length, stack);
	printf("Printing strings\n");
	print_str_stack(stack);

	ft_stackrev(stack);

	printf("Stack length: %zu   - address: %p\n",stack->length, stack);
	printf("Printing strings\n");
	print_str_stack(stack);

	ft_stackdel(&stack);
	printf("Printing strings - post delete\n");
	print_str_stack(stack);
	printf("stack %p\n",stack);
	
	while(1)
	{}
	
	return (1) ;
}