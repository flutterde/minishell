/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ochouati <ochouati@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 17:10:35 by ochouati          #+#    #+#             */
/*   Updated: 2024/06/11 19:57:17 by ochouati         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	if (!s)
		return (NULL);
	while (*s)
	{
		if ((unsigned char)*s == (unsigned char)c)
			return ((char *)s);
		s++;
	}
	if ((unsigned char)*s == (unsigned char)c)
		return ((char *)s);
	return (NULL);
}
