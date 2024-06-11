/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   macros_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ochouati <ochouati@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 17:18:12 by ochouati          #+#    #+#             */
/*   Updated: 2024/01/23 23:42:33 by ochouati         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

bool	_is_dg(char c1, char c2)
{
	return ((c1 == '+' || c1 == ' ') && (c2 == 'd' || c2 == 'i'));
}

bool	_is_hx(char c1, char c2)
{
	return (c1 == '#' && (c2 == 'x' || c2 == 'X'));
}

bool	_is_ss(char c1, char c2)
{
	return (c1 == ' ' && c2 == 's');
}

bool	_is_speci_format(char c1, char c2)
{
	return (_is_dg(c1, c2) || _is_hx(c1, c2) || _is_ss(c1, c2));
}
