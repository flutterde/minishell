/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ochouati <ochouati@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 16:46:11 by ochouati          #+#    #+#             */
/*   Updated: 2024/06/11 19:23:10 by ochouati         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

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
