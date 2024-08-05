/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redire_handler.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ochouati <ochouati@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 16:00:02 by mboujama          #+#    #+#             */
/*   Updated: 2024/08/04 16:00:27 by ochouati         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

static int	__out_handler(t_redir *redire, int *redfd)
{
	int	fd;

	if (redire->is_ambiguous)
		return (mini_printf(2, "minishell:: %s: ambiguous redirect\n",
				redire->file), g_status = 1, *redfd = -1, -1);
	if (redire->type == REDIR_OUT)
	{
		fd = open(redire->file, O_WRONLY | O_CREAT | O_TRUNC, 0644);
		if (fd == -1)
			return (*redfd = -1, mini_printf(2, "minishell: %s: %s\n",
					redire->file, strerror(errno)), g_status = 1, -1);
	}
	else
	{
		fd = open(redire->file, O_WRONLY | O_CREAT | O_APPEND, 0644);
		if (fd == -1)
			return (*redfd = -1, mini_printf(2, "minishell: %s: %s\n",
					redire->file, strerror(errno)), g_status = 1, -1);
	}
	return (close(fd), fd);
}

static int	_open_in(t_redir *node, int *redfd)
{
	int	fd;

	fd = open(node->file, O_RDONLY);
	if (fd == -1)
	{
		mini_printf(2, "minishell: %s: %s\n", node->file, strerror(errno));
		return (g_status = 1, *redfd = -1, -1);
	}
	if (node->is_last)
		return (*redfd = fd, fd);
	return (close(fd), fd);
}

static int	__in_handler(t_data *data, t_redir *node, int *redfd)
{
	if (node->is_ambiguous)
		return (mini_printf(2, "minishell: %s: ambiguous redirect\n",
				node->file), g_status = 1, *redfd = -1, -1);
	if (node->type == REDIR_IN)
		return (_open_in(node, redfd));
	else if (node->type == HEREDOC)
		return (ft_heredoc(data, node, redfd));
	return (-1);
}

void	_child_redirloop(t_redir	*tmp, int *ints, t_data *data, int *red_fd)
{
	signal (SIGINT, sig_hear);
	while (tmp)
	{
		if (tmp->type == REDIR_OUT || tmp->type == APPEND)
		{
			ints[2] = __out_handler(tmp, red_fd + 1);
			if (ints[2] == -1)
				exit (1);
		}
		else if (tmp->type == REDIR_IN || tmp->type == HEREDOC)
		{
			ints[1] = __in_handler(data, tmp, red_fd);
			if (ints[1] == -1)
				exit (1);
		}
		tmp = tmp->next;
	}
	exit (0);
}

int	redire_handler(t_data *data, t_redir *redire, int *red_fd)
{
	t_redir	*tmp;
	int		ints[4];

	if (!redire)
		return (0);
	tmp = redire;
	signal (SIGINT, SIG_IGN);
	ints[0] = fork();
	if (ints[0] == 0)
	{
		_child_redirloop(tmp, ints, data, red_fd);
	}
	waitpid(ints[0], &ints[3], 0);
	ints[3] = WEXITSTATUS(ints[3]);
	signal (SIGINT, handle_sigint);
	if (ints[3] == 111)
		return (data->sigint = -1, 1);
	return (_reopen_fds(redire, red_fd), ints[3]);
}
