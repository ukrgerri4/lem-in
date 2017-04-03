#include "lem_in.h"

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


static int      room_id(t_field *field, char *room_name)
{
    t_room *tmp;

    tmp = field->head;
    while (tmp)
    {
        if (ft_strcmp(tmp->name, room_name) == 0)
            return (tmp->id);
        tmp = tmp->next;
    }
    ft_error("Error. Room does not exist.\n");
    return (0);
}

static void     write_link(t_field *field, char **line)
{
    int x;
    int y;

    if ((find_quantity_elem_in_line(line)) != 2)
        ft_error("Error. Bad links initalization. Too many rooms\n");
    y = room_id(field, line[0]);
    x = room_id(field, line[1]);
    field->matrix[y][x] = 1;
    field->matrix[x][y] = 1;
}

static void     init_matrix(t_field *field)
{
    int i;
    int j;

    j = 0;
    field->matrix = (char**)malloc(sizeof(char*) * (field->size + 1));
    while (j < field->size)
    {
        i = 0;
        field->matrix[j] = (char*)malloc(sizeof(char) * (field->size + 1));
        ft_bzero(field->matrix[j], (size_t)(field->size + 1));
        j++;
    }
}

void            validation_links(t_field *field, char *line)
{
    init_matrix(field); // create matrix
    write_link(field, ft_strsplit(line, '-'));
    ft_strdel(&line);
    while (get_next_line(0, &line))
    {
        write_link(field, ft_strsplit(line, '-'));
        ft_strdel(&line);
    }
    ft_put(field->matrix, field->size); // delete
}
