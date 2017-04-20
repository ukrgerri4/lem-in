#include "lem_in.h"

void    par(int *arr, int size) // DELETE!!
{
    int i = 0;
    while (i < size)
        ft_printf("%d ", arr[i++]);
    ft_printf("\n");
}

void    pways(t_field *field) // DELETE!!
{
    int i;
    t_ways *tmp = field->way_head;
    while (tmp)
    {
        i = 0;
        while (tmp->way[i] != -1 && i < field->size)
            ft_printf("%d  ", tmp->way[i++]);
        ft_printf("\nSize = %d\n", tmp->size);
        if (tmp->next)
            tmp = tmp->next;
        else
            break;
    }
}

int main(void)
{
    t_field *field;
    int     n;

    field = init_field();
    validation(field);
    reserve_ways(field);

    n = 0;
    if (!(field->visited = (int*)malloc(sizeof(int) * field->size)))
        exit(1);
    ft_fill_int(field->visited, field->size, -1);
    find_ways(field, field->start_id, n);
    //find_shortest_ways(field);

    pways(field);
    return (0);
}

