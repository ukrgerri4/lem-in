#include "lem_in.h"

static int    check_start_end(t_field *field, char *line, int *flag)
{
    if (ft_strcmp(line, "##start"))
    {
        push_back_room(field, field->size, 1); // initialize start room
        *flag = 1;
        return (1);
    }
    else if (ft_strcmp(line, "##end"))
    {
        push_back_room(field, field->size, 2); // initialize end room
        *flag = 2;
        return (2);
    }
    else if (line[0] == '#')
    {
        return (3); // do somthing;
    }
    else
    {
        if (*flag == 0)
            push_back_room(field, field->size, 0);
        *flag = 0;
        return (0);
    }
}

static int     find_quantity_elem_in_line(char **line)
{
    int i;

    i = 0;
    while (line[i])
        i++;
    return (i);
}

static int     check_digit(char *str)
{
    int i;

    i = 0;
    while (str[i])
    {
        if (!ft_isdigit(str[i++]))
            ft_error("Error. Bad room initalization. Coordinates not digit\n");
    }
}

static int    check_room_parameters(t_field *field, char **line)
{
    int q_elem;

    q_elem = 0;
    if ((q_elem = find_quantity_elem_in_line(line)) == 1)
        return (1);
    else if (q_elem != 3)
        ft_error("Error. Bad room initalization. Too many parameters\n");
    field->tail->name = ft_strdup(line[0]);
    check_digit(line[1]);
    field->tail->x = ft_atoi(line[1]);
    check_digit(line[2]);
    field->tail->x = ft_atoi(line[2]);
    return (0);
}

int    validation_rooms(t_field *field, char **line, int *flag)
{
    while (get_next_line(0, line))
    {
        if (check_start_end(field, *line, flag) == 0)
        {
            if (check_room_parameters(field, ft_strsplit(*line, ' ')) == 1)
                break ;
            field->size++;
        }
        ft_strdel(line);
    }
    return (*flag);
}