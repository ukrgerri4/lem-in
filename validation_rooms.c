#include "lem_in.h"

static int    check_start_end(t_field *field, char *line)
{
    if (!ft_strcmp(line, "##start"))
    {
        if (field->start_id == -1)
            field->start_id = field->size;
        else
            ft_error("Error. Can't be more than one start/end!\n");
        return (0);
    }
    else if (!ft_strcmp(line, "##end"))
    {
        if (field->end_id == -1)
            field->end_id = field->size;
        else
            ft_error("Error. Can't be more than one start/end!\n");
        return (0);
    }
    /*
    else if (line[0] == '#' && !*flag)
    {
        return (*flag = 123456); // do somthing;
    }
    */
    else
        return (1);
}

static void     check_digit(char *str)
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
    push_back_room(field);
    field->tail->name = ft_strdup(line[0]);
    check_digit(line[1]);
    field->tail->x = ft_atoi(line[1]);
    check_digit(line[2]);
    field->tail->x = ft_atoi(line[2]);
    return (0);
}

int    validation_rooms(t_field *field, char **line)
{
    while (get_next_line(0, line))
    {
        if (check_start_end(field, *line))
        {
            if (check_room_parameters(field, ft_strsplit(*line, ' ')) == 1)
                return (1);
            field->size++;
        }
        ft_strdel(line);
    }
    return (0);
}