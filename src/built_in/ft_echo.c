/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboujama <mboujama@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 19:26:31 by ochouati          #+#    #+#             */
/*   Updated: 2024/06/28 20:42:44 by mboujama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

static int	__expand(t_env *lst, char *str)
{
	int	i;

	i = 0;
	(void)lst;
	(void)str;
	(void)i;
	return (1);
}

static int	__no_expand(t_env *lst, char *str)
{
	(void)lst;
	(void)str;
	return (1);
}

int	ft_echo(t_env *lst, char *str, bool expand)
{
	if (!lst || !str)
		return (0);
	if (expand)
		return (__expand(lst, str));
	return (__no_expand(lst, str));
}
