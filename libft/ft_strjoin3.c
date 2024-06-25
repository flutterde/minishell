/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ochouati <ochouati@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 16:45:44 by ochouati          #+#    #+#             */
/*   Updated: 2024/03/01 18:44:43 by ochouati         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin3(char *s1, char *s2, char *s3)
{
	char	*new;
	int		l;
	int		i;
	int	j;

	l = ft_strlen(s1) + ft_strlen(s2) + ft_strlen(s3);
	if (!l)
		return (NULL);
	new = malloc (l + 1);
	if (!new)
		return (NULL);
	i = 0;
	j = 0;
	while (s1 && i < l && s1[j])
		new[i++] = s1[j++];
	j = 0;
	while (s2 && i < l && s2[j])
		new[i++] = s2[j++];
	j = 0;
	while (s3 && i < l && s3[j])
		new[i++] = s3[j++];
	return (new[i] = '\0', new);
}