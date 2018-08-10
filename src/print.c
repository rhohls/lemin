




#include "../includes/lemin.h"

void print_str_stack(t_stack *stack)
{
    t_list *node;

    if (!stack || !stack->start)
    {
        printf("Nothing to print\n");
        return ;
    }
    node = stack->start;
    while(node)
    {
        printf("\t%s\n", (char *)(node->content));
        node = node->next;
    }
}

void print_char_starstar(char** str_list, int num_str)
{
    int i;

    i = 0;
    while (i < num_str)
    {
        printf("\t\t%s\n", str_list[i]);
        i++;
    }
}

void print_turnmoves(t_stack *turn_moves)
{
    t_list  *turn;
    int     i;

    if (!turn_moves || !turn_moves->start)
        return ;
    turn = turn_moves->start;
    i = 0;
    while(turn)
    {
        printf("\tTurn number: -%i-\n", i);
        print_char_starstar(turn->content, turn->content_size);
        turn = turn->next;
        i++;
    }
}

void print_connections(t_stack *conections)
{
    t_list  *room;
    t_con   *conn;

    if (!conections || !conections->start)
        return ;
    room = conections->start;
    while(room)
    {
        conn = room->content;
        printf("\tRoom name: \"%s\"\n", conn->name);
        print_char_starstar(conn->conections, conn->num_connections);
        room = room->next;
    }
}

void print_lemin(t_lemin *lemin)
{
    printf("Start |%s|\n", lemin->start);
    printf("End   |%s|\n", lemin->end);
    printf("Number of ants :%i:\n", lemin->num_ants);
    printf("\nAll rooms:\n");
    print_str_stack(lemin->room_list);

    printf("\nTurn moves:\n");
    print_turnmoves(lemin->turn_moves);
    
    printf("\nConnections:\n");
    print_connections(lemin->connections);




}