/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   join_lexer_helpers.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboujama <mboujama@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 12:44:40 by mboujama          #+#    #+#             */
/*   Updated: 2024/07/25 09:45:38 by mboujama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

int	is_redirection(t_lex *lex)
{
	if (lex->type == REDIR_IN || lex->type == REDIR_OUT
		|| lex->type == HEREDOC || lex->type == APPEND)
		return (1);
	return (0);
}

char	*get_str(t_lex **lex)
{
	char	*str;

	str = ft_strdup("");
	if (!str)
		return (NULL);
	(*lex) = (*lex)->next;
	while (*lex 
		&& (((*lex)->status == IN_D_QUOTE && (*lex)->type != DOUBLE_QUOTE)
			|| ((*lex)->status == IN_S_QUOTE && (*lex)->type != QUOTE)))
	{
		str = ft_strjoin(str, (*lex)->string);
		if (!str)
			return (NULL);
		(*lex) = (*lex)->next;
	}
	return (str);
}
