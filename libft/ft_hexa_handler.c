/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexa_handler.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ochouati <ochouati@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 17:24:42 by ochouati          #+#    #+#             */
/*   Updated: 2024/01/23 23:43:46 by ochouati         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	_ft_puchar(char c)
{
	write(1, &c, 1);
	return (1);
}

static void	_handle_hex(size_t nb, char *base)
{
	if (nb >= 16)
		_handle_hex(nb / 16, base);
	_ft_puchar(base[nb % 16]);
}

int	_ft_hexa(unsigned int nb, char c)
{
	t_unint	x;
	int		i;

	x = nb;
	i = 1;
	while (x >= 16)
	{
		i++;
		x = x / 16;
	}
	if (c == 'x')
		_handle_hex(nb, "0123456789abcdef");
	else
		_handle_hex(nb, "0123456789ABCDEF");
	return (i);
}

static int	_ft_hexa_t(size_t nb)
{
	size_t	x;
	int		i;

	x = nb;
	i = 3;
	while (x >= 16)
	{
		i++;
		x = x / 16;
	}
	_handle_hex(nb, "0123456789abcdef");
	return (i);
}

int	_ft_print_adrs(void *adrs)
{
	size_t	ad;

	if (!adrs)
		return (_ft_pustr("0x0"), 3);
	ad = (size_t)adrs;
	_ft_pustr("0x");
	return (_ft_hexa_t(ad));
}
