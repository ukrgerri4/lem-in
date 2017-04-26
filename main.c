#include "lem_in.h"

void    par(int **arr, int size) // DELETE!!
{
    int i = 0, j;
    while (i < size) {
        j = 0;
        while (j != 3)
            ft_printf("%d ", arr[i][j++]);
        ft_printf("\n");
        i++;
    }
    ft_printf("\n");
}

void    par2(int **arr, int size, int stop) // DELETE!!
{
    int i = 0, j;
    while (i < size) {
        j = 0;
        while (arr[i][j] != stop)
            ft_printf("%d ", arr[i][j++]);
        ft_printf("%d\n", arr[i][j]);
        i++;
    }
    ft_printf("\n");
}

void    pways(t_field *field) // DELETE!!
{
    int i;
    t_ways *tmp = field->way_head;
    while (tmp)
    {
        i = 0;
        ft_printf("Id = %d, Size = %d           ", tmp->id, tmp->size);
        while (tmp->way[i] != -1 && i < field->size)
            ft_printf("%d  ", tmp->way[i++]);
        ft_printf("\n");
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
    write_ways_in_array(field);
    initialize_sets(field);
    fill_sets(field);
    sort_set_of_ways(field);
    find_shortest_way(field);

    /*-------INFO--------*/
    pways(field);
    ft_printf("Количество путей = %d, Кол-во непересек = %d, lemings = %d\n", field->ways_quantity, field->max_path_in_way, field->ant_quantity);
    par2(field->set_ways, field->ways_quantity, -1);
    for(int m = 0; m < field->ways_quantity; m++){
        ft_printf("Size id(%d) = %d\n", m, field->size_ways[m]);
    }
    ft_printf("S.len = %d, S.set_id = %d\n", field->shortest_len, field->shortest_set_id);
    /*-------INFO--------*/
    return (0);
}

