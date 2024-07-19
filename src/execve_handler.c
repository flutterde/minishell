/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execve_handler.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ochouati <ochouati@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 19:05:57 by ochouati          #+#    #+#             */
/*   Updated: 2024/07/19 10:15:52 by ochouati         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static void	__handler(t_data *data, char **args, char *path)
{
	char	**env;

	env = env_lst_to_2dchar(data->env);
	if (execve(path, args, env))
		perror("Error:");
	printf("the Errno: %d.\n", errno);
	ft_free_strs(env);
	exit(errno);
}

int	execve_handler(t_data *data, char *prompt)
{
	char	*cmd;
	pid_t	pid;
	char	**args;
	char	*path;

	cmd = ft_first_word(prompt);
	if (!cmd)
		return (-1);
	path = get_absolute_path(cmd, data->env);
	if (!path)
	{
		mini_printf(2, "Error: %s: Command not found\n", cmd);
		return (ft_free((void **)(&cmd)), -1);
	}
	ft_printf("the path: %s.\n", path);
	args = ft_split(prompt, ' ');
	if (!args)
		return (-1);
	pid = fork();
	if (!pid)
		__handler(data, args, path);
	else
		waitpid(pid, &data->last_exit, 0);
	return (free(cmd), ft_free_strs(args), free(path), 1);
}
