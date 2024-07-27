/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_lst_to_2dchar.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ochouati <ochouati@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 13:21:26 by ochouati          #+#    #+#             */
/*   Updated: 2024/07/27 11:02:43 by ochouati         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

char **env_lst_to_2dchar(t_env *lst)
{
	char **new;
	int size;
	int i;

	size = size_env(lst);
	if (!size)
		return (NULL);
	new = ft_calloc((size + 1), sizeof(char *));
	if (!new)
		return (NULL);
	new[size] = NULL;
	i = 0;
	while (lst)
	{
		if (lst->value)
		{
			new[i] = ft_strjoin3(lst->key, "=", lst->value);
			if (!new[i])
				return (ft_free_strs(new), NULL);
			i++;
		}
		lst = lst->next;
	}
	return (new);
}

static char	*_ft__helper(char *s1, char *s2)
{
	if (!s1 && !s2)
		return (NULL);
	if (s1 && !s2)
		return (ft_strdup(s1));
	return (ft_strjoin3(s1, "=", s2));
}

char **env__to_2dchar(t_env *lst)
{
	char **new;
	int size;
	int i;

	size = size_env(lst);
	if (!size)
		return (NULL);
	new = ft_calloc((size + 1), sizeof(char *));
	if (!new)
		return (NULL);
	new[size] = NULL;
	i = 0;
	while (lst)
	{
		new[i] = _ft__helper(lst->key, lst->value);
		if (!new[i])
			return (ft_free_strs(new), NULL);
		i++;
		lst = lst->next;
	}
	return (new);
}
