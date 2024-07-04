/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_lexer.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboujama <mboujama@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 15:33:09 by mboujama          #+#    #+#             */
/*   Updated: 2024/07/04 20:30:54 by mboujama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

t_status	_status(t_lex_helper lex)
{
	if (lex.in_d_quote)
		return (D_QUOTE);
	else if (lex.in_s_quote)
		return (S_QUOTE);
	else
		return (GENERAL);
}

void	other_cases_2(t_lex_helper *lex, char *line)
{
	(void) lex;
	if (*line == '$')
		return ;
}

void	other_cases(t_lex_helper *lex, char *line)
{
	if (*line == '\\')
	{
		lex->lex = lex_new_node(char_to_str('\\'), S_QUOTE, 1, _status(*lex));
		lex_add_back(&lex->lexer, lex->lex);
	}
	else if (*line == '|')
	{
		lex->lex = lex_new_node(char_to_str('|'), S_QUOTE, 1, _status(*lex));
		lex_add_back(&lex->lexer, lex->lex);
	}
	else if (*line == ' ')
	{
		lex->lex = lex_new_node(char_to_str(' '), S_QUOTE, 1, _status(*lex));
		lex_add_back(&lex->lexer, lex->lex);
	}
	else if (*line == '\n')
	{
		lex->lex = lex_new_node(char_to_str('\n'), S_QUOTE, 1, _status(*lex));
		lex_add_back(&lex->lexer, lex->lex);
	}
	other_cases_2(lex, line);
}

t_lex	*create_lexer(char *line)
{
	t_lex_helper	lex;
	int				i;

	i = 0;
	ft_bzero(&lex, sizeof(t_lex_helper));
	lex.lexer = NULL;
	while (*line)
	{
		if (*line == '\'')
		{
			lex.in_s_quote = !lex.in_s_quote;
			lex.lex = lex_new_node(char_to_str('\''), S_QUOTE, 1, _status(lex));
			lex_add_back(&lex.lexer, lex.lex);
		}
		else if (*line == '\"')
		{
			lex.in_d_quote = !lex.in_d_quote;
			lex.lex = lex_new_node(char_to_str('\"'), S_QUOTE, 1, _status(lex));
			lex_add_back(&lex.lexer, lex.lex);
		}
		else
			other_cases(&lex, line);
		line++;
	}
	return (lex.lexer);
}
