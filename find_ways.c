#include "lem_in.h"

static int check_visited(t_field *field, int i)
{
    int j;

    j = 0;
    while (j < field->size)
    {
        if (i == field->visited[j++])
            return (0);
    }
    return (1);
}

void    copy_way(t_field *field, int size)
{
    int i;

    i = 0;
    push_back_ways(field, size);
    while (field->visited[i] != -1 && i < field->size)
        field->way_tail->way[i] = field->visited[i++];

}

int    find_ways(t_field *field, int id, int n)
{
    int i;

    field->visited[n] = id;
    if (id != field->end_id)
    {
        i = 0;
        while (i < field->size)
        {
            if (field->matrix[id][i] == 1 && check_visited(field, i))
                find_ways(field, i, (n + 1));
            i++;
        }
    }
    else
        copy_way(field, n);
    field->visited[n] = -1;
    return (0);
}


void    find_shortest_ways(t_field *field)
{
    t_ways  *tmp;
    int     *buf;
    int     size;

    tmp = field->way_head;
    size = 0;
    if (!field->way_head)
        ft_error("Error. No ways was found!");
    if (!(buf = (int*)malloc(sizeof(int) * field->size)))
        exit(1);
    ft_fill_int(buf, field->size, -1);
    while (tmp)
    {
        if (size == 0 || tmp->size < size)
            size = tmp->size;
        if (tmp->next)
            tmp = tmp->next;
        else
            break;
    }
    //find shortest way
    //while field->ways_quantity find shortest ways witch has no double with another
}