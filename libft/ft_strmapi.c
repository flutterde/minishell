/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ochouati <ochouati@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 21:11:38 by ochouati          #+#    #+#             */
/*   Updated: 2023/12/23 17:20:16 by ochouati         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*newstr;
	unsigned int	i;
	int				len;
	char			*ns;

	i = 0;
	if (!s || !f)
		return (NULL);
	ns = (char *) s;
	len = ft_strlen(ns);
	newstr = malloc(len + 1);
	if (!newstr)
		return (NULL);
	newstr[len] = '\0';
	while (s[i])
	{
		newstr[i] = f(i, s[i]);
		i++;
	}
	return (newstr);
}
