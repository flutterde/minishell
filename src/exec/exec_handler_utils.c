/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_handler_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ochouati <ochouati@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/26 16:53:28 by ochouati          #+#    #+#             */
/*   Updated: 2024/08/02 18:22:05 by ochouati         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

int	built_in_wrapper(t_data *data)
{
	char	**args;
	
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

static void	_close_fds(int fd1, int fd2)
{
	if (fd1 >= 0)
		close(fd1);
	if (fd2 >= 0)
		close(fd2);
}

static int	_helper_fn(t_cmd *cmd, int *outfd)
{
	if (cmd->red_fd[1] != -2)
	{
		if (dup2(*outfd, STDOUT_FILENO) < 0)
			return (close(*outfd), -1);
		close(*outfd);
	}
	return (0);
}

int	s_builtin_handler(t_data *data)
{
	int		outfd;
	t_cmd	*cmd;

	if (!data || !data->command)
		return (0);
	cmd = data->command;
	redire_handler(data, cmd->redire, cmd->red_fd);
	if (cmd->red_fd[0] == -1 || cmd->red_fd[1] == -1)
		return (_close_fds(cmd->red_fd[0], cmd->red_fd[1]),
			g_status = 1, 0);
	outfd = -2;
	if (cmd->red_fd[1] != -2)
		outfd = dup(STDOUT_FILENO);
	if (outfd == -1)
		return (_close_fds(cmd->red_fd[0], cmd->red_fd[1]),
			perror("Error: "), g_status = 1, 0);
	if (cmd->red_fd[1] != -2)
	{
		if (dup2(cmd->red_fd[1], STDOUT_FILENO) < 0)
			return (_close_fds(cmd->red_fd[0], cmd->red_fd[1]),
				perror("Error: "), close(outfd), g_status = 1, 0);
	}
	built_in_wrapper(data);
	_close_fds(cmd->red_fd[0], cmd->red_fd[1]);
	return (_helper_fn(cmd, &outfd));
}
