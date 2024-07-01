/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ochouati <ochouati@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 20:58:15 by ochouati          #+#    #+#             */
/*   Updated: 2024/07/01 15:01:52 by ochouati         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	_leaks(void)
{
	system("leaks minishell");
}

void	__handler_helper(t_env *env, char **line)
{
	(void)env;

	char **sts = initial_split_line(*line);
	ft_print_strs(sts);
	ft_free_strs(sts);
	free(*line);
	*line = NULL;
}



void	_handler(char **env)
{
	t_env	*head;
	char	*line;
	// t_cmd	*cmd;

	head = NULL;
	head = dup_env(env);
	while (1)
	{
		line = readline(M_NAME);
		if (!ft_strlen(line))
			continue ;
		add_history(line);
		if (ft_strncmp(line, "exit", ft_strlen(line)) == 0)
		{
			ft_printf("Gooooooooodbye!\n");
			exit(0);
		}
		if (ft_strncmp(line, "env", ft_strlen(line)) == 0)
			_print_env(head);
		else if (ft_strncmp(line, "pwd", ft_strlen(line)) == 0)
			ft_pwd(head);
		__handler_helper(head, &line);
	}
}


int	main(int ac, char **av, char **env)
{
	//atexit(_leaks); //todo: delete this at the end

	(void)ac;
	(void)av;
	_handler(env);
	return (0);
}
