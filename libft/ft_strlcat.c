/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ochouati <ochouati@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 17:10:09 by ochouati          #+#    #+#             */
/*   Updated: 2023/12/14 17:11:20 by ochouati         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	dtl;
	size_t	srcl;
	size_t	i;
	size_t	j;

	dtl = ft_strlen(dst);
	srcl = ft_strlen(src);
	if (size == 0 || size <= ft_strlen(dst))
		return (size + ft_strlen(src));
	i = 0;
	j = 0;
	i = dtl;
	while ((i < (size - 1)) && src[j])
		dst[i++] = ((char *)src)[j++];
	dst[i] = '\0';
	return (dtl + srcl);
}
