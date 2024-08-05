/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linked_utils2_env.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ochouati <ochouati@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 13:13:07 by ochouati          #+#    #+#             */
/*   Updated: 2024/06/29 15:30:19 by ochouati         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

t_env	*search_env(t_env *head, char *key)
{
	while (key && head)
	{
		if (!ft_strncmp(head->key, key, (ft_strlen(key) + 1)))
			return (head);
		head = head->next;
	}
	return (NULL);
}

int	size_env(t_env *lst)
{
	int	i;

	i = 0;
	while (lst)
	{
		i++;
		lst = lst->next;
	}
	return (i);
}

t_env	*get_prev_env(t_env *head, t_env *node)
{
	if (!node || !head)
		return (NULL);
	while (head)
	{
		if (head->next == node)
			return (head);
		head = head->next;
	}
	return (NULL);
}
