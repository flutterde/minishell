/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_join_args.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ochouati <ochouati@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/05 11:06:36 by ochouati          #+#    #+#             */
/*   Updated: 2024/08/05 13:38:37 by ochouati         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	_count_strslen(char **args)
{
	int	i;
	int	coun;

	if (!args)
		return (0);
	i = 0;
	coun = 0;
	while (args[i])
	{
		coun += ft_strlen(args[i]);
		if (args[i + 1] && args[i + 1][0])
			coun++;
		i++;
	}
	return (coun);
}

char	*ft_join_args(char **args, char sep)
{
	int		count;
	int		i;
	int		j;
	int		k;
	char	*new;

	if (!args)
		return (NULL);
	i = 0;
	j = 0;
	k = 0;
	count = _count_strslen(args);
	if (count < 1)
		return (NULL);
	new = (char *)ft_calloc((count + 1), sizeof(char));
	while (args[i])
	{
		j = 0;
		while (args[i][j])
			new[k++] = args[i][j++];
		if (args[i + 1] && args[i + 1][0])
			new[k++] = sep;
		i++;
	}
	return (ft_free_strs(args), args = NULL, new);
}
