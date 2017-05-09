/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikryvenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/08 18:06:13 by ikryvenk          #+#    #+#             */
/*   Updated: 2017/05/08 18:37:06 by ikryvenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static int	check_first_nb(char *line)
{
	int i;

	i = 0;
	if (line)
	{
		while (line[i])
		{
			if (!ft_isdigit(line[i++]))
				return (1);
		}
	}
	return (0);
}

void	validation(t_field *field)
{
	char	*line;

	line = NULL;
	get_next_line(field->fd, &line);
	ft_printf("%s\n", line);
	if (check_first_nb(line))
		ft_error("Error. Incorrect number of ants.\n");
	field->ant_quantity = ft_atoi(line);
	if (field->ant_quantity == 0)
		ft_error("Error. The number of ants is 0.\n");
	ft_strdel(&line);
	if (!validation_rooms(field, &line))
		ft_error("Error. Start/End room.\n");
	if (field->start_id == -1 || field->end_id == -1)
		ft_error("Error. There are no start/end room!\n");
	validation_links(field, line);
}
