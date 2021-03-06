#include "lem_in.h"

void    validation(t_field *field)
{
    char    *line;

    line = NULL;
    get_next_line(field->fd, &line);
    ft_printf("%s\n", line);
    if (!ft_isdigit(line[0]))
        ft_error("Error. There is no number of ants.\n");
    field->ant_quantity = ft_atoi(line);
    if (field->ant_quantity == 0)
        ft_error("Error. The number of ants is 0.\n");
    ft_strdel(&line);
    if (!validation_rooms(field, &line))
        ft_error("Error. Start/End room.\n");
    validation_links(field, line);
}
