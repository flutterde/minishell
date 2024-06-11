/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_helpers.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ochouati <ochouati@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 17:24:37 by ochouati          #+#    #+#             */
/*   Updated: 2024/01/23 23:43:23 by ochouati         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	_ft_pustr(char *str)
{
	int	i;

	i = 0;
	if (str)
	{
		while (str[i])
			_ft_puchar(str[i++]);
	}
	else
	{
		write(1, "(null)", 6);
		i = 6;
	}
	return (i);
}

static int	_count(int nb)
{
	int	i;

	i = 1;
	if (nb == INT_MIN)
		return (11);
	if (nb < 0)
	{
		i++;
		nb = -nb;
	}
	while (nb > 9)
	{
		i++;
		nb = nb / 10;
	}
	return (i);
}

int	_ft_putbnr(int nb)
{
	int	i;

	i = _count(nb);
	if (nb == INT_MIN)
	{
		_ft_pustr("-2147483648");
	}
	else
	{
		if (nb < 0)
		{
			_ft_puchar('-');
			nb = -nb;
		}
		if (nb > 9)
			_ft_putbnr(nb / 10);
		_ft_puchar((nb % 10) + 48);
	}
	return (i);
}

static void	_pr_u(t_unint nb)
{
	if (nb > 9)
		_pr_u(nb / 10);
	_ft_puchar((nb % 10) + '0');
}

int	_ft_print_u(t_unint nb)
{
	int		i;
	t_unint	x;

	i = 1;
	x = nb;
	while (x > 9)
	{
		i++;
		x = x / 10;
	}
	return (_pr_u(nb), i);
}
