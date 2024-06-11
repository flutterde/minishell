/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ochouati <ochouati@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 20:49:01 by ochouati          #+#    #+#             */
/*   Updated: 2023/12/11 12:34:35 by ochouati         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*t_s1;
	unsigned char	*t_s2;

	t_s1 = (unsigned char *)s1;
	t_s2 = (unsigned char *)s2;
	if (n == 0)
		return (0);
	while ((*t_s1 == *t_s2) && (n-- > 1))
	{
		t_s1++;
		t_s2++;
	}
	return (*t_s1 - *t_s2);
}
