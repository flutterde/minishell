/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dup_2d_array.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ochouati <ochouati@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 12:40:44 by ochouati          #+#    #+#             */
/*   Updated: 2024/07/04 12:41:05 by ochouati         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**dup_2d_array(char **arr)
{
	int		count;
	char	**new_arr;

	count = ft_split_size(arr);
	if (!count)
		return (NULL);
	new_arr = (char **)malloc(sizeof(char *) * (count + 1));
	if (!new_arr)
		return (NULL);
	new_arr[count] = NULL;
	count = 0;
	while (arr && arr[count])
	{
		new_arr[count] = ft_strdup(arr[count]);
		if (!new_arr[count])
			return (ft_free_strs(new_arr), NULL);
		count++;
	}
	return (new_arr);
}
