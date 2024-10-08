/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_strs.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboujama <mboujama@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/03 21:04:36 by ochouati          #+#    #+#             */
/*   Updated: 2024/07/22 16:22:20 by mboujama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_print_strs(char **strs)
{
	int	i;

	i = 0;
	while (strs && strs[i])
		ft_putendl_fd(strs[i++], 1);
}
