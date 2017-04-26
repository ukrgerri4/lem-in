#include "lem_in.h"

static void    copy_way(int *dest, int *src, int size)
{
    int i;

    i = 0;
    while (i <= size)
    {
        dest[i] = src[i];
        i++;
    }
}

void    write_ways_in_array(t_field *field)
{
    int     i;
    t_ways  *tmp;

    if (!(field->arr_ways = (int**)malloc(sizeof(int*) * field->ways_quantity)))
        exit(1);
    if (!(field->size_ways = (int*)malloc(sizeof(int) * field->ways_quantity)))
        exit(1);
    i = 0;
    tmp = field->way_head;
    while (i < field->ways_quantity)
    {
        field->arr_ways[i] = (int*)malloc(sizeof(int) * (tmp->size + 1));
        copy_way(field->arr_ways[i], tmp->way, tmp->size);
        field->size_ways[i] = tmp->size;
        i++;
        tmp = tmp->next;
    }
}

void    initialize_sets(t_field *field)
{
    int i;

    if (!(field->set_ways = (int**)malloc(sizeof(int*) * field->ways_quantity)))
        exit(1);
    i = 0;
    while (i < field->ways_quantity)
    {
        field->set_ways[i] = (int*)malloc(sizeof(int) * (field->max_path_in_way + 1));
        ft_fill_int(field->set_ways[i], (field->max_path_in_way + 1), -1);
        i++;
    }

}


static int compare(t_field *field, int *set, int *x)
{
    int i;
    int j;
    int k;

    i = 0;
    while (set[i] != -1)
    {
        j = 1;
        while (field->arr_ways[set[i]][j] != field->end_id)
        {
            k = 1;
            while (x[k] != field->end_id)
            {
                if (x[k] == field->arr_ways[set[i]][j])
                    return (0);
                k++;
            }
            j++;
        }
        i++;
    }
    return (1);
}

void    fill_sets(t_field *field)
{
    int i;
    int j;
    int k;

    i= 0;
    while (i < field->ways_quantity)
    {
        j = 0;
        k = 0;
        field->set_ways[i][j++] = i;
        while (k < field->ways_quantity)
        {
            if (compare(field, field->set_ways[i], field->arr_ways[k]))
                field->set_ways[i][j++] = k;
            k++;
        }
        i++;
    }
}