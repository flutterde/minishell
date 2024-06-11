/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ochouati <ochouati@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 17:35:05 by ochouati          #+#    #+#             */
/*   Updated: 2024/06/11 17:39:40 by ochouati         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	ft_exit(char *msg, int status, int fd)
{
	ft_putendl_fd(msg, fd);
	exit(status);
}
