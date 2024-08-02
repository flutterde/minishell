/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_handler.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ochouati <ochouati@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 21:16:57 by ochouati          #+#    #+#             */
/*   Updated: 2024/08/02 10:41:45 by ochouati         ###   ########.fr       */
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
	if (!cmd->path)
	{
		if (cmd->args && cmd->args[0])
			mini_printf(2, "minishell: %s: command not found\n", cmd->args[0]);
		exit(127);
	}
	if (access(cmd->path, X_OK) == -1)
	{
		mini_printf(2, "minishell: %s: %s\n", cmd->args[0], "Permission denied");
		g_status = 126;
		exit(126);
	}
	// ft_printf("\033[0;91mthe path: %s, the Command: %s.\033[0m\n", cmd->path, cmd->args[0]);
}

// ! merge this with the builtin handler
void	child_builtin_cmd(t_data *data, t_cmd *cmd)
{
	char	**args;

	if (!data || !cmd)
		exit(1);
	args = cmd->args;
	if (args && !ft_strcmp(args[0], "echo"))
		return (ft_echo(cmd, data), exit(g_status));
	else if (args && !ft_strcmp(args[0], "pwd"))
		return (pwd_cmd(), exit(g_status));
	else if (args && !ft_strcmp(args[0], "cd"))
		return (cd_handler(data->env, args[1]), exit(g_status));
	else if (args && !ft_strcmp(args[0], "export"))
		return (export_handler(cmd, data), exit(g_status));
	else if (args && !ft_strcmp(args[0], "unset"))
		return (unset_handler(cmd, data), exit(g_status));
	else if (args && !ft_strcmp(args[0], "env"))
		return (_print_env(data->env), exit(g_status));
	else if (args && !ft_strcmp(args[0], "exit"))
		return (exit_handler(data, cmd), exit(g_status));
}

void	print__lst(t_redir *lst)
{
	char	*type;

	while (lst)
	{
		if (lst->type == HEREDOC)
			type = ft_strdup("HEREDOC");
		else if (lst->type == REDIR_IN)
			type = ft_strdup("REDIR");
		else if (lst->type == APPEND)
			type = ft_strdup("APPEND");
		else if (lst->type == REDIR_OUT)
			type = ft_strdup("REDIR_OUT");
		ft_printf("type: %s, file: %s, delim: %s, index: %d, isLast?: %d.\
			\n", type, lst->file, lst->delim, lst->index, lst->is_last);
		lst = lst->next;
	}
}

// TODO: tets this: << l | grep fjbdjksbf
static void	_child_prs(t_data *data, t_cmd *cmd, t_exec exec) 
{
	char	**env;

	// signal(SIGINT, SIG_DFL); // ! is going to work in the herdoc
	g_status = 0;
	signal(SIGQUIT, SIG_DFL);
	if (!data || !cmd)
		exit(1);
	// redirecting
	exec_redirections(data, cmd, exec);
	// if no args
	if (!cmd->args)
		exit(0);
	if (!cmd->is_builtin)
		exists_and_permissions(cmd); // TODO: if the command does not exist or the permissions are not granted
	else
		child_builtin_cmd(data, cmd);
	env = env_lst_to_2dchar(data->env);
	if (execve(cmd->path, cmd->args, env))
	{
		mini_printf(2, "minishell$: %s: %s\n", cmd->args[0], strerror(errno));
		// g_status = errno;
		ft_free_strs(env);
		exit(126);
	}
}

void	__err_msg(char *msg, int nbr)
{
	mini_printf(2, "minishell: %s\n", msg);
	g_status = nbr;
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
	exec.fd_stdin = dup(STDIN_FILENO);
	if (exec.fd_stdin == -1)
		return __err_msg(strerror(errno), 1);
	exec.cmd = data->command;
	while (exec.cmd)
	{
		if (pipe(exec.fd) == -1)
			return __err_msg(strerror(errno), 1);
		data->childs[exec.i] = fork();
		if (data->childs[exec.i] == -1)
			return __err_msg(strerror(errno), 1);
		else if (!data->childs[exec.i])
			_child_prs(data, exec.cmd, exec);
		if (dup2(exec.fd[0], STDIN_FILENO) < 0)
			return __err_msg(strerror(errno), 1);
		exec.i++;
		close(exec.fd[0]);
		close(exec.fd[1]);	
		exec.cmd = exec.cmd->next;
	}
	if (dup2(exec.fd_stdin, STDIN_FILENO) < -1)
		return __err_msg(strerror(errno), 1);
	// Waiting for the child processes to finish
	exec.i = 0;
	while (exec.i < exec.count)
	{
		if (waitpid(data->childs[exec.i++], &g_status, 0) == -1)
			return __err_msg(strerror(errno), 1);
		if (WIFSIGNALED(g_status))
			g_status = WTERMSIG(g_status) + 128;
		else if (WIFEXITED(g_status))
			g_status = WEXITSTATUS(g_status);
	}	
	close(exec.fd_stdin);
	// ft_printf("\033[0;91mthe status: %d\033[0m\n", g_status);
}
