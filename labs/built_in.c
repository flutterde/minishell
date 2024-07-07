/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   built_in.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboujama <mboujama@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 19:33:13 by ochouati          #+#    #+#             */
/*   Updated: 2024/07/07 15:41:15 by mboujama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "head.h"

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

char	*cd_cmd(char *arg)
{
	char	*dir;
	char	*home;
	char	*new;

	dir = ft_calloc(2000, sizeof(char));
	if (!dir)
		return (mini_printf(2, "Error\n"), NULL);
	getcwd(dir, 1999);
	if (!ft_strlen(arg))
	{
		home = getenv("HOME");
		chdir(home); // ! handle error
		getcwd(dir, 1999);
		return (new = ft_strdup(dir), free(dir), new);
	}
	chdir(arg); // ! handle error
	getcwd(dir, 1999);
	return (new = ft_strdup(dir), free(dir), new);
}

void	_handler(char *s1, char *s2)
{
	ft_printf("-----------------------\n");
	char *n1 = cd_cmd(s1);
	ft_printf("the path 1 :: %s\n", n1);
	char *n2 = cd_cmd(s2);
	ft_printf("the path 2 :: %s\n", n2);
	// ft_print_strs(av);
	free(n1);
	free(n2);
	ft_printf("-----------------------\n");
	pwd_cmd();
}


int	main(int ac, char **av)
{
	(void)ac;
	_handler(av[1], av[2]);
	// system("leaks a.out");
	return (0);
}
