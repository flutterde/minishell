/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_execve.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ochouati <ochouati@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 16:47:13 by ochouati          #+#    #+#             */
/*   Updated: 2024/07/09 17:00:53 by ochouati         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "head.h"

void	handler(char *cmd1, char *cmd2, char *path, char **env)
{
	int	status;

	char	*args[3] = {cmd1, cmd2, NULL};
	int pid = fork();
	if (!pid)
	{
		if (execve(path, args, env))
		{
			printf("Eroor: %s.\n", strerror(errno));
			exit(errno);
		}
	}
	else
		waitpid(pid, &status, 0);
}

int	main(int ac, char **av, char **env)
{
	if (ac != 4)
		return (1);
	handler(av[1], av[2], av[3], env);
	return (0);
}

