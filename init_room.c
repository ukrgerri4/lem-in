#include "lem_in.h"

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
    field->size++;
}