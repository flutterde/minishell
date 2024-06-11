/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_first_word.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ochouati <ochouati@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/03 21:09:22 by ochouati          #+#    #+#             */
/*   Updated: 2024/02/03 21:29:29 by ochouati         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_first_word(char *str)
{
	int		i;
	int		j;

	i = -1;
	j = 0;
	if (!str)
		return (NULL);
	while (*str && *str == ' ')
		str++;
	while (str[++i] && str[i] != ' ')
		j++;
	return (ft_substr(str, 0, j));
}
