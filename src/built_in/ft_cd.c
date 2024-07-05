/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ochouati <ochouati@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 18:53:19 by ochouati          #+#    #+#             */
/*   Updated: 2024/07/04 19:42:06 by ochouati         ###   ########.fr       */
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
	if (!ft_strlen(arg))
	{
		home = getenv("HOME");
		if (chdir(home))
			return (ft_errno(errno), NULL);
		getcwd(dir, 1999);
		return (new = ft_strdup(dir), free(dir), new);
	}
	if (chdir(home))
		return (ft_errno(errno), NULL);
	getcwd(dir, 1999);
	return (new = ft_strdup(dir), free(dir), new);
}
