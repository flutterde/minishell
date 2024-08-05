/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_redirect.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboujama <mboujama@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/20 20:34:25 by mboujama          #+#    #+#             */
/*   Updated: 2024/08/04 12:03:01 by mboujama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

static int	heredoc(t_lex **lex, t_cmd_utils *utils)
{
	t_redir	*redire;

	redire = NULL;
	(*lex) = (*lex)->next;
	while ((*lex) && (*lex)->type == W_SPACE)
		(*lex) = (*lex)->next;
	if ((((*lex)->type == WORD || (*lex)->type == ENV)
			&& (*lex)->status == GENERAL)
		&& ((*lex)->next->type == W_SPACE 
			|| (*lex)->next->type == PIPELINE || !is_redirection((*lex))))
		utils->heredoc_expand = true;
	utils->type = HEREDOC;
	utils->delim = get_arg(lex);
	if (!utils->delim)
		return (0);
	redire = red_create(utils);
	if (!redire)
		return (0);
	red_addback(&utils->redir, redire);
	return (1);
}

static int	redirection(t_lex **lex, t_cmd_utils *utils, t_token token)
{
	t_redir		*redire;
	int			in_quote;
	char		*str;

	str = NULL;
	redire = NULL;
	in_quote = 0;
	(*lex) = (*lex)->next;
	while ((*lex) && (*lex)->type == W_SPACE)
		(*lex) = (*lex)->next;
	utils->type = token;
	utils->file = get_file_amb(lex, utils);
	if (!utils->file)
		return (0);
	redire = red_create(utils);
	if (!redire)
		return (0);
	red_addback(&utils->redir, redire);
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
		if (!redirection(lex, utils, REDIR_IN))
			return (0);
	}
	else if ((*lex)->type == REDIR_OUT)
	{
		if (!redirection(lex, utils, REDIR_OUT))
			return (0);
	}
	else if ((*lex)->type == APPEND)
	{
		if (!redirection(lex, utils, APPEND))
			return (0);
	}
	return (1);
}
