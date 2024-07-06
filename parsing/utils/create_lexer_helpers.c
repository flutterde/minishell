/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_lexer_helpers.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboujama <mboujama@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 09:41:58 by mboujama          #+#    #+#             */
/*   Updated: 2024/07/06 07:07:56 by mboujama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

t_status	_status(t_lex_helper lex)
{
	if (lex.in_d_quote)
		return (D_QUOTE);
	else if (lex.in_s_quote)
		return (S_QUOTE);
	else
		return (GENERAL);
}

void	lex_red_in(t_lex_helper *lex, char **line)
{
	if (*(*line + 1) == '<')
	{
		lex->lex = lex_new_node(ft_strdup("<<"), HERE_DOC, 2, _status(*lex));
		if (!lex->lex)
			return ;
		lex_add_back(&lex->lexer, lex->lex);
		(*line)++;
	}
	else
	{
		lex->lex = lex_new_node(char_to_str('<'), REDIR_IN, 1, _status(*lex));
		if (!lex->lex)
			return ;
		lex_add_back(&lex->lexer, lex->lex);
	}
}

void	lex_red_out(t_lex_helper *lex, char **line)
{
	if (*(*line + 1) == '>')
	{
		lex->lex = lex_new_node(ft_strdup(">>"), DREDIR_OUT, 2, _status(*lex));
		if (!lex->lex)
			return ;
		lex_add_back(&lex->lexer, lex->lex);
		(*line)++;
	}
	else
	{
		lex->lex = lex_new_node(char_to_str('>'), REDIR_OUT, 1, _status(*lex));
		if (!lex->lex)
			return ;
		lex_add_back(&lex->lexer, lex->lex);
	}
}

void	lex_env(t_lex_helper *lex, char **line)
{
	char	*str;

	str = ft_strdup("");
	if (!str)
		return ;
	str = ft_strjoin(str, char_to_str(**line));
	if (!str)
		return ;
	(*line)++;
	while (**line && ft_isalnum(*(*line)))
	{
		str = ft_strjoin(str, char_to_str(**line));
		if (!str)
			return ;
		(*line)++;
	}
	(*line)--;
	lex->lex = lex_new_node(str, ENV, ft_strlen(str), _status(*lex));
	lex_add_back(&lex->lexer, lex->lex);
}

void	lex_word(t_lex_helper *lex, char **line)
{
	char	*str;

	str = ft_strdup("");
	if (!str)
		return ;
	while (**line && **line != QUOTE && **line != D_QUOTE && **line != ' ')
	{
		str = ft_strjoin(str, char_to_str(**line));
		if (!str)
			return ;
		(*line)++;
	}
	(*line)--;
	lex->lex = lex_new_node(str, WORD, ft_strlen(str), _status(*lex));
	lex_add_back(&lex->lexer, lex->lex);
}
