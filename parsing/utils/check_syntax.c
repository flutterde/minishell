/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_syntax.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ochouati <ochouati@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/06 10:58:47 by mboujama          #+#    #+#             */
/*   Updated: 2024/07/30 14:58:51 by ochouati         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

static int	pipe_checks(t_lex *lex)
{
	t_lex	*last;

	last = lex_getlast(lex);
	if (!last)
		return (0);
	if (last->prev->type == PIPELINE)
		return (g_status = 258, mini_printf(2,
				"minishell: syntax error near unexpected token `|'\n"), 0);
	else if ((rev_consec_spaces(lex, REDIR_OUT)
		|| rev_consec_spaces(lex, REDIR_IN)
		|| rev_consec_spaces(lex, APPEND) 
		|| rev_consec_spaces(lex, HEREDOC)
		|| rev_consec_spaces(lex, PIPELINE)) && lex->status == GENERAL)
		return (g_status = 258, mini_printf(2,
				"minishell: syntax error near unexpected token `|'\n"), 0);
	return (1);
}

static int	redirect_checks(t_lex *lex)
{
	t_lex	*last;

	last = lex_getlast(lex);
	if (last->prev->type == REDIR_OUT || last->prev->type == REDIR_IN
		|| last->prev->type == APPEND || last->prev->type == HEREDOC)
		return (g_status = 258, mini_printf(2,
				"minishell: syntax error\n"), 0);
	if ((rev_consec_spaces(lex, REDIR_OUT) || rev_consec_spaces(lex, REDIR_IN)
		|| rev_consec_spaces(lex, APPEND) 
		|| rev_consec_spaces(lex, HEREDOC)) && lex->status == GENERAL)
	{
		if (lex->type == REDIR_OUT)
			return (g_status = 258, mini_printf(2,
					"minishell: syntax error near unexpected token `>'\n"), 0);
		else if (lex->type == REDIR_IN)
			return (g_status = 258, mini_printf(2,
					"minishell: syntax error near unexpected token `<'\n"), 0);
		else if (lex->type == HEREDOC)
			return (g_status = 258, mini_printf(2,
					"minishell: syntax error near unexpected token `<<'\n"), 0);
		else if (lex->type == APPEND)
			return (g_status = 258, mini_printf(2,
					"minishell: syntax error near unexpected token `>>'\n"), 0);
	}
	return (1);
}

static int	env_checks(t_lex *lex)
{
	if (ft_strcmp(lex->string, "$?") && !check_chars_env(lex))
		return (g_status = 258, mini_printf(2,
				"minishell: syntax error near unexpected token `$'\n"), 0);
	return (1);
}

int	check_syntax(t_lex *lex)
{
	if (lex->type == PIPELINE)
	{
		if (!pipe_checks(lex))
			return (0);
	}
	else if (lex->type == REDIR_IN || lex->type == REDIR_OUT
		|| lex->type == HEREDOC || lex->type == APPEND)
	{
		if (!redirect_checks(lex))
			return (0);
	}
	else if (lex->type == ENV)
	{
		if (!env_checks(lex))
			return (0);
	}
	return (1);
}
