/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_lst2arr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboujama <mboujama@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/05 16:07:57 by ochouati          #+#    #+#             */
/*   Updated: 2024/08/05 19:12:01 by mboujama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

char	**str_lst2arr(t_str_lst *lst)
{
	char		**arr;
	int			i;
	int			len;
	t_str_lst	*tmp;

	if (!lst)
		return (NULL);
	len = 0;
	i = 0;
	tmp = lst;
	while (tmp)
	{
		len++;
		tmp = tmp->next;
	}
	arr = ft_calloc(len + 1, sizeof(char *));
	if (!arr)
		return (NULL);
	while (i < len)
	{
		arr[i] = ft_strdup(lst->str);
		lst = lst->next;
		i++;
	}
	return (arr);
}
