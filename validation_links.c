#include "lem_in.h"

static int      room_id(t_field *field, char *room_name)
{
    t_room *tmp;

    tmp = field->room_head;
    while (tmp)
    {
        if (ft_strcmp(tmp->name, room_name) == 0)
            return (tmp->id);
        if (tmp->next)
            tmp = tmp->next;
        else
            break;
    }
    ft_error("Error. Room does not exist.\n");
    return (0);
}

static void     write_link(t_field *field, char **line)
{
    int x;
    int y;

    if ((find_quantity_elem_in_line(line)) != 2)
        ft_error("Error. Bad links initalization.\n");
    y = room_id(field, line[0]);
    x = room_id(field, line[1]);
    field->matrix[y][x] = 1;
    field->matrix[x][y] = 1;
    free_strsplit(&line, 2);
}

static void     init_matrix(t_field *field)
{
    int j;

    j = 0;
    field->matrix = (char**)malloc(sizeof(char*) * (field->size + 1));
    while (j < field->size)
    {
        field->matrix[j] = (char*)malloc(sizeof(char) * (field->size + 1));
        ft_bzero(field->matrix[j], (size_t)(field->size + 1));
        j++;
    }
}

void            validation_links(t_field *field, char *line)
{
    init_matrix(field);
    write_link(field, ft_strsplit(line, '-'));
    ft_strdel(&line);
    while (get_next_line(field->fd, &line))
    {
        ft_printf("%s\n", line);
        if (line[0] != '#')
            write_link(field, ft_strsplit(line, '-'));
        ft_strdel(&line);
    }
    ft_strdel(&line);
}
