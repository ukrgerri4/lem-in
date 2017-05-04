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
        while (tmp->way[i] != -1)
            ft_printf("%s  ", proom(field, tmp->way[i++]));
        ft_printf("\n");
        if (tmp->next)
            tmp = tmp->next;
        else
            break;
    }
}


void	ft_put(char **arr, int i) // delete
{
    int x, y = 0;

    while (y < i)
    {
        x = 0;
        while (x < i)
        {
            if (arr[y][x])
                ft_printf("1");
            else
                ft_printf("0");
            x++;
        }
        ft_printf("\n");
        y++;
    }
}

/*-------INFO--------*/
/*
pways(field);
ft_printf("ways_quantity = %d, max_path_in_way = %d, ant_quantity = %d\n", field->ways_quantity, field->max_path_in_way, field->ant_quantity);
par2(field->set_ways, field->ways_quantity, -1);
for(int m = 0; m < field->ways_quantity; m++){
    ft_printf("Size id(%d) = %d\n", m, field->size_ways[m]);
}
ft_printf("shortest_len = %d, shortest_set_id = %d, set_len = %d\n", field->shortest_len, field->shortest_set_id, field->set_len);
*/
/*-------INFO--------*/

