/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ochouati <ochouati@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/04 16:35:57 by ochouati          #+#    #+#             */
/*   Updated: 2024/08/04 16:43:11 by ochouati         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

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
}

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

void	_child_prs(t_data *data, t_cmd *cmd, t_exec exec)
{
	char	**env;

	signal(SIGINT, SIG_DFL);
	g_status = 0;
	signal(SIGQUIT, SIG_DFL);
	if (!data || !cmd)
		exit(1);
	exec_redirections(data, cmd, exec);
	if (!cmd->args)
		exit(0);
	if (!cmd->is_builtin)
		exists_and_permissions(cmd);
	else
		child_builtin_cmd(data, cmd);
	env = env_lst_to_2dchar(data->env);
	if (execve(cmd->path, cmd->args, env))
	{
		mini_printf(2, "minishell$: %s: %s\n", cmd->args[0], strerror(errno));
		ft_free_strs(env);
		exit(126);
	}
}

void	__err_msg(char *msg, int nbr)
{
	mini_printf(2, "minishell: %s\n", msg);
	g_status = nbr;
}

void	__redirections_wrapper(t_data *data)
{
	t_cmd	*tmp;

	if (!data)
		return ;
	tmp = data->command;
	while (tmp)
	{
		redire_handler(data, tmp->redire, tmp->red_fd);
		tmp = tmp->next;
	}
}
