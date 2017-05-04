#include "lem_in.h"

void    free_rooms(t_field *field)
{
    t_room *tmp;
    t_room *next;

    tmp = field->room_head;
    next = NULL;
    while (tmp)
    {
        next = tmp->next;
        free(tmp->name);
        tmp->name = NULL;
        free(tmp);
        tmp = next;
    }
    field->room_head = NULL;
    field->room_tail = NULL;
}

void free_matrix(t_field *field)
{
    int i;

    i = 0;
    while (i < field->size)
    {
        free(field->matrix[i]);
        field->matrix[i++] = NULL;
    }
    free(field->matrix);
    field->matrix = NULL;
    free(field->visited);
    field->visited = NULL;
}

void    free_ways(t_field *field)
{
    t_ways *tmp;
    t_ways *next;

    tmp = field->way_head;
    next = NULL;
    while (tmp)
    {
        next = tmp->next;
        free(tmp->way);
        tmp->way = NULL;
        free(tmp);
        tmp = next;
    }
    field->way_head = NULL;
    field->way_tail = NULL;
}

void    free_paths(t_field *field)
{
    t_path *tmp;
    t_path *next;
    int i;

    i = 0;
    while (i < field->set_len)
    {
        tmp = field->path_head[i];
        next = NULL;
        while (tmp)
        {
            next = tmp->next;
            free(tmp);
            tmp = NULL;
            tmp = next;
        }
        i++;
    }
    free(field->path_head);
    field->path_head = NULL;
    free(field->path_tail);
    field->path_tail = NULL;
}

void    free_project_memory(t_field *field)
{
    int i;

    free_rooms(field);
    free_matrix(field);
    free_ways(field);
    i = 0;
    while (i < field->ways_quantity)
    {
        free(field->arr_ways[i]);
        field->arr_ways[i] = NULL;
        free(field->set_ways[i]);
        field->set_ways[i] = NULL;
        i++;
    }
    free(field->arr_ways);
    field->arr_ways = NULL;
    free(field->set_ways);
    field->set_ways = NULL;
    free(field->size_ways);
    field->size_ways = NULL;
    free_paths(field);
}

