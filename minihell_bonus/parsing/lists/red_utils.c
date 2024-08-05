/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   red_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboujama <mboujama@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 09:50:30 by ochouati          #+#    #+#             */
/*   Updated: 2024/08/03 12:03:29 by mboujama         ###   ########.fr       */
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
	a->is_last = b->is_last;
	swap_data(red, b);
}

static void	_set_lasts(t_redir *lst)
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
		get_last_in(last);
	else
		get_last_out(last);
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
	ft_free((void **) &utils->file);
	utils->file = NULL;
	ft_free((void **) &utils->delim);
	utils->delim = NULL;
	utils->heredoc_expand = false;
	utils->is_ambiguous = false;
}
