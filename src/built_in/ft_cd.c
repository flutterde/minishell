/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ochouati <ochouati@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 18:53:19 by ochouati          #+#    #+#             */
/*   Updated: 2024/07/29 10:32:50 by ochouati         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

char	*ft_cd(char *arg)
{
	char	*dir;
	char	*home;
	char	*new;

	dir = ft_calloc(2000, sizeof(char));
	if (!dir)
		return (g_status = 1, mini_printf(2, "Error\n"), NULL);
	getcwd(dir, 1999);
	if (!ft_strlen(arg) || !ft_strcmp(arg, "~"))
	{
		home = getenv("HOME");
		if (chdir(home) == -1)
			return (free(dir), mini_printf(2, "Error: %s\n",
					strerror(errno)), g_status = 1, NULL);
		getcwd(dir, 1999);
		return (new = ft_strdup(dir), free(dir), new);
	}
	else if (chdir(arg) == -1)
		return (g_status = 1, mini_printf(2, "Error: cd: %s: %s\n", arg,
				strerror(errno)), free(dir), NULL);
	getcwd(dir, 1999);
	return (new = ft_strdup(dir), free(dir), g_status = 0, new);
}

static void	_set2null(char **s1, char **s2, char **s3)
{
	*s1 = NULL;
	*s2 = NULL;
	*s3 = NULL;
}

static void	_free_srcs(char **s1, char **s2, char **s3)
{
	free(*s1);
	free(*s2);
	free(*s3);
	*s1 = NULL;
	*s2 = NULL;
	*s3 = NULL;
}

void	cd_handler(t_env *env, char *path)
{
	char	*oldpwd;
	char	*new;
	char	*_new;
	t_env	*node;

	if (!env)
		return ;
	_set2null(&oldpwd, &_new, &new);
	node = search_env(env, "PWD");
	if (node)
	{
		oldpwd = ft_strdup(node->value);
		if (!oldpwd)
			return ;
	}
	new = ft_cd(path);
	if (new)
	{
		_new = ft_strjoin3("OLDPWD", "=", oldpwd);
		ft_export(&env, _new);
		free(_new);
		_new = ft_strjoin3("PWD", "=", new);
		ft_export(&env, _new);
	}
	_free_srcs(&_new, &new, &oldpwd);
}
