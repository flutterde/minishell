/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   built_in.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ochouati <ochouati@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 19:33:13 by ochouati          #+#    #+#             */
/*   Updated: 2024/07/07 19:00:46 by ochouati         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "head.h"
#include <errno.h>
#include <string.h>

int	pwd_cmd(void)
{
	char	*dir;

	dir = ft_calloc(2000, 1);
	if (!dir)
		return (mini_printf(2, "Error\n"), -1);
	getcwd(dir, 1999);
	printf("%s\n", dir);
	return (free(dir), dir = NULL, 0);
}

// char	*cd_cmd(char *arg)
// {
// 	char	*dir;
// 	char	*home;
// 	char	*new;

// 	dir = ft_calloc(2000, sizeof(char));
// 	if (!dir)
// 		return (mini_printf(2, "Error can't allocate\n"), NULL);
// 	getcwd(dir, 1999);
// 	if (!ft_strlen(arg))
// 	{
// 		home = getenv("HOME");
// 		//chdir(home); // ! handle error
// 		if (chdir(home) == -1)
// 			return (mini_printf(2, "Error: %s\n", strerror(errno)), NULL);
// 		getcwd(dir, 1999);
// 		printf("the PWD>: %s\n", dir);
// 		return (new = ft_strdup(dir), free(dir), new);
// 	}
// 	chdir(arg); // ! handle error
// 	getcwd(dir, 1999);
// 	printf("the PWD: %s\n", dir);
// 	return (new = ft_strdup(dir), free(dir), new);
// }

char	*ft_cd(char *arg)
{
	char	*dir;
	char	*home;
	char	*new;

	dir = ft_calloc(2000, sizeof(char));
	if (!dir)
		return (mini_printf(2, "Error\n"), NULL);
	getcwd(dir, 1999);
	if (!ft_strlen(arg) || !ft_strcmp(arg, "~"))
	{
		home = getenv("HOME");
		if (chdir(home) == -1)
			return (free(dir), mini_printf(2, "Error: %s\n",
				strerror(errno)), NULL);
		getcwd(dir, 1999);
		return (new = ft_strdup(dir), free(dir), new);
	}
	else if (chdir(arg) == -1)
		return (mini_printf(2, "Error: cd: %s: %s\n", arg,
			strerror(errno)), free(dir), NULL);
	getcwd(dir, 1999);
	return (new = ft_strdup(dir), free(dir), new);
}

void	_handler(char *s1, char *s2)
{
	ft_printf("--=>> -------(s1 = %s)-----(s2 = %s)-----------\n", s1, s2);
	char *n1 = ft_cd("/root");
	ft_printf("n1 = %s\n", n1);
	char *n2 = ft_cd("/dev");
	ft_printf("n2 = %s\n", n2);

	free(n1);
	free(n2);
	ft_printf("-----------------------\n");
	pwd_cmd();
}


int	main(int ac, char **av)
{
	(void)ac;
	_handler(av[1], av[0]);
	pwd_cmd();
	system("leaks a.out");
	return (0);
}
