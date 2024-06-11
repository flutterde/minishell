/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dup2dchar.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ochouati <ochouati@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 16:59:22 by ochouati          #+#    #+#             */
/*   Updated: 2024/06/11 17:08:04 by ochouati         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**dup2dchar(char **str)
{
	int		count;
	int		i;
	char	**new;

	count = ft_split_size(str);
	if (!count)
		return (NULL);
	new = malloc (sizeof(char *) * (count + 1));
	if (!new)
		return (NULL);
	i = 0;
	new[count] = NULL;
	while (i < count)
	{
		new[i] = ft_strdup(str[i]);
		if (!new[i])
			return (ft_free_strs(new), NULL);
		i++;
	}
	return (new);
}
