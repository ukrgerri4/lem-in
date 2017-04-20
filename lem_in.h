#ifndef LEM_IN_LEM_IN_H
#define LEM_IN_LEM_IN_H

#include "ft_printf/ft_printf.h"
#include "libft/libft.h"

#include <stdio.h> // DELETE

typedef struct  s_room
{
    char *name;
    int id;
    int comment;
    int x;
    int y;
    struct s_room *next;
}               t_room;

typedef struct  s_ways
{
    int             *way;
    int             size;
    struct s_ways   *next;
}               t_ways;

typedef struct  s_path
{
    int             *way;
    int             size;
    struct s_path   *next;
}               t_path;

typedef struct  s_field
{
    t_room  *head;
    t_room  *tail;
    int     fd;//DELETE
    int     ant_quantity;
    int     size;
    int     start_id;
    int     end_id;
    char    **matrix;
    int     ways_quantity;
    int     *visited;
    t_ways  *way_head;
    t_ways  *way_tail;
    t_path  *path_head;
    t_path  *path_tail;

}               t_field;

/*
 * basic function
 */
int     find_quantity_elem_in_line(char **line);
void ft_fill_int(int *arr, int size, int n);

/*
 * t_room/t_field function
 */
t_field *init_field(void);
void	push_back_room(t_field *field);
void push_back_ways(t_field *field, int size);
void	push_back_path(t_field *field, int size);

/*
 * validation function
 */
void    validation(t_field *field);
int     validation_rooms(t_field *field, char **line);
void    validation_links(t_field *field, char *line);

/*
 * find_way function
 */
void    reserve_ways(t_field *field);
int     find_ways(t_field *field, int id, int n);

#endif
