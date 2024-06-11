/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ochouati <ochouati@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 22:44:10 by ochouati          #+#    #+#             */
/*   Updated: 2024/06/11 19:58:11 by ochouati         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_found(char *haystack, char *needle, size_t len)
{
	size_t	i;

	i = 0;
	while (haystack[i] && i < len && needle[i] && (haystack[i] == needle[i]))
		i++;
	if ((!haystack[i] || i >= len) && needle[i])
		return (0);
	if (!needle[i])
		return (1);
	return (3);
}

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;

	i = 0;
	if (!ft_strlen(needle))
		return ((char *) haystack);
	while (haystack && haystack[i] && len >= ft_strlen(needle))
	{
		if (haystack[i] == needle[0])
		{
			if (!is_found((char *)&haystack[i], (char *)needle, len))
				return (NULL);
			if (is_found((char *)&haystack[i], (char *)needle, len) == 1)
				return ((char *)&haystack[i]);
		}
		i++;
		len--;
	}
	return (NULL);
}
