/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_handler.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ochouati <ochouati@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 21:16:57 by ochouati          #+#    #+#             */
/*   Updated: 2024/07/28 16:28:53 by ochouati         ###   ########.fr       */
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

void	exists_and_permissions(t_cmd *cmd)
{
	if (!cmd)
		return ;
}

static void	_child_prs(t_data *data, t_cmd *cmd, t_exec exec) // ! tets this: << l | grep fjbdjksbf
{
	char	**env;

	// signal(SIGINT, SIG_DFL); // ! is going to work in the herdoc
	signal(SIGQUIT, SIG_DFL);
	// ft_printf("child CMD: %s\n", cmd->args[0]);
	// ft_print_strs(cmd->args);
	if (!data || !cmd)
		exit(1);
	ft_printf("-------------------PATH: %s ---CMD: ---->> \n", cmd->path);
	ft_print_strs(cmd->args);
	ft_printf("-------------------PATH: %s ---CMD: ---->> \n", cmd->path);
	if (exec.i != (exec.count - 1))
	{
		if (dup2(exec.fd[1], STDOUT_FILENO) < -1)
		{
			mini_printf(2, "minishell: %s\n", strerror(errno));
			g_status = 1;
			exit(1);
		}
		close(exec.fd[1]);
		close(exec.fd[0]);
	}
	ft_printf("------------------ -  2  ------->> \n", cmd->path);
	if (!cmd->path || !cmd->args)
	{
		if (cmd->args && cmd->args[0])
			mini_printf(2, "minishell: %s: command not found\n", cmd->args[0]); // ! what the else message ?
		g_status = 127;
		exit(127);
	}
	ft_printf("-------------------PATH: %s ------->> \n", cmd->path);
	env = env_lst_to_2dchar(data->env);
	if (execve(cmd->path, cmd->args, env))
	{
		mini_printf(2, "minishell: %s: %s\n", cmd->args[0], strerror(errno));
		g_status = errno;
		ft_free_strs(env);
		exit(errno);
	}
}

void	exec_handler(t_data *data)
{
	t_exec	exec;

	ft_bzero(&exec, sizeof(t_exec));
	if (!data || !data->command)
		return ;
	exec.count = cmd_lstsize(data->command);
	if (exec.count == 1 && data->command->is_builtin)
	{
		s_builtin_handler(data);
		return ;
	}
	// Forking and executing the commands
	__alloc(data, exec.count, &exec.fails);
	if (exec.fails)
		return ;
	exec.i = 0;
	// Handling the forking and executing
	exec.__stdinp = dup(STDIN_FILENO);
	if (exec.__stdinp == -1)
	{
		mini_printf(2, "minishell: %s\n", strerror(errno));
		g_status = 1;
		return ;
	}
	exec.cmd = data->command;
	while (exec.cmd)
	{
		if (pipe(exec.fd) == -1)
		{
			mini_printf(2, "minishell: %s\n", strerror(errno));
			g_status = 1;
			return ;
		}
		data->childs[exec.i] = fork();
		if (data->childs[exec.i] == -1)
		{
			mini_printf(2, "minishell: %s\n", strerror(errno));
			g_status = 1;
			return ;
		}
		else if (!data->childs[exec.i])
			_child_prs(data, exec.cmd, exec);
		if (dup2(exec.fd[0], STDIN_FILENO) < -1)
		{
			mini_printf(2, "minishell: %s\n", strerror(errno));
			g_status = 1;
			return ;
		}
		exec.i++;
		exec.cmd = exec.cmd->next;
		close(exec.fd[0]);
		close(exec.fd[1]);
	}
	// Waiting for the child processes to finish
	exec.i = 0;
	while (exec.i < exec.count)
	{
		if (waitpid(data->childs[exec.i++], &g_status, 0) == -1)
		{
			mini_printf(2, "minishell: %s\n", strerror(errno));
			g_status = 1;
			return ;
		}
		g_status = WEXITSTATUS(g_status);
	}	
	if (dup2(exec.__stdinp, STDIN_FILENO) < -1)
	{
		mini_printf(2, "minishell: %s\n", strerror(errno));
		g_status = 1;
		return ;
	}
	close(exec.__stdinp);
	ft_printf("the status: %d\n", g_status);
}
