/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   red_clear.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboujama <mboujama@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 19:06:47 by ochouati          #+#    #+#             */
/*   Updated: 2024/07/31 11:11:26 by mboujama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

void	red_delete1(t_redir *node)
{
	if (!node)
		return ;
	if (node->file)
		free(node->file);
	if (node->delim)
		free(node->delim);
	free(node);
}

void	red_clear(t_redir **lst)
{
	t_redir	*tmp;

	if (!lst)
		return ;
	while (*lst)
	{
		tmp = *lst;
		*lst = (*lst)->next;
		red_delete1(tmp);
	}
	*lst = NULL;
}

static void	mark_last_in(t_cmd **cmd)
{
	t_redir	*node;
	t_cmd	*tmp;

	tmp = *cmd;
	while (tmp)
	{
		node = red_getlast((tmp)->redire);
		while (node)
		{
			if (node->type == REDIR_IN || node->type == HEREDOC)
			{
				node->is_last = 1;
				break ;
			}
			node = node->prev;
		}
		tmp = (tmp)->next;
	}
}

static void	mark_last_out(t_cmd **cmd)
{
	t_redir	*node;
	t_cmd	*tmp;

	tmp = *cmd;
	while (tmp)
	{
		node = red_getlast((tmp)->redire);
		while (node)
		{
			if (node->type == REDIR_OUT || node->type == APPEND)
			{
				node->is_last = 1;
				break ;
			}
			node = node->prev;
		}
		tmp = (tmp)->next;
	}
}

void	mark_last(t_cmd **cmd)
{
	mark_last_in(cmd);
	mark_last_out(cmd);
}
