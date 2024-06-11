/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_string_bits.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ochouati <ochouati@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/03 21:04:20 by ochouati          #+#    #+#             */
/*   Updated: 2024/02/03 21:04:23 by ochouati         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_print_string_bits(char *str)
{
	int	i;
	int	j;

	i = 0;
	while (str && str[i])
	{
		j = 7;
		while (j >= 0)
			ft_putnbr_fd(((str[i] >> j--) & 1), 1);
		i++;
		if (str[i])
			ft_putchar_fd(' ', 1);
	}
}
