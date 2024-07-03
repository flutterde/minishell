/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   built_in.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ochouati <ochouati@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 19:33:13 by ochouati          #+#    #+#             */
/*   Updated: 2024/07/03 19:56:56 by ochouati         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "head.h"

void	cd_cmd(char *arg)
{
	char	*dir;

	dir = ft_calloc(2000, sizeof(char));
	if (!dir)
	{
		mini_printf(2, "malloc failed\n");
		return ;
	}
	getcwd(dir, 1000);
	printf("the Path: %s\n", dir);
	// if no argument is passed, we will go to the home directory.
	if (!ft_strlen(arg))
	{
		chdir(getenv("HOME"));
		getcwd(dir, 1000);
		printf("the Path: %s\n", dir);
		return ;
	}
	chdir(arg);
	getcwd(dir, 1000);
	printf("the Path: %s\n", dir);
}


int	main(void)
{
	cd_cmd(NULL);
	printf("the USER: %s\n", getenv("USER"));
	return (0);
}
