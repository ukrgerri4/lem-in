#include "lem_in.h"

void    reserve_ways(t_field *field)
{
    int i;
    int count;

    i = 0;
    count = 0;
    while (i < field->size)
        if (field->matrix[field->start_id][i++])
            count++;
    i = 0;
    while (i < field->size)
        if (field->matrix[field->end_id][i++])
            field->ways_quantity++;
    if (field->ways_quantity > count)
        field->ways_quantity = count;
    if (field->ways_quantity == 0)
        ft_error("Error. There are no ways!\n");
}

