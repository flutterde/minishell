/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirections_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ochouati <ochouati@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/04 15:21:34 by ochouati          #+#    #+#             */
/*   Updated: 2024/08/04 16:00:57 by ochouati         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

int	__out_handler_copy(t_redir *redire, int *redfd)
{
	int	fd;

	if (redire->is_ambiguous)
		return (g_status = 1, *redfd = -1, -1);
	if (redire->type == REDIR_OUT)
	{
		fd = open(redire->file, O_WRONLY | O_CREAT | O_TRUNC, 0644);
		if (fd == -1)
			return (*redfd = -1, g_status = 1, -1);
	}
	else
	{
		fd = open(redire->file, O_WRONLY | O_CREAT | O_APPEND, 0644);
		if (fd == -1)
			return (*redfd = -1, g_status = 1, -1);
	}
	if (redire->is_last)
		return (*redfd = fd, fd);
	return (close(fd), fd);
}

int	_open_in_copy(t_redir *node, int *redfd)
{
	int	fd;

	if (node->type == HEREDOC)
		fd = open(node->path, O_RDONLY);
	else
		fd = open(node->file, O_RDONLY);
	if (fd == -1)
		return (g_status = 1, *redfd = -1, -1);
	if (node->is_last)
		return (*redfd = fd, fd);
	return (close(fd), fd);
}

void	_reopen_fds(t_redir *node, int *fds)
{
	t_redir	*tmp;
	int		in;
	int		out;

	if (!node || !fds)
		return ;
	tmp = node;
	while (tmp)
	{
		if (tmp->type == REDIR_OUT || tmp->type == APPEND)
		{
			out = __out_handler_copy(tmp, fds + 1);
			if (out == -1)
				return ;
		}
		else if (tmp->type == REDIR_IN || tmp->type == HEREDOC)
		{
			in = _open_in_copy(tmp, fds);
			if (in == -1)
				return ;
		}
		tmp = tmp->next;
	}
}

void	sig_hear(int s)
{
	(void) s;
	write(1, "\n", 1);
	exit (111);
}
