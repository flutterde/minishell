/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split3.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ochouati <ochouati@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 17:02:48 by ochouati          #+#    #+#             */
/*   Updated: 2024/03/06 17:11:26 by ochouati         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	***ft_split3(char *str, char c1, char c2)
{
	char	***new;
	char	**snew;
	int		i;
	int		l;

	snew = ft_split(str, c1);
	if (!snew)
		return (NULL);
	l = ft_split_size(snew);
	new = malloc (sizeof(char **) * (l + 1));
	if (!new)
		return (NULL);
	new[l] = NULL;
	i = -1;
	while (snew[++i])
		new[i] = ft_split(snew[i], c2);
	return (ft_free_strs(snew), new);
}
