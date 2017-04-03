#include "lem_in.h"

t_field *init_field(void)
{
    t_field *tmp;

    if (!(tmp = (t_field*)malloc(sizeof(t_field))))
        exit(1);
    tmp->head = NULL;
    tmp->tail = NULL;
    tmp->size = 0;
    tmp->start_id = -1;
    tmp->end_id = -1;
    tmp->matrix = NULL;
    tmp->way = NULL;
    return (tmp);
}

void	push_back_room(t_field *field, int id, int s_e)
{
    t_room	*tmp;

    if (!(tmp = (t_room*)malloc(sizeof(t_room))))
        exit(1);
    tmp->name = NULL;
    tmp->id = id;
    tmp->s_e = 0;
    tmp->x = 0;
    tmp->y = 0;
    if (field->tail)
        field->tail->next = tmp;
    field->tail = tmp;
    if (field->head == NULL)
        field->head = tmp;
}