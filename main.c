/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboujama <mboujama@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 20:58:15 by ochouati          #+#    #+#             */
/*   Updated: 2024/07/23 08:38:20 by mboujama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	leaks(void)
{
	system("leaks minishell");
}

void	export___(t_data *data, char *str)
{
	char	**split;

	split = ft_split(str, ' ');
	if (!split || !split[0])
		return ;
	if (split[0] && !split[1])
	{
		ft_export_no_args(data->env);
		ft_free_strs(split);
		return ;
	}
	ft_export(&data->env, split[1]);
	ft_free_strs(split);
}

static void	minishell(t_data *data)
{
	char	*line;
	char	*trimmed_line;

	atexit(leaks);
	while (1)
	{
		line = readline(M_NAME);
		trimmed_line = ft_strtrim(line, " ");
		free(line);
		if (!ft_strlen(trimmed_line))
		{
			free(trimmed_line);
			continue ;
		}
		add_history(trimmed_line);
		if (ft_strlen(trimmed_line) > 0
			&& ft_strncmp(trimmed_line, "exit", ft_strlen(trimmed_line)) == 0)
		{
			free(trimmed_line);
			break ;
		}
		else if (!ft_strncmp(line, "cd", 2))
			cd_handler(data->env, trimmed_line + 3);
		else if (!ft_strncmp(trimmed_line, "env", ft_strlen(trimmed_line)))
			_print_env(data->env);
		else if (!ft_strncmp(trimmed_line, "pwd", ft_strlen(trimmed_line)))
			pwd_cmd();
		else if (!ft_strncmp(trimmed_line, "export", 6))
			export___(data, trimmed_line);
		// else if (!ft_strncmp(trimmed_line, "$?", 2))
		// 	ft_printf("%d\n", data->last_exit);
		// else
		// 	execve_handler(data, trimmed_line);
		if (!parsing(data, trimmed_line))
			lex_clear_list(&data->lexer);
		print_linked_list(data->command);
		free(trimmed_line);
		lex_clear_list(&data->lexer);
	}
}

int	main(int ac, char **av, char **env)
{
	t_data	*data;

	(void)ac;
	(void)av;
	data = ft_calloc(1, sizeof(t_data));
	if (!data)
		return (1);
	data->env = dup_env(env);
	minishell(data);
	clear_data(&data);
	return (0);
}
