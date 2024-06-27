/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboujama <mboujama@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 14:12:44 by ochouati          #+#    #+#             */
/*   Updated: 2024/06/27 16:22:05 by mboujama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	_leaks(void)
{
	system("leaks minishell");
}

void	_handler(char **env)
{
	t_env	*head;
	t_env	*tmp;
	char	*line;

	head = NULL;
	tmp = NULL;
	(void)tmp;
	(void)head;
	head = dup_env(env);
	while (1)
	{
		line = readline(M_NAME);
		add_history(line);
		if (ft_strncmp(line, "exit", 4) == 0)
		{
			printf("Goodbye!\n");
			free(line);
			exit(0);
		}
		initial_split_line(line);
		free(line);
		line = NULL;
	}
}

int	main(int ac, char **av, char **env)
{
	atexit(_leaks); //todo: delete this at the end
	(void)ac;
	(void)av;
	_handler(env);
	return (0);
}
