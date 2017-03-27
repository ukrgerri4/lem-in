#ifndef LEM_IN_LEM_IN_H
#define LEM_IN_LEM_IN_H

#include "ft_printf/ft_printf.h"
#include "libft/libft.h"

typedef struct  s_room
{
    char *name;
    int id;
    int x;
    int y;
    struct s_room next;
}               t_room;

typedef struct  s_field
{
    t_room  head;
    int     size;
}               t_field;

/*
 * validation function
 */
void    validation(void);

#endif //LEM_IN_LEM_IN_H
