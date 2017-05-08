/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_ways_3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikryvenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/08 18:04:14 by ikryvenk          #+#    #+#             */
/*   Updated: 2017/05/08 18:16:13 by ikryvenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static int	find_len_way(t_field *field, int *set)
{
	int lemings;
	int len;
	int i;

	len = 0;
	lemings = field->ant_quantity;
	while (lemings > 0)
	{
		lemings--;
		i = 1;
		while (set[i] != -1)
		{
			if ((lemings - field->size_ways[set[i]]) >= 0)
			{
				lemings--;
				i++;
			}
			else
				break ;
		}
		len++;
	}
	return (len + field->size_ways[set[i - 1]] - 1);
}

void		find_shortest_way(t_field *field)
{
	int i;
	int way_lenght;

	i = 0;
	while (i < field->ways_quantity)
	{
		way_lenght = find_len_way(field, field->set_ways[i]);
		if (field->shortest_len == 0 || way_lenght < field->shortest_len)
		{
			field->shortest_len = way_lenght;
			field->shortest_set_id = i;
		}
		i++;
	}
	while (field->set_ways[field->shortest_set_id][field->set_len] != -1)
		field->set_len++;
}
