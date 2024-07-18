/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   join_lexer_helpers.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboujama <mboujama@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 12:44:40 by mboujama          #+#    #+#             */
/*   Updated: 2024/07/18 12:49:14 by mboujama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

int	is_redirection(t_lex *lex)
{
	if (lex->status == REDIR_IN || lex->status == REDIR_OUT
		|| lex->status == HEREDOC || lex->status == DREDIR_OUT)
		return (1);
	return (0);
}
