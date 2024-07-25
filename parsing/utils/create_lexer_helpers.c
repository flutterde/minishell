/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_lexer_helpers.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboujama <mboujama@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 09:41:58 by mboujama          #+#    #+#             */
/*   Updated: 2024/07/25 14:50:45 by mboujama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

t_status	_status(t_lex_helper lex)
{
	if (lex.in_d_quote)
		return (IN_D_QUOTE);
	else if (lex.in_s_quote)
		return (IN_S_QUOTE);
	else
		return (GENERAL);
}

void	lex_red_in(t_lex_helper *lex, char **line)
{
	if (*(*line + 1) == '<')
	{
		lex->lex = lex_create(ft_strdup("<<"), HEREDOC, 2, _status(*lex));
		if (!lex->lex)
			return ;
		lex_add_back(&lex->lexer, lex->lex);
		(*line)++;
	}
	else
	{
		lex->lex = lex_create(char_to_str('<'), REDIR_IN, 1, _status(*lex));
		if (!lex->lex)
			return ;
		lex_add_back(&lex->lexer, lex->lex);
	}
}

void	lex_red_out(t_lex_helper *lex, char **line)
{
	if (*(*line + 1) == '>')
	{
		lex->lex = lex_create(ft_strdup(">>"), APPEND, 2, _status(*lex));
		if (!lex->lex)
			return ;
		lex_add_back(&lex->lexer, lex->lex);
		(*line)++;
	}
	else
	{
		lex->lex = lex_create(char_to_str('>'), REDIR_OUT, 1, _status(*lex));
		if (!lex->lex)
			return ;
		lex_add_back(&lex->lexer, lex->lex);
	}
}

void	lex_env(t_lex_helper *lex, char **line)
{
	char	*str;
	char	*ch;

	str = ft_strdup("");
	if (!str)
		return ;
	ch = char_to_str(**line);
	str = ft_strjoin(str, ch);
	free(ch);
	if (!str)
		return ;
	(*line)++;
	if (!ft_strncmp(*line, "?", 1))
		str = ft_strdup("$?");
	else
	{
		while (**line && (ft_isalnum(*(*line)) || **line == '_'))
		{
			ch = char_to_str(**line);
			str = ft_strjoin(str, ch);
			if (!str)
				return ;
			free(ch);
			(*line)++;
		}
		(*line)--;
	}
	if (lex->in_s_quote)
		lex->lex = lex_create(str, WORD, ft_strlen(str), _status(*lex));
	else
		lex->lex = lex_create(str, ENV, ft_strlen(str), _status(*lex));
	lex_add_back(&lex->lexer, lex->lex);
}

void	lex_word(t_lex_helper *lex, char **line)
{
	char	*str;
	char	*ch;

	str = ft_strdup("");
	if (!str)
		return ;
	while (**line && **line != ' ' && **line != '|' && **line != '$'
		&& !(**line == QUOTE || **line == DOUBLE_QUOTE) && **line != REDIR_IN 
		&& **line != REDIR_OUT)
	{
		ch = char_to_str(**line);
		str = ft_strjoin(str, ch);
		if (!str)
			return ;
		free(ch);
		ch = NULL;
		(*line)++;
	}
	(*line)--;
	lex->lex = lex_create(str, WORD, ft_strlen(str), _status(*lex));
	lex_add_back(&lex->lexer, lex->lex);
}
