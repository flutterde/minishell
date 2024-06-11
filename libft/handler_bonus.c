/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handler_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ochouati <ochouati@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 17:08:07 by ochouati          #+#    #+#             */
/*   Updated: 2024/01/23 23:42:04 by ochouati         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ftp_sp_sn(char c, int nbr)
{
	int	i;

	i = 0;
	if (c == '+' && nbr < 0)
		return (i += _ft_putbnr(nbr));
	else if (c == '+' && nbr >= 0)
	{
		i += _ft_puchar('+');
		return (i += _ft_putbnr(nbr));
	}
	else if (c == ' ' && nbr < 0)
		return (i += _ft_putbnr(nbr));
	else if (c == ' ' && nbr >= 0)
	{
		i += _ft_puchar(' ');
		return (i += _ft_putbnr(nbr));
	}
	return (0);
}

int	h_hashtag(t_unint nb, char c)
{
	int	i;

	i = 0;
	if (nb == 0)
		return (_ft_hexa(nb, c));
	if (c == 'x')
	{
		i += _ft_pustr("0x");
		i += _ft_hexa(nb, c);
	}
	else if (c == 'X')
	{
		i += _ft_pustr("0X");
		i += _ft_hexa(nb, c);
	}
	return (i);
}

int	__bonus(char c, char c2, va_list ap)
{
	if (c == '#' && (c2 == 'X' || c2 == 'x'))
		return (h_hashtag(va_arg(ap, t_unint), c2));
	else if ((c == ' ' && c2 == 's'))
		return (_ft_pustr(va_arg(ap, char *)));
	else
		return (ftp_sp_sn(c, va_arg(ap, int)));
}
