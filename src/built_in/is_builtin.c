/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_builtin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboujama <mboujama@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 11:10:15 by mboujama          #+#    #+#             */
/*   Updated: 2024/07/23 09:16:43 by mboujama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

int	is_builtin(t_cmd *cmd)
{
	if (!cmd || !cmd->cmd)
		return (0);
	if (!ft_strcmp("cd", cmd->cmd))
		return (1);
	else if (!ft_strcmp("export", cmd->cmd))
		return (1);
	else if (!ft_strcmp("unset", cmd->cmd))
		return (1);
	else if (!ft_strcmp("pwd", cmd->cmd))
		return (1);
	else if (!ft_strcmp("env", cmd->cmd))
		return (1);
	else if (!ft_strcmp("echo", cmd->cmd))
		return (1);
	else if (!ft_strcmp("exit", cmd->cmd))
		return (1);
	return (0);
}
