/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_lexer.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboujama <mboujama@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 15:33:09 by mboujama          #+#    #+#             */
/*   Updated: 2024/07/08 10:47:45 by mboujama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	other_cases_2(t_lex_helper *lex, char **line)
{
	if (**line == '<')
		lex_red_in(lex, line);
	else if (**line == '>')
		lex_red_out(lex, line);
	else if (**line == '$')
		lex_env(lex, line);
	else
		lex_word(lex, line);
}

void	other_cases(t_lex_helper *lex, char **line)
{
	if (**line == '\\')
	{
		lex->lex = lex_new_node(char_to_str('\\'), S_QUOTE, 1, _status(*lex));
		if (!lex->lex)
			return ;
		lex_add_back(&lex->lexer, lex->lex);
	}
	else if (**line == '|')
	{
		lex->lex = lex_new_node(char_to_str('|'), PIPELINE, 1, _status(*lex));
		if (!lex->lex)
			return ;
		lex_add_back(&lex->lexer, lex->lex);
	}
	else if (**line == ' ')
	{
		lex->lex = lex_new_node(char_to_str(' '),
				WHITE_SPACE, 1, _status(*lex));
		if (!lex->lex)
			return ;
		lex_add_back(&lex->lexer, lex->lex);
	}
	else
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
			lex.lex = lex_new_node(char_to_str('\''), S_QUOTE, 1, GENERAL);
			lex_add_back(&lex.lexer, lex.lex);
		}
		else if (*line == '\"')
		{
			lex.in_d_quote = !lex.in_d_quote;
			lex.lex = lex_new_node(char_to_str('\"'), S_QUOTE, 1, GENERAL);
			lex_add_back(&lex.lexer, lex.lex);
		}
		else
			other_cases(&lex, &line);
		line++;
	}
	return (lex.lexer);
}
