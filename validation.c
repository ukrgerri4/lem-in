#include "lem_in.h"

void    check_line(char *line)
{

}

void    validation(void)
{
    char    *line;
    int     quantity;

    get_next_line(0, &line);
    if (!ft_isdigit(line[0]))
        ft_error("Error\n");
    quantity = ft_atoi(line);
    while (get_next_line(0, &line))
    {
        check_line(line);
    }
}
