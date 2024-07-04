/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pwd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ochouati <ochouati@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/28 19:44:59 by mboujama          #+#    #+#             */
/*   Updated: 2024/07/04 14:33:44 by ochouati         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

// int	ft_pwd(t_env *env)
// {
// 	t_env	*pwd;

// 	if (!env)
// 		return (0);
// 	pwd = search_env(env, "PWD");
// 	printf("%s\n", pwd->value);
// 	return (1);
// }

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
