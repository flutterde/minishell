/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ochouati <ochouati@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 17:24:45 by ochouati          #+#    #+#             */
/*   Updated: 2024/01/23 23:42:39 by ochouati         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_set(char c, char *buffer)
{
	int		i;

	i = 0;
	while (buffer[i])
	{
		if (buffer[i] == c)
			return (1);
		i++;
	}
	return (0);
}

static int	_handler(va_list ap, char c)
{
	if (c == 's')
		return (_ft_pustr(va_arg(ap, char *)));
	else if (c == 'i' || c == 'd')
		return (_ft_putbnr(va_arg(ap, int)));
	else if (c == 'c')
		return (_ft_puchar(va_arg(ap, int)));
	else if (c == '%')
		return (_ft_puchar('%'));
	else if (c == 'X' || c == 'x')
		return (_ft_hexa(va_arg(ap, unsigned int), c));
	else if (c == 'p')
		return (_ft_print_adrs(va_arg(ap, void *)));
	else if (c == 'u')
		return (_ft_print_u(va_arg(ap, t_unint)));
	return (0);
}

int	ft_printf(const char *str, ...)
{
	va_list	ap;
	int		i;
	int		j;

	if (write(1, 0, 0) == -1)
		return (-1);
	va_start(ap, str);
	i = -1;
	j = 0;
	while (str[++i])
	{
		if (str[i] == '%' && is_set(str[i + 1], "% +Xxdiscpu#"))
		{
			if (_is_speci_format(str[i + 1], str[i + 2]))
			{
				j += __bonus(str[i + 1], str[i + 2], ap);
				i += 2;
			}
			else
				j += _handler(ap, str[++i]);
		}
		else if (str[i] != '%')
			j += _ft_puchar(str[i]);
	}
	return (va_end(ap), j);
}
