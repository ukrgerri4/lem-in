#include "lem_in.h"

t_field *init_field(void)
{
    t_field *tmp;

    if (!(tmp = (t_field*)malloc(sizeof(t_field))))
        exit(1);
    tmp->head = NULL;
    tmp->tail = NULL;
    tmp->size = 0;
    return (tmp);
}

int main(void)
{
    t_field *field;

    field = init_field();
    validation(field);

    return (0);
}

