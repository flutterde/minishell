/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pwd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ochouati <ochouati@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/28 19:44:59 by mboujama          #+#    #+#             */
/*   Updated: 2024/07/27 13:03:43 by ochouati         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

int	pwd_cmd(void)
{
	char	*dir;

	dir = ft_calloc(2000, 1);
	if (!dir)
	{
		g_status = 1;
		return (mini_printf(2, "Error\n"), -1);
	}
	getcwd(dir, 1999);
	printf("%s\n", dir);
	g_status = 0;
	return (free(dir), dir = NULL, 0);
}
