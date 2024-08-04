/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redire_handler.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ochouati <ochouati@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 16:00:02 by mboujama          #+#    #+#             */
/*   Updated: 2024/08/03 19:09:30 by ochouati         ###   ########.fr       */
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
	// if (redire->is_last)
	// 	return (*redfd = fd, fd);
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

void sig_hear(int s)
{
	(void) s;
	write (1, "\n", 1);
	exit (111);
}

static int	__out_handler_copy(t_redir *redire, int *redfd)
{
	int	fd;

	if (redire->is_ambiguous)
		return ( g_status = 1, *redfd = -1, -1);
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

static int	_open_in_copy(t_redir *node, int *redfd)
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

static void	_reopen_fds(t_redir *node, int *fds)
{
	t_redir	*tmp;
	int		in;
	int		out;

	if (!node || !fds)
		return ;
	// ft_printf("Now re opening............>\n");
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

int	redire_handler(t_data *data, t_redir *redire, int	*red_fd)
{
	t_redir	*tmp;
	int		in; // red_fd[0]
	int		out; // red_fd[1]
	int 	status;

	(void) in; //?
	(void) out;//?
	(void) red_fd;//?
	if (!redire)
		return (0);
	tmp = redire;
	signal (SIGINT, SIG_IGN);
	int pid = fork();
	if (pid	== 0)
	{
		signal (SIGINT, sig_hear);
		while (tmp)
		{
			if (tmp->type == REDIR_OUT || tmp->type == APPEND)
			{
				out = __out_handler(tmp, red_fd + 1);
				if (out == -1)
					exit (1);
			}
			else if (tmp->type == REDIR_IN || tmp->type == HEREDOC)
			{
				in = __in_handler(data, tmp, red_fd);
				if (in == -1)
					exit (1);
			}
			tmp = tmp->next;
		}
		exit (0);
	}
	waitpid(pid, &status, 0);
	status = WEXITSTATUS(status);
	signal (SIGINT, handle_sigint);
	if (status == 111)
		return (data->sigint = -1, 1);
	_reopen_fds(redire, red_fd);
	// ft_printf("IN: %d   OUT: %d .\n", red_fd[0], red_fd[1]);
	return (status);
}
