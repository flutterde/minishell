/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   red_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ochouati <ochouati@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 09:50:30 by ochouati          #+#    #+#             */
/*   Updated: 2024/07/31 15:11:05 by ochouati         ###   ########.fr       */
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
	red.is_last = a->is_last;
	red.index = a->index;
	a->type = b->type;
	a->file = b->file;
	a->delim = b->delim;
	a->to_expand = b->to_expand;
	a->is_ambiguous = b->is_ambiguous;
	a->is_last = b->is_last;
	a->index = b->index;
	b->type = red.tp;
	b->file = red.file;
	b->delim = red.delim;
	b->to_expand = red.expand;
	b->is_ambiguous = red.ambiguous;
	b->is_last = red.is_last;
	b->index = red.index;
}

static void	_set_lasts(t_redir *lst) // << d1 > o1 > o2 < in2 << h2 < in3 >> ap1 << h3 >> ap2
{
	t_redir	*last;
	int		is_out;

	last = red_getlast(lst);
	if (!last)
		return ;
	last->is_last = true;
	if (last->type == HEREDOC || last->type == REDIR_IN)
		is_out = 0;
	else
		is_out = 1;
	last = last->prev;
	if (is_out)
	{
		while(last)
		{
			if (last->type == HEREDOC || last->type == REDIR_IN)
			{
				last->is_last = true;
				break ;
			}
			last = last->prev;
		}
	}
	else
	{
		while(last)
		{
			if (last->type == APPEND || last->type == REDIR_OUT)
			{
				last->is_last = true;
				break ;
			}
			last = last->prev;
		}
	}
}

void	red_sort(t_redir *lst)
{
	t_redir	*tmp;

	_set_lasts(lst);
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
