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

static void    copy_way(t_field *field, int size)
{
    int i;

    i = 0;
    push_back_ways(field, size);
    while (field->visited[i] != -1 && i < field->size) {
        field->way_tail->way[i] = field->visited[i];
        i++;
    }

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