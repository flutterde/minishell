/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ochouati <ochouati@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 16:27:06 by ochouati          #+#    #+#             */
/*   Updated: 2023/12/15 17:05:20 by ochouati         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	len;
	size_t	i;
	size_t	j;
	char	*nstr;

	if (!s1 || !s2)
		return (NULL);
	len = ft_strlen(s1) + ft_strlen(s2);
	nstr = malloc(sizeof(char) * (len + 1));
	if (!nstr)
		return (NULL);
	i = 0;
	j = 0;
	while (s1[i])
		nstr[j++] = ((char *)s1)[i++];
	i = 0;
	while (s2[i])
		nstr[j++] = ((char *)s2)[i++];
	nstr[j] = '\0';
	return (nstr);
}
