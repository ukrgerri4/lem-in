/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_ants.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikryvenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/08 18:05:39 by ikryvenk          #+#    #+#             */
/*   Updated: 2017/05/08 18:35:55 by ikryvenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void		null_path(t_path **p, int size)
{
	int i;

	i = 0;
	while (i < size)
	{
		p[i] = NULL;
		i++;
	}
}

void		make_way(t_field *field)
{
	int		i;
	int		j;
	t_ways	*tmp;

	field->path_head = (t_path**)malloc(sizeof(t_path*) * field->set_len);
	null_path(field->path_head, field->set_len);
	field->path_tail = (t_path**)malloc(sizeof(t_path*) * field->set_len);
	null_path(field->path_tail, field->set_len);
	i = 0;
	tmp = field->way_head;
	while (tmp && (field->set_ways[field->shortest_set_id][i] != -1))
	{
		if (tmp->id == field->set_ways[field->shortest_set_id][i])
		{
			j = 0;
			while (tmp->way[j] != -1)
				push_back_path(field, tmp->way[j++], i);
			i++;
			tmp = field->way_head;
		}
		else if (tmp->next)
			tmp = tmp->next;
		else
			break ;
	}
}

static void	check_lemings(t_field *field)
{
	int		i;
	t_path	*tmp;

	i = 0;
	while (i < field->set_len)
	{
		tmp = field->path_tail[i];
		while (tmp->prev->id != field->start_id)
		{
			if (tmp->prev->ant_nb != -1)
			{
				ft_printf("L%d-%s ", tmp->prev->ant_nb, proom(field, tmp->id));
				tmp->ant_nb = tmp->prev->ant_nb;
				tmp->prev->ant_nb = -1;
			}
			if (tmp->prev->id != field->start_id)
				tmp = tmp->prev;
			else
				break ;
		}
		i++;
	}
}

void		show_them_way_continuation(t_field *field, int *lemings, int i)
{
	while (i < field->set_len && *lemings <= field->ant_quantity)
	{
		if (((field->ant_quantity - *lemings + 1) -
			field->size_ways[field->set_ways[field->shortest_set_id][i]]) >= 0)
		{
			field->path_head[i]->next->ant_nb = (*lemings)++;
			ft_printf("L%d-%s ", field->path_head[i]->next->ant_nb,
					proom(field, field->path_head[i]->next->id));
			i++;
		}
		else
			break ;
	}
}

void		show_them_way(t_field *field)
{
	int lemings;
	int i;
	int count;

	lemings = 1;
	count = 0;
	while (count < field->shortest_len)
	{
		check_lemings(field);
		if (lemings <= field->ant_quantity)
		{
			field->path_head[0]->next->ant_nb = lemings++;
			ft_printf("L%d-%s ", field->path_head[0]->next->ant_nb,
					proom(field, field->path_head[0]->next->id));
			i = 1;
			show_them_way_continuation(field, &lemings, i);
		}
		ft_printf("\n");
		count++;
	}
}
