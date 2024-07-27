/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ochouati <ochouati@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 18:10:01 by ochouati          #+#    #+#             */
/*   Updated: 2024/07/25 19:11:52 by ochouati         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

int	unset_handler(t_cmd *cmd, t_data *data)
{
	int	i;

	i = 1;
	while (cmd && cmd->args && cmd->args[i])
	{
		removeif_env(&data->env, cmd->args[i]);
		i++;
	}
	return (0);
}
