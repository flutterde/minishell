/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   out_handler.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboujama <mboujama@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 11:29:11 by mboujama          #+#    #+#             */
/*   Updated: 2024/07/31 15:42:31 by mboujama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

static int	open_close_file(t_redir *red)
{
	int	fd;

	fd = open(red->file, O_CREAT | O_RDWR, 0644);
	if (fd < 0)
		return (0);
	close(fd);
	return (1);
}

static int	file_red_out(t_redir *red)
{
	int	fd;

	if (red->type == REDIR_OUT)
		fd = open(red->file, O_CREAT | O_TRUNC | O_RDWR, 0644);
	else
		fd = open(red->file, O_CREAT | O_APPEND | O_RDWR, 0644);
	if (fd < 0)
		return (M_FAIL);
	ft_printf("FD ==> %d\n", fd);
	return (fd);
}

int	out_handler(t_redir *red)
{
	if (!red)
		return (0);
	if (!red->is_last)
	{
		printf("NOT_LAST\n");
		if (!open_close_file(red))
			return (M_FAIL);
		return (M_IGNORE);
	}
	else
	{
		printf("LAST\n");
		return (file_red_out(red));
	}
}
