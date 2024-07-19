/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dup_env.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboujama <mboujama@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 19:48:34 by ochouati          #+#    #+#             */
/*   Updated: 2024/07/06 10:56:19 by mboujama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

// ? increment SHLVL
static void	__shell_level(t_env *head)
{
	char	*tmp;
	char	*tmp2;
	t_env	*target;

	target = search_env(head, "SHLVL");
	if (!target)
		return ;
	tmp = ft_itoa(ft_atoi(target->value) + 1);
	if (!tmp)
		return ;
	tmp2 = target->value;
	target->value = tmp;
	free(tmp2);
}

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
	t_env	*head;
	t_env	*new;
	int		i;

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
	__shell_level(head);
	return (head);
}