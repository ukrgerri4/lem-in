/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_room.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikryvenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/08 18:04:50 by ikryvenk          #+#    #+#             */
/*   Updated: 2017/05/08 18:20:01 by ikryvenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

t_field	*init_field(void)
{
	t_field	*tmp;

	if (!(tmp = (t_field*)malloc(sizeof(t_field))))
		exit(1);
	tmp->room_head = NULL;
	tmp->room_tail = NULL;
	tmp->fd = open("../map.txt", O_RDONLY);
	tmp->size = 0;
	tmp->start_id = -1;
	tmp->end_id = -1;
	tmp->shortest_set_id = -1;
	tmp->set_len = 0;
	tmp->shortest_len = 0;
	tmp->max_path_in_way = 0;
	tmp->matrix = NULL;
	tmp->visited = NULL;
	tmp->ways_quantity = 0;
	tmp->way_head = NULL;
	tmp->way_tail = NULL;
	tmp->arr_ways = NULL;
	tmp->size_ways = NULL;
	tmp->set_ways = NULL;
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
	else if (field->size == field->end_id)
		tmp->comment = field->end_id;
	else
		tmp->comment = 0;
	tmp->x = 0;
	tmp->y = 0;
	if (field->room_tail)
		field->room_tail->next = tmp;
	field->room_tail = tmp;
	if (field->room_head == NULL)
		field->room_head = tmp;
	tmp->next = NULL;
}

void	push_back_ways(t_field *field, int size)
{
	t_ways	*tmp;

	if (!(tmp = (t_ways*)malloc(sizeof(t_ways))))
		exit(1);
	if (!(tmp->way = (int*)malloc(sizeof(int) * (field->size + 1))))
		exit(1);
	tmp->id = field->ways_quantity++;
	ft_fill_int(tmp->way, (field->size + 1), -1);
	tmp->size = size;
	if (field->way_tail)
		field->way_tail->next = tmp;
	field->way_tail = tmp;
	if (field->way_head == NULL)
		field->way_head = tmp;
	tmp->next = NULL;
}

void	push_back_path(t_field *field, int id, int i)
{
	t_path	*tmp;

	if (!(tmp = (t_path*)malloc(sizeof(t_path))))
		exit(1);
	tmp->id = id;
	tmp->ant_nb = -1;
	tmp->next = NULL;
	tmp->prev = field->path_tail[i];
	if (field->path_tail[i])
		field->path_tail[i]->next = tmp;
	field->path_tail[i] = tmp;
	if (field->path_head[i] == NULL)
		field->path_head[i] = tmp;
	tmp->next = NULL;
}
