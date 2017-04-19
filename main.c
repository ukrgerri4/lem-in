#include "lem_in.h"

void    par(int *arr, int size) // DELETE!!
{
    int i = 0;
    while (i < size)
        ft_printf("%d ", arr[i++]);
    ft_printf("\n");
}

int main(void)
{
    t_field *field;
    int     n;
    int     j;

    field = init_field();
    validation(field);
    reserve_ways(field);
    n = 0;
    j = 0;
    while (find_ways(field, field->start_id, n) && (j != field->ways_quantity))
    {
        par(field->cur_way, field->size);
        change_matrix(field);
        field->cur_way = field->ways[++j];
    }

    return (0);
}

