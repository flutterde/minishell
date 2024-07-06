/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboujama <mboujama@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 16:46:11 by ochouati          #+#    #+#             */
/*   Updated: 2024/07/06 13:41:31 by mboujama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

void	ft_init(int ac, char **av, char **env, t_env *envs)
{
	(void)av;
	(void)envs;

	if (ac != 1)
		ft_exit("Don't run it with Args!", 1, 2);
	if (!env)
		ft_exit("Env Required!", 1, 2);
	// envs->env = dup2dchar(env);
}
