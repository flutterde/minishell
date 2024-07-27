/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_syntax_helpers.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ochouati <ochouati@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/07 09:45:35 by mboujama          #+#    #+#             */
/*   Updated: 2024/07/27 16:46:59 by ochouati         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

/// @brief Check if there is only spaces between two special characters
/// @param lex the node of the first special char
/// @param token token to end
/// @return (0) if OK - (1) if there is only spaces
int	consec_spaces(t_lex *lex, t_token token)
{
	t_lex	*tmp;

	tmp = lex;
	lex = lex->next;
	while (lex && lex->type != token)
	{
		if (lex->type != W_SPACE)
			return (0);
		lex = lex->next;
	}
	lex = tmp;
	return (1);
}

int	rev_consec_spaces(t_lex *lex, t_token token)
{
	t_lex	*tmp;

	tmp = lex;
	if (!lex->prev)
		return (0);
	lex = lex->prev;
	while (lex && lex->type != token)
	{
		if (lex->type != W_SPACE)
			return (0);
		lex = lex->prev;
	}
	lex = tmp;
	return (1);
}

int	check_chars_env(t_lex *lex)
{
	int	i;

	i = 1;
	while (lex->string[i])
	{
		if (!ft_isalnum(lex->string[i]) && lex->string[i] != '_')
			return (0);
		i++;
	}
	return (1);
}

int	quotes_check(t_data *data, t_lex *lex)
{
	t_quote	quote;

	(void) data;
	ft_bzero(&quote, sizeof(t_quote));
	quote.tmp = lex;
	while (quote.tmp)
	{
		if (quote.tmp->type == QUOTE && !quote.in_d_quote)
		{
			quote.in_s_quote = !quote.in_s_quote;
			quote.nb_s_quote++;
		}
		else if (quote.tmp->type == DOUBLE_QUOTE && !quote.in_s_quote)
		{
			quote.in_d_quote = !quote.in_d_quote;
			quote.nb_d_quote++;
		}
		quote.tmp = quote.tmp->next;
	}
	if (quote.nb_d_quote % 2 != 0)
		return (g_status = 258, mini_printf(2,
				"minishell: syntax error near \"\n"), 0);
	else if (quote.nb_s_quote % 2 != 0)
		return (g_status = 258, mini_printf(2,
				"minishell: syntax error near \'\n"), 0);
	return (1);
}
