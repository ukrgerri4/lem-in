#include "lem_in.h"

static void comment_visited_rooms(t_field *field, int id, char a, char b)
{
    int i;

    i = 0;
    while (i < field->size)
    {
        if (field->matrix[id][i] == a)
        {
            field->matrix[id][i] = b;
            field->matrix[i][id] = b;
        }
        i++;
    }
}

void    change_matrix(t_field *field)
{
    int i;

    i = 0;
    while (i < field->size)
    {
        if ((field->matrix[field->start_id][i] == -1) && i != field->cur_way[0])
        {

        }
    }
}

int    find_ways(t_field *field, int id, int n)
{
    int i;

    if (id != field->end_id)
    {
        i = 0;
        while (i < field->size)
        {
            if (field->matrix[id][i] == 1)
            {
                comment_visited_rooms(field, id, 1, -1);
                if (find_ways(field, i, (n + 1))) // if return success write i to field->ways and return success
                {
                    field->cur_way[n] = id;
                    return (1);
                }
                else
                    comment_visited_rooms(field, i, -1, 1);
            }
            i++;
        }
    }
    else
    {
        field->cur_way[n] = id;
        return (1);
        //write ways, make one more line for next ways and return success
    }
    return (0);
}