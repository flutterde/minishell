/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_handler.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ochouati <ochouati@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 21:16:57 by ochouati          #+#    #+#             */
/*   Updated: 2024/07/27 17:18:11 by ochouati         ###   ########.fr       */
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

static void	_child_prs(t_data *data, t_cmd *cmd)
{
	char	**env;

	if (!data || !cmd)
		return ;
	if (!cmd->path)
	{
		mini_printf(2, "minishell: %s: command not found\n", cmd->args[0]);
		g_status = 127;
		exit(127);
		return ;
	}
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
	int		i;

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
	// Handling the forking and executing
	i = 0;
	data->childs[i] = fork();
	if (data->childs[i] == -1)
	{
		mini_printf(2, "minishell: %s\n", strerror(errno));
		g_status = 1;
		return ;
	}
	if (data->childs[i] == 0)
		_child_prs(data, data->command);
	waitpid(data->childs[i], &g_status, 0);
	g_status = WEXITSTATUS(g_status);
	ft_printf("the status: %d\n", g_status);
}
