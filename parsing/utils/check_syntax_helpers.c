/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_syntax_helpers.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboujama <mboujama@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/07 09:45:35 by mboujama          #+#    #+#             */
/*   Updated: 2024/07/07 12:51:37 by mboujama         ###   ########.fr       */
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
