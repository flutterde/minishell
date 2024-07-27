/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_handler.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboujama <mboujama@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/13 15:02:50 by ochouati          #+#    #+#             */
/*   Updated: 2024/07/27 15:28:28 by mboujama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

static int	x__atoi(char *str, int *i)
{
	int		nb;
	int		j;
	int		sign;

	nb = 0;
	j = 0;
	sign = 1;
	if (!str)
		return (nb = g_status);
	if (str[j] == '-' || str[j] == '+')
	{
		if (str[j] == '-')
			sign = -1;
		j++;
	}
	while (str[j] && ft_isdigit(str[j]))
		nb = (nb * 10) + str[j++] - '0';
	if (str[j])
		return (*i = 1, nb = 255);
	return (nb * sign);
}

void	exit_handler(t_data *data, t_cmd *cmd)
{
	int		st;
	int		i;

	if (!data || !cmd || !cmd->args || !cmd->args[0])
		return ;
	if (!cmd->args[1])
	{
		data_cleanup(&data, true);
		exit(g_status);
	}
	i = 0;
	st = x__atoi(cmd->args[1], &i);
	if (i)
	{
		mini_printf(2, "minishell: exit: %s: numeric argument required\n",
			cmd->args[1]);
		exit(255);
	}
	else if (cmd->args[2])
	{
		ft_putstr_fd("minishell: exit: too many arguments\n", 2);
		return ;
	}
	data_cleanup(&data, true);
	exit(st);
}
