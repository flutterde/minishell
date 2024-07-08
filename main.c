/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ochouati <ochouati@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 20:58:15 by ochouati          #+#    #+#             */
/*   Updated: 2024/07/08 16:04:50 by ochouati         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	leaks(void)
{
	system("leaks minishell");
}

static void	minishell(t_data *data)
{
	char	*line;
	char	*tmp;

	atexit(leaks);
	while (1)
	{
		line = readline(M_NAME);
		if (!ft_strlen(ft_strtrim(line, " ")))
			continue ;
		add_history(line);
		if (ft_strlen(line) > 0
			&& ft_strncmp(line, "exit", ft_strlen(line)) == 0)
		{
			lex_clear_list(&data->lexer);
			ft_printf("Goodbye!\n");
			free(line);
			exit(0);
		}
		else if (!ft_strncmp(line, "cd", 2))
		{
			cd_handler(data->env, line + 3);
		}
		else if (!ft_strncmp(line, "env", ft_strlen(line)))
			_print_env(data->env);
		else if (!ft_strncmp(line, "pwd", ft_strlen(line)))
			pwd_cmd();
		else if (!ft_strncmp(line, "export", ft_strlen(line)))
			ft_export_no_args(data->env);
		else if (!ft_strncmp(line, "$?", 2))
			ft_printf("%d\n", data->last_exit);
		tmp = line;
		line = ft_strtrim(tmp, " ");
		if (!parsing(data, line))
			lex_clear_list(&data->lexer);
		free(tmp);
		free(line);
		lex_clear_list(&data->lexer);
		line = NULL;
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
	return (0);
}
