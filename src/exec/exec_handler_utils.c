/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_handler_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ochouati <ochouati@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/26 16:53:28 by ochouati          #+#    #+#             */
/*   Updated: 2024/07/26 16:53:50 by ochouati         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

int	s_builtin_handler(t_data *data)
{
	char	**args;

	if (!data || !data->command)
		return (0);
	args = data->command->args;
	if (args && !ft_strcmp(args[0], "echo"))
		return (ft_echo(data->command, data));
	else if (args && !ft_strcmp(args[0], "pwd"))
		return (pwd_cmd());
	else if (args && !ft_strcmp(args[0], "cd"))
		return (cd_handler(data->env, args[1]), 1);
	else if (args && !ft_strcmp(args[0], "export"))
		return (export_handler(data->command, data), 1);
	else if (args && !ft_strcmp(args[0], "unset"))
		return (unset_handler(data->command, data), 1);
	else if (args && !ft_strcmp(args[0], "env"))
		return (_print_env(data->env), 1);
	else if (args && !ft_strcmp(args[0], "exit"))
		return (exit_handler(data, data->command), 1);
	return (0);
}
