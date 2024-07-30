/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   red_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboujama <mboujama@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 09:50:30 by ochouati          #+#    #+#             */
/*   Updated: 2024/07/29 16:38:18 by mboujama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

void	red_set_index(t_redir *lst)
{
	int		i;
	t_redir	*tmp;

	i = 0;
	tmp = lst;
	while (tmp)
	{
		if (tmp->type == HEREDOC)
			tmp->index = i++;
		tmp = tmp->next;
	}
	while (lst)
	{
		if (lst->type != HEREDOC)
			lst->index = i++;
		lst = lst->next;
	}
}

static void	_red_swap_data(t_redir *a, t_redir *b)
{
	t_red_help	red;

	bzero((void *) &red, sizeof(t_red_help));
	red.tp = a->type;
	red.file = a->file;
	red.delim = a->delim;
	red.expand = a->to_expand;
	red.ambiguous = a->is_ambiguous;
	red.index = a->index;
	a->type = b->type;
	a->file = b->file;
	a->delim = b->delim;
	a->to_expand = b->to_expand;
	a->is_ambiguous = b->is_ambiguous;
	a->index = b->index;
	b->type = red.tp;
	b->file = red.file;
	b->delim = red.delim;
	b->to_expand = red.expand;
	b->is_ambiguous = red.ambiguous;
	b->index = red.index;
}

void	red_sort(t_redir *lst)
{
	t_redir	*tmp;

	red_set_index(lst);
	while (lst)
	{
		tmp = lst->next;
		while (tmp)
		{
			if (tmp->index < lst->index)
				_red_swap_data(lst, tmp);
			tmp = tmp->next;
		}
		lst = lst->next;
	}
}

void	_reset_utils(t_cmd_utils *utils)
{
	utils->type = 0;
	utils->file = NULL;
	utils->delim = NULL;
	utils->heredoc_expand = false;
	utils->is_ambiguous = false;
}
