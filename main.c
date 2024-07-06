/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboujama <mboujama@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 20:58:15 by ochouati          #+#    #+#             */
/*   Updated: 2024/07/04 19:45:08 by mboujama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	minishell(t_data *data)
{
	char	*line;
	// char	*parsed;
	// char	**splitted;
	t_lex	*lex;

	(void)data;
	while (1)
	{
		line = readline(M_NAME);
		if (!ft_strlen(line))
			continue ;
		add_history(line);
		if (ft_strlen(line) > 0
			&& ft_strncmp(line, "exit", ft_strlen(line)) == 0)
		{
			ft_printf("Goodbye!\n");
			free(line);
			exit(0);
		}
		else if (ft_strncmp(line, "env", ft_strlen(line)) == 0)
			_print_env(data->env);
		else if (ft_strncmp(line, "pwd", ft_strlen(line)) == 0)
			pwd_cmd();
		else if (ft_strncmp(line, "export", ft_strlen(line)) == 0)
			ft_export_no_args(data->env);
		lex = create_lexer(line);
		while (lex)
		{
			printf("==> |	%s	|	%d	|	%d	|\n", lex->string, lex->state, lex->len);
			lex = (lex)->next;
		}
		// splitted = initial_split_line(line);
		
		// parsed = parse_quote(data, line);
		// ft_printf("[%s]\n", parsed);
		// ft_export_no_args(head);
		// ft_print_strs(splitted);
		// ft_free_strs(splitted);
		free(line);
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
