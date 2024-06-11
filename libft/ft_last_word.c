/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_last_word.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ochouati <ochouati@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/03 21:33:45 by ochouati          #+#    #+#             */
/*   Updated: 2024/02/03 22:01:54 by ochouati         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_last_word(char *str)
{
	int		i;
	int		l;

	i = 0;
	l = 0;
	if (!str)
		return (NULL);
	l = ft_strlen(str);
	if (!l)
		return ("");
	while ((l - 1) >= 0 && str[l - 1] == ' ')
		l--;
	while ((l - 1) >= 0 && str[l - 1] != ' ')
	{
		i++;
		l--;
	}
	return (ft_substr((str + l), 0, i));
}
