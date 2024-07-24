/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_newln.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ochouati <ochouati@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 14:29:39 by ochouati          #+#    #+#             */
/*   Updated: 2024/07/24 14:40:37 by ochouati         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

bool	ft_is_newln(char *op)
{
	int	i;

	i = 0;
	if (!op)
		return (false);
	if (op[i] != '-')
		return (false);
	i++;
	if (op[i] != 'n')
		return (false);
	while (op[i])
	{
		if (op[i] != 'n')
			return (false);
		i++;
	}
	return (true);
}
