/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_printf.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ochouati <ochouati@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 23:52:52 by ochouati          #+#    #+#             */
/*   Updated: 2024/03/22 19:47:11 by ochouati         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	_ft_putchar(int fd, char c)
{
	write(fd, &c, 1);
}

static void	_ft_putstr(int fd, char *str)
{
	while (*str)
	{
		_ft_putchar(fd, (*str));
		str++;
	}
}

static void	_ft_putnbr(int fd, int nbr)
{
	if (nbr == -2147483648)
	{
		_ft_putstr(fd, "-2147483648");
		return ;
	}
	if (nbr < 0)
	{
		_ft_putchar(fd, '-');
		nbr = -nbr;
	}
	if (nbr >= 10)
		_ft_putnbr(fd, nbr / 10);
	_ft_putchar(fd, (nbr % 10) + 48);
}

static int	_is_ope(char c)
{
	if (c == 's' || c == 'd' || c == 'c')
		return (1);
	return (0);
}

void	mini_printf(int fd, const char *str, ...)
{
	int		i;
	va_list	ap;

	i = 0;
	va_start(ap, str);
	while (str[i])
	{
		if (str[i] == '%' && _is_ope(str[i + 1]))
		{
			i++;
			if (str[i] == 's')
				_ft_putstr(fd, va_arg(ap, char *));
			else if (str[i] == 'd')
				_ft_putnbr(fd, va_arg(ap, int));
			else if (str[i] == 'c')
				_ft_putchar(fd, va_arg(ap, int));
		}
		else if (str[i] != '%')
			_ft_putchar(fd, str[i]);
		i++;
	}
	va_end(ap);
}
