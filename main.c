/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboujama <mboujama@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 20:58:15 by ochouati          #+#    #+#             */
/*   Updated: 2024/07/24 16:00:40 by mboujama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	test_sort(void)
{
	t_redir	*lst;
	t_redir	*tmp;
	char	*str;

	lst = NULL;
	red_lstadd_back(&lst, red_create(REDIR_IN, "file1", NULL, false, false));
	red_lstadd_back(&lst, red_create(HEREDOC, NULL, "delim2", false, false));
	red_lstadd_back(&lst, red_create(REDIR_OUT, "file3", NULL, false, false));
	red_lstadd_back(&lst, red_create(HEREDOC, NULL, "delim4", false, false));
	red_lstadd_back(&lst, red_create(DREDIR_OUT, "file5", NULL, false, false));
	red_lstadd_back(&lst, red_create(REDIR_IN, "file6", NULL, false, false));
	red_lstadd_back(&lst, red_create(HEREDOC, NULL, "delim7", false, false));
	red_lstadd_back(&lst, red_create(SUPER_HEREDOC, NULL, "delim8", false, false));
	tmp = lst;
	while (tmp)
	{
		if (tmp->type == HEREDOC)
			str = "HEREDOC";
		else if (tmp->type == SUPER_HEREDOC)
			str = "SUPER_HEREDOC";
		else if (tmp->type == REDIR_IN)
			str = "REDIR_IN";
		else if (tmp->type == REDIR_OUT)
			str = "REDIR_OUT";
		else
			str = "DREDIR_OUT";
		printf("type: %s, file: %s, delim: %s, expand: %d, amb: %d, index: %d\n",
			str, tmp->file, tmp->delim, tmp->to_expand, tmp->is_ambiguous, tmp->index);
		tmp = tmp->next;
	}
	tmp = lst;
	red_sort(lst);
	ft_printf("\nAFTER______SORTING\n");
	while (tmp)
	{
		if (tmp->type == HEREDOC)
			str = "HEREDOC";
		else if (tmp->type == SUPER_HEREDOC)
			str = "SUPER_HEREDOC";
		else if (tmp->type == REDIR_IN)
			str = "REDIR_IN";
		else if (tmp->type == REDIR_OUT)
			str = "REDIR_OUT";
		else
			str = "DREDIR_OUT";
		printf("type: %s, file: %s, delim: %s, expand: %d, amb: %d, index: %d\n",
			str, tmp->file, tmp->delim, tmp->to_expand, tmp->is_ambiguous, tmp->index);
		tmp = tmp->next;
	}
}

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

void	handle_sigint(int sig)
{
	(void)sig;
	if (sig == SIGINT)
	{
		ft_printf("\n");
		rl_on_new_line();
		rl_replace_line("", 0);
		rl_redisplay();
	}
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
		else if (!ft_strncmp(trimmed_line, "tttt", 4))
			test_sort();
		else if (!ft_strncmp(trimmed_line, "cd", 2))
			cd_handler(data->env, trimmed_line + 3);
		else if (!ft_strncmp(trimmed_line, "env", ft_strlen(trimmed_line)))
			_print_env(data->env);
		else if (!ft_strncmp(trimmed_line, "pwd", ft_strlen(trimmed_line)))
			pwd_cmd();
		else if (!ft_strncmp(trimmed_line, "export", 6))
			export___(data, trimmed_line);
		if (!parsing(data, trimmed_line))
			lex_clear_list(&data->lexer);
		print_linked_list(data->command);
		free(trimmed_line);
		lex_clear_list(&data->lexer);
		data->lexer = NULL;
		cmd_clear(&data->command);
		data->command = NULL;
	}
}

int	main(int ac, char **av, char **env)
{
	t_data	*data;

	(void)ac;
	(void)av;
	signal(SIGINT, handle_sigint);
	signal(SIGQUIT, SIG_IGN);
	data = ft_calloc(1, sizeof(t_data));
	if (!data)
		return (1);
	data->env = dup_env(env);
	minishell(data);
	clear_data(&data);
	return (0);
}
