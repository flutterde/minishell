/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_redirections.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ochouati <ochouati@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 11:14:48 by ochouati          #+#    #+#             */
/*   Updated: 2024/08/04 15:57:23 by ochouati         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

char	*__generate_path(void)
{
	char	*path;
	char	*rand;

	rand = ft_random(30);
	if (!rand)
		return (NULL);
	path = ft_strjoin(ft_strdup("/tmp/.minishell_"), rand);
	if (!path)
		return (free(rand), NULL);
	return (free(rand), path);
}

static void	__in(t_cmd *cmd, t_exec exec)
{
	(void) exec;
	if (cmd->red_fd[0] != -2)
	{
		if (dup2(cmd->red_fd[0], STDIN_FILENO) < 0)
		{
			mini_printf(2, "minishell: %s\n", strerror(errno));
			g_status = 1;
			exit(1);
		}
		close(cmd->red_fd[0]);
	}
}

static void	__out(t_cmd *cmd, t_exec exec)
{
	(void) exec;
	if (cmd->red_fd[1] != -2)
	{
		if (dup2(cmd->red_fd[1], STDOUT_FILENO) < 0)
		{
			mini_printf(2, "minishell: %s\n", strerror(errno));
			g_status = 1;
			exit(1);
		}
		close(cmd->red_fd[1]);
	}
}

void	exec_redirections(t_data *data, t_cmd *cmd, t_exec exec)
{
	(void) data;
	if ((cmd->red_fd[0] == -1) || (cmd->red_fd[1] == -1))
		exit(1);
	__in(cmd, exec);
	__out(cmd, exec);
	if (exec.i != (exec.count - 1))
	{
		if (cmd->red_fd[1] == -2)
		{
			if (dup2(exec.fd[1], STDOUT_FILENO) < 0)
			{
				mini_printf(2, "minishell: %s\n", strerror(errno));
				g_status = 1;
				exit(1);
			}
		}
		close(exec.fd[1]);
		close(exec.fd[0]);
	}
}
