/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ochouati <ochouati@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 19:19:30 by ochouati          #+#    #+#             */
/*   Updated: 2023/12/20 19:21:26 by ochouati         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	char		*my_dst;
	const char	*my_src;

	my_dst = (char *)dst;
	my_src = (const char *)src;
	if ((!src && !dst))
		return (NULL);
	if (dst == src)
		return (dst);
	while (n > 0)
	{
		*my_dst = *my_src;
		my_dst++;
		my_src++;
		n--;
	}
	return (dst);
}
