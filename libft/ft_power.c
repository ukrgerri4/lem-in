/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_power.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikryvenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/05 18:29:34 by ikryvenk          #+#    #+#             */
/*   Updated: 2016/12/06 16:09:01 by ikryvenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

double	ft_power(double nb, double pow)
{
	if (pow == 0)
		return (1);
	if (pow < 0)
		return (-1);
	return (nb = nb * ft_power(nb, (pow - 1)));
}