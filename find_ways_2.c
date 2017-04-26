#include "lem_in.h"

static void	shells_sort(t_field *field, int *arr, int n, int tmp)
{
    int	k;
    int	i;
    int	j;

    k = n / 2;
    while (k > 0)
    {
        i = k;
        while (i < n)
        {
            tmp = arr[i];
            j = i;
            while (j >= k)
            {
                if (field->size_ways[tmp] < field->size_ways[arr[j - k]])
                    arr[j] = arr[j - k];
                else
                    break ;
                j -= k;
            }
            arr[j] = tmp;
            i++;
        }
        k /= 2;
    }
}

void    sort_set_of_ways(t_field *field)
{
    int i;
    int len;
    int tmp;

    i = 0;
    len = 0;
    tmp = 0;
    while (i < field->ways_quantity)
    {
        while (field->set_ways[i][len] != -1)
            len++;
        shells_sort(field, field->set_ways[i], len, tmp);
        len = 0;
        i++;
    }
}