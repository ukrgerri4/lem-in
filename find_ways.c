#include "lem_in.h"

static void write_way(t_field *field)
{
    int i;

    i = 0;
    while (i < field->size)
        field->way[i++] = -1;
}

static int find_id(t_field *field, int id)
{
    int y;

    y = 0;
    while (y < field->size)
    {
        if (field->matrix[y][id] && field->matrix[y][id] != -1)
        {
            field->matrix[y][id] = -1;
            field->matrix[id][y] = -1;
            return (y);
        }
        y++;
    }
    return (-1);
}

int    find_ways(t_field *field, int id, int n)
{
    int new_id;

    new_id = -1;
    if (id != field->end_id)
    {
        ft_printf(".0 %d\n", id);
        while ((new_id = find_id(field, id)) != -1)
        {
            ft_printf(".1 %d\n", id);
            if (find_ways(field, new_id, (n + 1) != -1))
            {
                field->way[n] = id;
                return (n);
            }
        }
    }
    else
    {
        field->way = (int*)malloc(sizeof(int) * field->size);
        write_way(field);
        field->way[n] = id;
        return (n);
    }
    return (-1); // need to return somthing useful
}