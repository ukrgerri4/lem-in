#include "lem_in.h"

int main(void)
{
    t_field *field;
    int     n;

    field = init_field();
    validation(field);
    reserve_ways(field);
    n = 0;
    if (!(field->visited = (int*)malloc(sizeof(int) * (field->size + 1))))
        exit(1);
    ft_fill_int(field->visited, field->size + 1, -1);
    find_ways(field, field->start_id, n);
    write_ways_in_array(field);
    initialize_sets(field);
    fill_sets(field);
    sort_set_of_ways(field);
    find_shortest_way(field);
    ft_printf("\n");
    make_way(field);
    show_them_way(field);
    free_project_memory(field);
    free(field);
    field = NULL;
    return (0);
}

