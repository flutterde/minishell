/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ochouati <ochouati@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 14:12:44 by ochouati          #+#    #+#             */
/*   Updated: 2024/06/27 13:09:21 by ochouati         ###   ########.fr       */
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
		// add_history(line);
		if (ft_strncmp(line, "exit", 4) == 0)
		{
			printf("Goodbye!\n");
			free(line);
			exit(0);
		}
		printf("%s\n", line);
		free(line);
		line = NULL;
	}
}

int	main(int ac, char **av, char **env)
{
	// printf("%d\n", );
	// atexit(_leaks); // delete this at the end
	(void)ac;
	(void)av;
	_handler(env);
	return (0);
}
