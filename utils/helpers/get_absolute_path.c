/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_absolute_path.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ochouati <ochouati@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 19:37:26 by ochouati          #+#    #+#             */
/*   Updated: 2024/07/29 12:40:04 by ochouati         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

static char	*__absp(char *path)
{
	if (!access(path, F_OK))
		return (ft_strdup(path));
	return (NULL);
}

static char	*__relativepath(char *path)
{
	char	*pwd;
	char	*new;

	pwd = getenv("PWD");
	if (!path || !pwd)
		return (NULL);
	new = ft_strjoin(ft_strdup(pwd), path);
	if (!new)
		return (NULL);
	if (!access(new, F_OK))
		return (new);
	return (free(new), NULL);
}

char	*get_absolute_path(char *command, t_env *env)
{
	t_env	*node;

	node = search_env(env, "PATH");
	if (!command || !env)
		return (NULL);
	if (command[0] == '/')
		return (__absp(command));
	if (command[0] == '.' && command[1] == '/')
		return (__relativepath(command + 1));
	if (!node)
		return (NULL);
	return (get_cmd_path(node->value, command));
}
