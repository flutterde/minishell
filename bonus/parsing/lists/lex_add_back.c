/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lex_add_back.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboujama <mboujama@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 16:21:32 by ochouati          #+#    #+#             */
/*   Updated: 2024/07/04 19:30:01 by mboujama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

static void	_add_null(t_lex *node)
{
	if (!node)
		return ;
	node->next = NULL;
	node->prev = NULL;
}

void	lex_add_back(t_lex **list, t_lex *new)
{
	t_lex	*last;

	if (!new || !list)
		return ;
	_add_null(new);
	if (!*list)
	{
		(*list) = new;
		return ;
	}
	last = lex_getlast(*list);
	if (!last)
		return ;
	new->prev = last;
	last->next = new;
}
