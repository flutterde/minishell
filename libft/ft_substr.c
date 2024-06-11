/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ochouati <ochouati@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 18:44:30 by ochouati          #+#    #+#             */
/*   Updated: 2023/12/23 16:48:50 by ochouati         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*sub;
	size_t	slen;
	size_t	i;

	i = -1;
	if (!s)
		return (NULL);
	slen = ft_strlen(s);
	if (start >= slen)
		return (ft_strdup(""));
	if (len > slen - start)
		return (ft_strdup(s + start));
	sub = malloc(len + 1);
	if (!sub)
		return (NULL);
	while (++i < len)
		sub[i] = s[start + i];
	sub[i] = '\0';
	return (sub);
}
