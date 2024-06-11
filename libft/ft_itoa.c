/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ochouati <ochouati@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 15:41:29 by ochouati          #+#    #+#             */
/*   Updated: 2023/12/16 15:13:48 by ochouati         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	cnbr(int nb)
{
	int	i;

	i = 1;
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

static char	*_handler(char *str, int i, int nbr)
{
	int	hdneg;

	hdneg = 0;
	if (nbr < 0)
	{
		str[0] = '-';
		nbr = -nbr;
		hdneg = 1;
	}
	while (i >= hdneg)
	{
		str[i--] = (nbr % 10) + 48;
		nbr = nbr / 10;
	}
	return (str);
}

char	*ft_itoa(int n)
{
	int		c;
	char	*str;

	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	c = cnbr(n);
	str = malloc(c + 1);
	if (!str)
		return (NULL);
	str[c] = '\0';
	return (_handler(str, c - 1, n));
}
