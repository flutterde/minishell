/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   red_utils_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboujama <mboujama@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/03 09:53:27 by mboujama          #+#    #+#             */
/*   Updated: 2024/08/03 12:03:05 by mboujama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

void	get_last_in(t_redir *last)
{
	while (last)
	{
		if (last->type == HEREDOC || last->type == REDIR_IN)
		{
			last->is_last = true;
			break ;
		}
		last = last->prev;
	}
}

void	get_last_out(t_redir *last)
{
	while (last)
	{
		if (last->type == APPEND || last->type == REDIR_OUT)
		{
			last->is_last = true;
			break ;
		}
		last = last->prev;
	}
}

void	swap_data(t_red_help red, t_redir *b)
{
	b->type = red.tp;
	b->file = red.file;
	b->delim = red.delim;
	b->to_expand = red.expand;
	b->is_ambiguous = red.ambiguous;
	b->is_last = red.is_last;
	b->index = red.index;
	b->is_last = red.is_last;
}
