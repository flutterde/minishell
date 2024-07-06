/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_absolute_path.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ochouati <ochouati@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 19:37:26 by ochouati          #+#    #+#             */
/*   Updated: 2024/07/05 19:53:59 by ochouati         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

char	*get_absolute_path(char *command, t_env *env)
{
	char	*pwd;

	if (!command || !env)
		return (NULL);
	pwd = getenv("PWD");
	if (command[0] == '/')
		return (ft_strdup(command));
	if (!pwd)
		return (NULL);
	if (command[0] == '.' && command[1] == '/')
		return (ft_strjoin(pwd, command + 1));
	return (get_cmd_path(getenv("PATH"), command));
}
