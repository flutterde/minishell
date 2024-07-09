/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_syntax_helpers.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboujama <mboujama@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/07 09:45:35 by mboujama          #+#    #+#             */
/*   Updated: 2024/07/09 13:15:25 by mboujama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

/// @brief Check if there is only spaces between two special characters
/// @param lex the node of the first special char
/// @param token token to end
/// @return (0) if OK - (1) if there is only spaces
int	consec_spaces(t_lex *lex, t_token token)
{
	int		found;
	t_lex	*tmp;

	found = 0;
	tmp = lex;
	lex = lex->next;
	while (lex && lex->type != token)
	{
		if (lex->type != WHITE_SPACE)
			return (0);
		lex = lex->next;
	}
	lex = tmp;
	return (1);
}

int	rev_consec_spaces(t_lex *lex, t_token token)
{
	int		found;
	t_lex	*tmp;

	found = 0;
	tmp = lex;
	if (!lex->prev)
		return (0);
	lex = lex->prev;
	while (lex && lex->type != token)
	{
		if (lex->type != WHITE_SPACE)
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
	t_lex	*tmp;
	int		nb_s_quote;
	int		nb_d_quote;

	nb_d_quote = 0;
	nb_s_quote = 0;
	tmp = lex;
	while (tmp)
	{
		if (tmp->type == S_QUOTE && tmp->state == GENERAL)
			nb_s_quote++;
		else if (tmp->type == D_QUOTE && tmp->state == GENERAL)
			nb_d_quote++;
		tmp = tmp->next;
	}
	if (nb_d_quote % 2 != 0)
		return (data->last_exit = 258, mini_printf(2,
				"minishell: syntax error near \"\n"), 0);
	else if (nb_s_quote % 2 != 0)
		return (data->last_exit = 258, mini_printf(2,
				"minishell: syntax error near \'\n"), 0);
	return (1);
}
