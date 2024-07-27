/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   red_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboujama <mboujama@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 09:50:30 by ochouati          #+#    #+#             */
/*   Updated: 2024/07/27 15:55:10 by mboujama         ###   ########.fr       */
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
	t_token	tp;
	char	*file;
	char	*delim;
	bool	expand;
	bool	ambiguous;
	int		index;

	tp = a->type;
	file = a->file;
	delim = a->delim;
	expand = a->to_expand;
	ambiguous = a->is_ambiguous;
	index = a->index;
	a->type = b->type;
	a->file = b->file;
	a->delim = b->delim;
	a->to_expand = b->to_expand;
	a->is_ambiguous = b->is_ambiguous;
	a->index = b->index;
	b->type = tp;
	b->file = file;
	b->delim = delim;
	b->to_expand = expand;
	b->is_ambiguous = ambiguous;
	b->index = index;
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
