/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_lst_to_2dchar.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ochouati <ochouati@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 13:21:26 by ochouati          #+#    #+#             */
/*   Updated: 2024/06/27 21:15:52 by ochouati         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

char	**env_lst_to_2dchar(t_env *lst)
{
	char	**new;
	int		size;
	int		i;

	size = size_env(lst);
	if (!size)
		return (NULL);
	new = malloc(sizeof(char *) * (size + 1));
	if (!new)
		return (NULL);
	new[size] = NULL;
	i = 0;
	while (lst)
	{
		new[i] = ft_strjoin3(lst->key, "=", lst->value);
		if (!new[i])
			return (ft_free_strs(new), NULL);
		lst = lst->next;
		i++;
	}
	return (new);
}
