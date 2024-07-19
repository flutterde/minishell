/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   piping.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ochouati <ochouati@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 19:41:24 by ochouati          #+#    #+#             */
/*   Updated: 2024/07/18 09:50:49 by ochouati         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	free_int_arrs(int **arr, int i)
{
	int	j;

	if (!arr)
		return ;
	j = 0;
	while (j < i)
		free(arr[j++]);
	free(arr);
}

// void	__dup(int **pips, int i)
// {
// 	int	j = 0;

// 	j = 0;
// 	while (j < i)
// 	{
// 		dup2()
// 	}

// }


void	_child_handler(int i, int nbr, char **cmd, char **env, int *fd)
{
	printf("Child ======> %d. CMD: %s\n", i, cmd[0]);
	(void)i;
	if (i != nbr - 1)
	{
		dup2(fd[1], STDOUT_FILENO);
		close(fd[0]);
		close(fd[1]);
		//close(STDOUT_FILENO);
	}
	
	
	if (execve(cmd[0], cmd, env))
	{
		printf("Error: ");
		perror(strerror(errno));
		exit(errno);
	}
	exit(0);
}

void	ft_piping(int nbr, char **cmd1, char **cmd2, char **env, char **cmd3)
{
	int		fd[2];
	int		i;
	char	**cc[4] = {cmd1, cmd2, cmd3, NULL};
	int		k;
	int		child;
	int		status;

	(void)env;
	(void)cmd1;
	(void)cmd2;
	i = 0;
	while (i < nbr)
	{
		k = pipe(fd);
		if (k < 0)
		{
			printf("Can't pipe.\n");
			exit(123);
		}
		child = fork();
		if (!child)
			_child_handler(i, nbr, cc[i], env, fd);
		dup2(fd[0], STDIN_FILENO);
		close(fd[1]);
		close(fd[0]);
		i++;
	}
	i = 0;
	waitpid(-1, &status, 0);
	waitpid(-1, &status, 0);
	waitpid(-1, &status, 0);
	printf("DONE\n");
}

int	main(int ac, char **av, char **env)
{
	char	**cmd1;
	char	**cmd2;
	char	**cmd3;

	if (ac < 4)
		return (printf("Error, Should be 4.\n"));
	cmd1 = ft_split(av[2], ' ');
	// printf("----- > 1\n");
	cmd2 = ft_split(av[3], ' ');
	cmd3 = ft_split(av[4], ' ');
	// printf("----- > 2\n");
	ft_piping(atoi(av[1]), cmd1, cmd2, env, cmd3);
	// system("leaks piping");
	while (1)
		;
	
}
