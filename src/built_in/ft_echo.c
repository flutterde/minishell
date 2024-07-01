/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ochouati <ochouati@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 19:26:31 by ochouati          #+#    #+#             */
/*   Updated: 2024/07/01 16:47:37 by ochouati         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

int	ft_echo(t_cmd *cmd, char *str)
{
	if (!cmd || !str)
		return (0);
	if (cmd->args && cmd->args[0] && cmd->args[1]
		&& !ft_strncmp(cmd->args[1], "git -n", ft_strlen(cmd->args[1])))
		return (printf("%s\n", str), 1);
	return (printf("%s", str), 2);
}
