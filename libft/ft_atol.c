/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ochouati <ochouati@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 19:06:38 by ochouati          #+#    #+#             */
/*   Updated: 2024/02/28 19:27:15 by ochouati         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

long	ft_atol(char *str)
{
	long	res;
	int		i;
	long	s;

	i = 0;
	s = 1;
	res = 0;
	while (str && str[i] && str[i] == ' ')
		i++;
	if (str[i] && (str[i] == '-' || str[i] == '+'))
	{
		if (str[i] == '-')
			s = -1;
		i++;
	}
	while (str[i] && ft_isdigit(str[i]))
	{
		res = res * 10 + (str[i++] - 48);
	}
	return (res * s);
}
