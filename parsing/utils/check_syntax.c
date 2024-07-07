/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_syntax.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboujama <mboujama@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/06 10:58:47 by mboujama          #+#    #+#             */
/*   Updated: 2024/07/07 15:13:54 by mboujama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

static int	pipe_checks(t_lex *lex)
{
	t_lex	*last;

	last = lex_getlast(lex);
	if (!last)
		return (0);
	if (last->type == PIPE_LINE)
		return (mini_printf(2,
				"minishell: syntax error near unexpected token `|'\n"), 0);
	else if (rev_consec_spaces(lex, REDIR_OUT)
		|| rev_consec_spaces(lex, REDIR_IN)
		|| rev_consec_spaces(lex, DREDIR_OUT) 
		|| rev_consec_spaces(lex, HERE_DOC)
		|| rev_consec_spaces(lex, PIPE_LINE))
		return (mini_printf(2,
				"minishell: syntax error near unexpected token `|'\n"), 0);
	return (1);
}

static int	redirect_checks(t_lex *lex)
{
	if (rev_consec_spaces(lex, REDIR_OUT)
		|| rev_consec_spaces(lex, REDIR_IN)
		|| rev_consec_spaces(lex, DREDIR_OUT)
		|| rev_consec_spaces(lex, HERE_DOC))
	{
		if (lex->type == REDIR_OUT)
			return (mini_printf(2,
					"minishell: syntax error near unexpected token `>'\n"), 0);
		else if (lex->type == REDIR_IN)
			return (mini_printf(2,
					"minishell: syntax error near unexpected token `<'\n"), 0);
		else if (lex->type == HERE_DOC)
			return (mini_printf(2,
					"minishell: syntax error near unexpected token `<<'\n"), 0);
		else if (lex->type == DREDIR_OUT)
			return (mini_printf(2,
					"minishell: syntax error near unexpected token `>>'\n"), 0);
	}
	return (1);
}

static int	env_checks(t_lex *lex)
{
	(void) lex;
	return (1);
}

int	check_syntax(t_lex *lex)
{
	if (lex->type == PIPE_LINE)
	{
		if (!pipe_checks(lex))
			return (0);
	}
	else if (lex->type == REDIR_IN || lex->type == REDIR_OUT
		|| lex->type == HERE_DOC || lex->type == DREDIR_OUT)
	{
		if (!redirect_checks(lex))
			return (0);
	}
	else if (lex->type == ENV)
		env_checks(lex);
	return (1);
}
