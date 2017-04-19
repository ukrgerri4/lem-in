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
    tmp->ways = NULL;
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