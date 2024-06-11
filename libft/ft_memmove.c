/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ochouati <ochouati@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 12:59:36 by ochouati          #+#    #+#             */
/*   Updated: 2023/12/11 19:35:06 by ochouati         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char	*s;
	unsigned char	*d;
	size_t			i;

	s = (unsigned char *)src;
	d = (unsigned char *)dest;
	if (!d && !s)
		return (d);
	i = -1;
	if (d < s)
		while (++i < n)
			d[i] = s[i];
	else
		while (--n + 1 > 0)
			d[n] = s[n];
	return (d);
}
