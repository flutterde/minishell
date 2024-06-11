/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ochouati <ochouati@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 20:52:55 by ochouati          #+#    #+#             */
/*   Updated: 2023/12/14 17:11:56 by ochouati         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	i;

	i = -1;
	if (dstsize == 0)
		return (ft_strlen(src));
	while (++i < (dstsize - 1) && src[i])
		dst[i] = ((char *)src)[i];
	dst[i] = '\0';
	return (ft_strlen(src));
}
