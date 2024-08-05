/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_builtin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ochouati <ochouati@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 11:10:15 by mboujama          #+#    #+#             */
/*   Updated: 2024/07/24 14:26:28 by ochouati         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

int	is_builtin(char *cmd)
{
	if (!cmd)
		return (0);
	if (!ft_strcmp("cd", cmd))
		return (1);
	else if (!ft_strcmp("export", cmd))
		return (1);
	else if (!ft_strcmp("unset", cmd))
		return (1);
	else if (!ft_strcmp("pwd", cmd))
		return (1);
	else if (!ft_strcmp("env", cmd))
		return (1);
	else if (!ft_strcmp("echo", cmd))
		return (1);
	else if (!ft_strcmp("exit", cmd))
		return (1);
	return (0);
}
