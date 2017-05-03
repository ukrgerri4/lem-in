#ifndef LEM_IN_LEM_IN_H
#define LEM_IN_LEM_IN_H

#include "ft_printf/ft_printf.h"
#include "libft/libft.h"

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
    int             id;
    int             *way;
    int             size;
    struct s_ways   *next;
}               t_ways;


typedef struct  s_path
{
    int             id;
    int             ant_nb;
    struct s_path   *next;
    struct s_path   *prev;
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
    int     shortest_set_id;
    int     set_len;
    int     shortest_len;
    char    **matrix;
    int     max_path_in_way;
    int     *visited;
    int     ways_quantity;
    t_ways  *way_head;
    t_ways  *way_tail;
    int     **arr_ways;
    int     *size_ways;
    int     **set_ways;
    t_path  **path_head;
    t_path  **path_tail;

}               t_field;

/*
 * basic function
 */
int     find_quantity_elem_in_line(char **line);
void    ft_fill_int(int *arr, int size, int n);

/*
 * t_room/t_field function
 */
t_field *init_field(void);
void	push_back_room(t_field *field);
void    push_back_ways(t_field *field, int size);
void	push_back_path(t_field *field, int id, int i);

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
void    write_ways_in_array(t_field *field);
void    initialize_sets(t_field *field);
void    fill_sets(t_field *field);
void    sort_set_of_ways(t_field *field);
void    find_shortest_way(t_field *field);
void    stw(t_field *field);

/*
 * help function
 */
char *proom(t_field *field, int id);

#endif
