/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboujama <mboujama@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 20:58:15 by ochouati          #+#    #+#             */
/*   Updated: 2024/06/28 20:38:03 by mboujama         ###   ########.fr       */
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
		if (ft_strncmp(line, "exit", ft_strlen(line)) == 0)
		{
			printf("Goodbye!\n");
			free(line);
			exit(0);
		}
		else if (ft_strncmp(line, "env", ft_strlen(line)) == 0)
			_print_env(head);
		else if (ft_strncmp(line, "pwd", ft_strlen(line)) == 0)
			ft_pwd(head);
		char **sts = initial_split_line(line);
		// ft_print_strs(sts);
		ft_free_strs(sts);
		free(line);
		line = NULL;
	}
}

int	main(int ac, char **av, char **env)
{
	// printf("%d\n", );
	// atexit(_leaks); // delete this at the end
	atexit(_leaks); //todo: delete this at the end
	(void)ac;
	(void)av;
	_handler(env);
	return (0);
}
