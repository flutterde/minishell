/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ochouati <ochouati@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 19:14:44 by ochouati          #+#    #+#             */
/*   Updated: 2023/12/16 19:10:32 by ochouati         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	x_isspace(char c)
{
	if (c == 32 || (c <= 13 && c >= 9))
		return (1);
	return (0);
}

static int	x_is_c_number(char c)
{
	if (c >= 48 && c <= 57)
		return (1);
	return (0);
}

static int	_islong(char *str)
{
	int	i;
	int	c;

	i = 0;
	c = 0;
	while (str[i] == '0')
		i++;
	while (str[i] && x_is_c_number(str[i]))
	{
		i++;
		c++;
	}
	if (c > 19)
		return (1);
	return (0);
}

int	ft_atoi(const char *str)
{
	size_t	x;
	int		s;
	int		i;

	s = 1;
	i = 0;
	x = 0;
	while (str[i] && x_isspace(str[i]))
		i++;
	if (str[i] == '+' || str[i] == '-')
		if (str[i++] == '-')
			s = -1;
	if (x_is_c_number(str[i]) && _islong((char *)&str[i]))
	{
		if (s == 1)
			return (-1);
		return (0);
	}
	while (str[i] && x_is_c_number(str[i]))
		x = (x * 10) + (str[i++] - 48);
	if (x > LMA && s == 1)
		return (-1);
	if (x > LMN && s == -1)
		return (0);
	return ((int)x * s);
}
