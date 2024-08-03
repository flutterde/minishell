/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   red_clear.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboujama <mboujama@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 19:06:47 by ochouati          #+#    #+#             */
/*   Updated: 2024/08/03 09:44:14 by mboujama         ###   ########.fr       */
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

static void	mark(t_redir *redir, int type)
{
	if (!redir)
		return ;
	while (redir)
	{
		if (((redir->type == REDIR_OUT || redir->type == APPEND) && type == 1)
			|| ((redir->type == REDIR_IN || redir->type == HEREDOC) 
				&& type == 0))
		{
			redir->is_last = 1;
			break ;
		}
		redir = redir->prev;
	}
}

void	mark_last(t_redir *lst)
{
	t_redir		*node;
	t_status	type;

	node = red_getlast(lst);
	if (!node)
		return ;
	type = node->type;
	node->is_last = 1;
	if (type == REDIR_OUT || type == APPEND)
		mark(node->prev, 0);
	else
		mark(node->prev, 1);
}
