/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_execve.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ochouati <ochouati@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/28 20:36:43 by ochouati          #+#    #+#             */
/*   Updated: 2024/07/30 13:19:05 by ochouati         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

//! DELETE THIS FILE

void	ft_execve(t_cmd *cmd)
{
	int		_id;
	int		_status;

	_id = fork();
	if (!_id)
	{
		if (execve(cmd->path, cmd->args, env_lst_to_2dchar(cmd->env)))
		{
			ft_errno(errno);
			exit(errno);
		}
	}
	else
	{
		if (waitpid(_id, &_status, 0) == -1)
			ft_errno(errno);
	}
}
