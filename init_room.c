#include "lem_in.h"

t_field *init_field(void)
{
    t_field *tmp;

    if (!(tmp = (t_field*)malloc(sizeof(t_field))))
        exit(1);
    tmp->head = NULL;
    tmp->tail = NULL;
    tmp->fd = 0; //DELETE
    tmp->size = 0;
    tmp->start_id = -1;
    tmp->end_id = -1;
    tmp->matrix = NULL;
    tmp->visited = NULL;
    tmp->way_head = NULL;
    tmp->way_tail = NULL;
    tmp->path_head = NULL;
    tmp->path_tail = NULL;
    return (tmp);
}

void	push_back_room(t_field *field)
{
    t_room	*tmp;

    if (!(tmp = (t_room*)malloc(sizeof(t_room))))
        exit(1);
    tmp->name = NULL;
    tmp->id = field->size;
    if (field->size == field->start_id)
        tmp->comment = field->start_id;
    else if  (field->size == field->end_id)
        tmp->comment = field->end_id;
    else
        tmp->comment = 0;
    tmp->x = 0;
    tmp->y = 0;
    if (field->tail)
        field->tail->next = tmp;
    field->tail = tmp;
    if (field->head == NULL)
        field->head = tmp;
    tmp->next = NULL;
}

void push_back_ways(t_field *field, int size)
{
    t_ways *tmp;

    if (!(tmp = (t_ways*)malloc(sizeof(t_ways))))
        exit(1);
    if (!(tmp->way = (int*)malloc(sizeof(int) * field->size)))
        exit(1);
    ft_fill_int(tmp->way, field->size, -1);
    tmp->size = size;
    if (field->way_tail)
        field->way_tail->next = tmp;
    field->way_tail = tmp;
    if (field->way_head == NULL)
        field->way_head = tmp;
    tmp->next = NULL;

}

void	push_back_path(t_field *field, int size)
{
    t_path *tmp;

    if (!(tmp = (t_path*)malloc(sizeof(t_path))))
        exit(1);
    if (!(tmp->way = (int*)malloc(sizeof(int) * size)))
        exit(1);
    tmp->size = size;
    if (field->path_tail)
        field->path_tail->next = tmp;
    field->path_tail = tmp;
    if (field->path_head == NULL)
        field->path_head = tmp;
    tmp->next = NULL;
}