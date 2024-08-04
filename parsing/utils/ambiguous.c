/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ambiguous.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboujama <mboujama@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/03 19:48:23 by mboujama          #+#    #+#             */
/*   Updated: 2024/08/04 11:55:46 by mboujama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

int	consec_quote_rev(t_lex *lex, t_token token)
{
	t_lex	*tmp;

	tmp = lex;
	while (tmp && tmp->type == token)
		tmp = tmp->prev;
	if (!(tmp->type == W_SPACE && tmp->status == GENERAL)
		|| tmp->type == WORD || tmp->type == ENV)
		return (1);
	return (0);
}

int	consec_quote(t_lex *lex, t_token token)
{
	t_lex	*tmp;

	tmp = lex;
	while (tmp && tmp->type == token)
		tmp = tmp->next;
	if (!(tmp->type == W_SPACE && tmp->status == GENERAL)
		|| tmp->type == WORD || tmp->type == ENV)
		return (1);
	return (0);
}

t_token	consec_quote_type(t_lex *lex, t_token token)
{
	t_lex	*tmp;

	tmp = lex;
	while (tmp && tmp->type == token)
		tmp = tmp->next;
	if (tmp)
		return (tmp->type);
	return (0);
}

void	left_space(t_lex **lex, t_cmd_utils *utils)
{
	if ((*lex)->prev && consec_quote_rev((*lex)->prev, QUOTE))
		utils->is_ambiguous = true;
	else if ((*lex)->prev && consec_quote_rev((*lex)->prev, DOUBLE_QUOTE))
		utils->is_ambiguous = true;
	else if ((*lex)->prev && ((*lex)->prev->type == WORD
			|| (*lex)->prev->type == ENV))
		utils->is_ambiguous = true;
}

void	right_space(t_lex **lex, t_cmd_utils *utils)
{
	if ((*lex)->next && (*lex)->next->type == QUOTE
		&& consec_quote((*lex)->next, QUOTE))
		utils->is_ambiguous = true;
	else if ((*lex)->next && (*lex)->next->type == DOUBLE_QUOTE
		&& consec_quote((*lex)->next, DOUBLE_QUOTE))
		utils->is_ambiguous = true;
	if ((*lex)->type == QUOTE && !consec_quote_type((*lex)->next, QUOTE))
		utils->is_ambiguous = false;
	else if ((*lex)->type == DOUBLE_QUOTE
		&& !consec_quote_type((*lex)->next, DOUBLE_QUOTE))
		utils->is_ambiguous = false;
}
