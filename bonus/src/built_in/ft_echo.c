/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ochouati <ochouati@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 19:26:31 by ochouati          #+#    #+#             */
/*   Updated: 2024/08/03 14:41:33 by ochouati         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

static int	_multi_n(char **args)
{
	int	i;

	i = 0;
	if (!args)
		return (g_status = 0, 1);
	while (args[i] && ft_is_newln(args[i]))
		i++;
	if (!args[i])
		return (g_status = 0, 1);
	return (print_joined_strs(&args[i], " ", 0), g_status = 0, 1);
}

int	ft_echo(t_cmd *cmd, t_data *data)
{
	if (!cmd || !data)
		return (0);
	if (cmd->args && cmd->args[0] && !cmd->args[1])
		return (ft_putstr_fd("\n", 1), g_status = 0, 1);
	else if (cmd->args[1] && ft_is_newln(cmd->args[1]))
		return (_multi_n(&cmd->args[2]));
	else if (cmd->args[1] && !ft_is_newln(cmd->args[1]))
		return (print_joined_strs(&cmd->args[1], " ", 1), g_status = 0, 1);
	return (g_status = 1, 0);
}
