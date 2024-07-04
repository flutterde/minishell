/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lex_add_back.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ochouati <ochouati@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 16:21:32 by ochouati          #+#    #+#             */
/*   Updated: 2024/07/04 16:21:51 by ochouati         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

void	lex_add_back(t_lex **list, t_lex *new)
{
	t_lex	*last;

	if (!list || !new)
		return ;
	if (!*list)
	{
		(*list)->next = new;
		return ;
	}
	last = lex_getlast(*list);
	if (!last)
		return ;
	last->next = new;
}
