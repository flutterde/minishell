/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pwd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboujama <mboujama@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/28 19:44:59 by mboujama          #+#    #+#             */
/*   Updated: 2024/06/28 19:56:51 by mboujama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

int	ft_pwd(t_env *env)
{
	t_env	*pwd;

	if (!env)
		return (0);
	pwd = search_env(env, "PWD");
	printf("%s\n", pwd->value);
	return (1);
}
