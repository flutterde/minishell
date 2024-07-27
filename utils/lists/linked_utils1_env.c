/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linked_utils1_env.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ochouati <ochouati@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 18:58:17 by ochouati          #+#    #+#             */
/*   Updated: 2024/07/26 09:19:21 by ochouati         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

t_env	*ls_create_env(char *key, char *val)
{
	t_env	*new;

	if (!key)
		return (NULL);
	new = ft_calloc(1, sizeof(t_env));
	if (!new)
		return (NULL);
	ft_bzero(new, sizeof(t_env));
	new->key = key;
	new->value = val;
	return (new);
}

t_env	*ls_last_env(t_env *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next)
		lst = lst->next;
	return (lst);
}

void	ls_add2end_env(t_env **lst, t_env *new)
{
	t_env	*last;

	if (!new || !lst)
		return ;
	if (!*lst)
	{
		*lst = new;
		return ;
	}
	last = ls_last_env(*lst);
	last->next = new;
}

void	ls_delete1_env(t_env *node)
{
	if (!node)
		return ;
	if (node->key)
		free((node)->key);
	if (node->value)
		free((node)->value);
	free(node);
}

void	ls_clear_env(t_env **lst)
{
	t_env	*tmp;

	if (!lst)
		return ;
	while (*lst)
	{
		tmp = (*lst)->next;
		ls_delete1_env(*lst);
		*lst = tmp;
	}
}
