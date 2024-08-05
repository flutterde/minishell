/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_handler.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ochouati <ochouati@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/13 15:02:50 by ochouati          #+#    #+#             */
/*   Updated: 2024/08/02 15:57:15 by ochouati         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

static int	_limit_check(char *str, int *i, size_t nbr, int sign)
{
	if (sign == -1)
		str++;
	if (ft_strlen(str) > 19)
		return (*i = 1, nbr = 255);
	if (nbr > 9223372036854775807 && sign == 1)
		return (*i = 1, nbr = 255);
	if (nbr > 9223372036854775808U && sign == -1)
		return (*i = 1, nbr = 255);
	return (nbr * sign);
}

static int	x__atoi(char *str, int *i)
{
	size_t	nb;
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
	return (_limit_check(str, i, nb, sign));
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
		mini_printf(2, "minishell: exit: %s%s", cmd->args[1], EXIT_ERR);
		exit(255);
	}
	else if (cmd->args[2])
	{
		ft_putstr_fd("minishell: exit: too many arguments\n", 2);
		g_status = 1;
		return ;
	}
	data_cleanup(&data, true);
	exit(st);
}
