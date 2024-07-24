/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_joined_strs.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ochouati <ochouati@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 14:51:55 by ochouati          #+#    #+#             */
/*   Updated: 2024/07/24 14:53:56 by ochouati         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	print_joined_strs(char **strs, char *sep, bool ln)
{
	int		i;

	i = 0;
	if (!strs || !sep)
		return ;
	while (strs[i])
	{
		ft_putstr_fd(strs[i], 1);
		if (strs[i + 1])
			ft_putstr_fd(sep, 1);
		i++;
	}
	if (ln)
		ft_putstr_fd("\n", 1);
}
