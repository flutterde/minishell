/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_redirect.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboujama <mboujama@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/20 20:34:25 by mboujama          #+#    #+#             */
/*   Updated: 2024/07/22 15:58:09 by mboujama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

static int	heredoc(t_lex **lex, t_cmd_utils *utils)
{
	t_inred	*in;

	(*lex) = (*lex)->next;
	while ((*lex) && (*lex)->type == W_SPACE)
		(*lex) = (*lex)->next;
	if ((*lex)->type == DOUBLE_QUOTE || (*lex)->type == QUOTE)
	{
		utils->delim = get_str(lex);
		utils->heredoc_expand = false;
	}
	else
	{
		utils->delim = (*lex)->string;
		utils->heredoc_expand = true;
	}
	in = inred_create(utils->delim, NULL, HEREDOC, utils->heredoc_expand);
	inred_addback(&utils->in, in);
	return (1);
}

static int	redirect_in(t_lex **lex, t_cmd_utils *utils)
{
	t_inred	*in;

	(*lex) = (*lex)->next;
	while ((*lex) && (*lex)->type == W_SPACE)
		(*lex) = (*lex)->next;
	if ((*lex)->type == DOUBLE_QUOTE || (*lex)->type == QUOTE)
		utils->file = get_str(lex);
	else
		utils->file = (*lex)->string;
	in = inred_create(NULL, utils->file, REDIR_IN, false);
	inred_addback(&utils->in, in);
	return (1);
}

static int	redirect_out(t_lex **lex, t_cmd_utils *utils)
{
	t_outred	*out;

	(*lex) = (*lex)->next;
	while ((*lex) && (*lex)->type == W_SPACE)
		(*lex) = (*lex)->next;
	if ((*lex)->type == DOUBLE_QUOTE || (*lex)->type == QUOTE)
		utils->file = get_str(lex);
	else
		utils->file = (*lex)->string;
	out = outred_create(utils->file, REDIR_OUT);
	outred_addback(&utils->out, out);
	return (1);
}

static int	append(t_lex **lex, t_cmd_utils *utils)
{
	t_outred	*out;

	(*lex) = (*lex)->next;
	while ((*lex) && (*lex)->type == W_SPACE)
		(*lex) = (*lex)->next;
	if ((*lex)->type == DOUBLE_QUOTE || (*lex)->type == QUOTE)
		utils->file = get_str(lex);
	else
		utils->file = (*lex)->string;
	out = outred_create(utils->file, DREDIR_OUT);
	outred_addback(&utils->out, out);
	return (1);
}

int	fill_redirect(t_lex **lex, t_cmd_utils *utils)
{
	if ((*lex)->type == HEREDOC)
	{
		if (!heredoc(lex, utils))
			return (0);
	}
	else if ((*lex)->type == REDIR_IN)
	{
		if (!redirect_in(lex, utils))
			return (0);
	}
	else if ((*lex)->type == REDIR_OUT)
	{
		if (!redirect_out(lex, utils))
			return (0);
	}
	else if ((*lex)->type == DREDIR_OUT)
	{
		if (!append(lex, utils))
			return (0);
	}
	return (1);
}

