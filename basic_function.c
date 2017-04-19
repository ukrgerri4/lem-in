#include "lem_in.h"

int     find_quantity_elem_in_line(char **line)
{
    int i;

    i = 0;
    while (line[i])
        i++;
    return (i);
}

void ft_fill_int(int *arr, int size, int n)
{
    int				i;

    i = 0;
    while (size-- > 0)
        arr[i++] = n;
}