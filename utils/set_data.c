/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_data.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ochouati <ochouati@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/29 15:07:17 by ochouati          #+#    #+#             */
/*   Updated: 2024/06/30 19:05:11 by ochouati         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

t_cmd	*set_data(t_env *env, char *path, char **args, char *cmd)
{
	t_cmd	*new;

	if (!env || !path || !args || !cmd || !*args)
		return (ft_printf("NO> args.\n"), NULL);
	new = ft_calloc(sizeof(new) * 1, sizeof(t_cmd));
	if (!new)
		return (NULL);
	new->args = args;
	new->cmd = cmd;
	new->env = env;
	new->path = path;
	return (new);
}
