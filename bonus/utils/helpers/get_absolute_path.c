/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_absolute_path.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ochouati <ochouati@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 19:37:26 by ochouati          #+#    #+#             */
/*   Updated: 2024/07/30 10:50:21 by ochouati         ###   ########.fr       */
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

static char	*___else(t_env *env, char *cmd)
{
	t_env	*node;

	node = search_env(env, "PATH");
	if (!node)
	{
		if (!access(cmd, F_OK))
			return (ft_strdup(cmd));
		return (NULL);
	}
	return (get_cmd_path(node->value, cmd));
}

char	*get_absolute_path(char *command, t_env *env)
{
	if (!ft_strlen(command))
		return (NULL);
	if (command[0] == '/')
		return (__absp(command));
	if (command[0] == '.' && command[1] == '/')
		return (__relativepath(command + 1));
	return (___else(env, command));
}
