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

char *proom(t_field *field, int id)
{
    t_room *tmp = field->room_head;
    while (tmp)
    {
        if (tmp->id == id)
            return (tmp->name);
        if (tmp->next)
            tmp = tmp->next;
        else
            break;
    }
    return (NULL);
}

void    free_strsplit(char ***line, int size)
{
    int i;

    i = 0;
    while (i < size)
    {
        free((*line)[i]);
        (*line)[i++] = NULL;
    }
    free(*line);
    *line = NULL;
}