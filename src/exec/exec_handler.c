/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_handler.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ochouati <ochouati@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 21:16:57 by ochouati          #+#    #+#             */
/*   Updated: 2024/08/04 19:07:33 by ochouati         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

static void	__alloc(t_data *data, int size, int *fails)
{
	if (!data || size <= 0 || !fails)
		return ;
	data->childs = ft_calloc(size, sizeof(pid_t));
	if (!data->childs)
	{
		mini_printf(2, "minishell: %s\n", strerror(errno));
		g_status = 1;
		*fails = 1;
	}
}

int	_prepare_fn(t_data *data, t_exec *exec)
{
	if (!data)
		return (exec->fails = 1, 0);
	ft_bzero(exec, sizeof(t_exec));
	if (!data->command)
		return (exec->fails = 1, 0);
	exec->count = cmd_lstsize(data->command);
	if (exec->count == 1 && data->command->is_builtin)
		return (s_builtin_handler(data), exec->fails = 1, 1);
	__redirections_wrapper(data);
	if (data->sigint == -1)
		return (exec->fails = 1, 0);
	__alloc(data, exec->count, &exec->fails);
	return (1);
}

int	__executor(t_data *data, t_exec *exec)
{
	if (pipe(exec->fd) == -1)
		return (__err_msg(strerror(errno), 1), -1);
	data->childs[exec->i] = fork();
	if (data->childs[exec->i] == -1)
		return (__err_msg(strerror(errno), 1), -1);
	else if (!data->childs[exec->i])
		_child_prs(data, exec->cmd, *exec);
	if (dup2(exec->fd[0], STDIN_FILENO) < 0)
		return (__err_msg(strerror(errno), 1), -1);
	exec->i++;
	_close_fds(exec->cmd->red_fd[0], exec->cmd->red_fd[1]);
	close(exec->fd[0]);
	close(exec->fd[1]);
	exec->cmd = exec->cmd->next;
	return (1);
}

void	__waitchilds(t_data *data, t_exec *exec)
{
	close(exec->fd_stdin);
	exec->i = 0;
	while (exec->i < exec->count)
	{
		if (waitpid(data->childs[exec->i++], &g_status, 0) == -1)
			return (__err_msg(strerror(errno), 1));
		if (WIFSIGNALED(g_status))
			g_status = WTERMSIG(g_status) + 128;
		else if (WIFEXITED(g_status))
			g_status = WEXITSTATUS(g_status);
	}
	signal(SIGINT, handle_sigint);
}

void	exec_handler(t_data *data)
{
	t_exec	exec;

	_prepare_fn(data, &exec);
	if (exec.fails)
		return ;
	exec.fd_stdin = dup(STDIN_FILENO);
	if (exec.fd_stdin == -1)
		return (__err_msg(strerror(errno), 1));
	exec.cmd = data->command;
	signal(SIGINT, SIG_IGN);
	while (exec.cmd)
	{
		if (__executor(data, &exec) < 0)
			return ;
	}
	if (dup2(exec.fd_stdin, STDIN_FILENO) < -1)
		return (close(exec.fd_stdin), __err_msg(strerror(errno), 1));
	__waitchilds(data, &exec);
}
