#ifndef LEM_IN_LEM_IN_H
#define LEM_IN_LEM_IN_H

#include "ft_printf/ft_printf.h"
#include "libft/libft.h"

typedef struct  s_room
{
    char *name;
    int id;
    char s_e;
    int x;
    int y;
    struct s_room *next;
}               t_room;

typedef struct  s_field
{
    t_room  *head;
    t_room  *tail;
    int     ant_quantity;
    int     size;
    int     start_id;
    int     end_id;
    char    **matrix;
    int     *way;
}               t_field;

/*
 * basic function
 */
int     find_quantity_elem_in_line(char **line);

/*
 * t_room/t_field function
 */
t_field *init_field(void);
void	push_back_room(t_field *field, int id, int s_e);

/*
 * validation function
 */
void    validation(t_field *field);
int     validation_rooms(t_field *field, char **line, int *flag);
void    validation_links(t_field *field, char *line);

/*
 * find_way function
 */
int    find_ways(t_field *field, int id, int n);

#endif
