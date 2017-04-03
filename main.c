#include "lem_in.h"

int main(void)
{
    t_field *field;
    int     n;

    field = init_field();
    validation(field);
    n = 0;
    ft_printf("start = %d, end = %d\n", field->start_id, field->end_id);
    find_ways(field, field->start_id, n);
    /*---------------------------------*/
    int i = 0;

    while (field->way[i] != -1)
        ft_printf("%d ", field->way[i++]);
    /*---------------------------------*/
    return (0);
}

