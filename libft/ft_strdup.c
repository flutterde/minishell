/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ochouati <ochouati@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 16:35:44 by ochouati          #+#    #+#             */
/*   Updated: 2024/01/24 00:25:01 by ochouati         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*ns;
	size_t	i;

	if (!s1)
		return (NULL);
	ns = malloc(ft_strlen(s1) + 1);
	if (!ns)
		return (NULL);
	i = -1;
	while (s1[++i])
		ns[i] = s1[i];
	ns[i] = '\0';
	return (ns);
}
