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
    int     quantity;
    int     size;
    char    **matrix;
}               t_field;

/*
 * t_room/t_field function
 */
void	push_back_room(t_field *field, int id, int s_e);

/*
 * validation function
 */
void    validation(t_field *field);
int     validation_rooms(t_field *field, char **line, int *flag);

#endif
