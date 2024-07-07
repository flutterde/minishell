/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ochouati <ochouati@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 18:53:19 by ochouati          #+#    #+#             */
/*   Updated: 2024/07/07 19:37:30 by ochouati         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

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
