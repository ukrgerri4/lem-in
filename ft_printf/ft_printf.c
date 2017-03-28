/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikryvenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/04 19:12:42 by ikryvenk          #+#    #+#             */
/*   Updated: 2017/02/04 19:38:54 by ikryvenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_printf(const char *format, ...)
{
	va_list			ap;
	t_plist			*rules;
	int				i;

	i = 0;
	g_count = 0;
	rules = (t_plist*)malloc(sizeof(t_plist));
	va_start(ap, format);
	while (format[i])
	{
		if (format[i] == '%')
			if (!ft_checkparam(rules, format, ap, &i))
				return (g_count);
		if (format[i] && format[i] != '%')
			ft_putchar_count(format[i++]);
	}
	va_end(ap);
	free(rules);
	rules = NULL;
	return (g_count);
}
