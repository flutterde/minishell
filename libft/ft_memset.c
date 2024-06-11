/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ochouati <ochouati@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 18:21:49 by ochouati          #+#    #+#             */
/*   Updated: 2023/12/07 19:16:18 by ochouati         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*nstr;
	size_t			i;

	nstr = (unsigned char *) b;
	i = 0;
	while (i < len)
	{
		nstr[i] = (unsigned char) c;
		i++;
	}
	return ((void *) nstr);
}
