/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dup_env.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ochouati <ochouati@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 19:48:34 by ochouati          #+#    #+#             */
/*   Updated: 2024/06/11 21:27:50 by ochouati         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static t_env	*new_node(char *str)
{
	char	*key;
	char	*val;
	char	*tmp;

	if (!str)
		return (NULL);
	tmp = ft_strchr(str, '=');
	val = ft_strdup(tmp + 1);
	key = ft_substr(str, 0, (ft_strlen(str) - ft_strlen(tmp)));
	return (ls_create_env(key, val));
}

t_env	*dup_env(char **env)
{
	int		i;
	t_env	*head;
	t_env	*new;

	if (!env || !*env)
		return (NULL);
	head = NULL;
	i = 0;
	while (env[i])
	{
		new = new_node(env[i]);
		ls_add2end_env(&head, new);
		i++;
	}
	return (head);
}
