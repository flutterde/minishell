/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insert_to2d_array.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ochouati <ochouati@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 12:42:10 by ochouati          #+#    #+#             */
/*   Updated: 2024/07/04 12:42:48 by ochouati         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**insert_to2d_array(char **arr, char *str)
{
	int		count;
	char	**new_arr;

	if ((!arr && !str) || (arr && !*arr && !str))
		return (NULL);
	if (!arr && str)
		return (ft_split(str, '\0'));
	if (!str)
		return (dup_2d_array(arr));
	count = ft_split_size(arr) + 1;
	new_arr = (char **)malloc(sizeof(char *) * (count + 1));
	if (!new_arr)
		return (NULL);
	new_arr[count] = NULL;
	count = -1;
	while (arr && arr[++count])
	{
		new_arr[count] = ft_strdup(arr[count]);
		if (!new_arr[count])
			return (ft_free_strs(new_arr), NULL);
	}
	new_arr[count] = ft_strdup(str);
	if (!new_arr[count])
		return (ft_free_strs(new_arr), NULL);
	return (new_arr);
}
