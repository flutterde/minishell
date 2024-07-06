/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_syntax.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboujama <mboujama@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/06 10:58:47 by mboujama          #+#    #+#             */
/*   Updated: 2024/07/06 14:48:11 by mboujama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

static int	pipe_checks(t_lex *lex)
{
	if (!lex)
	{
		mini_printf(2, "No lex\n");
		return (0);
	}
	if (!lex->next)
		if (!ft_strcmp(lex->string, "|"))
			return (mini_printf(2, "minishell: syntax err near unexpected token `|'\n"), 0);
	// TODO: check consecutive spaces and check white spaces "\t \v"
	if (!ft_strcmp(lex->next->string, "|")
		|| (!ft_strcmp(lex->next->string, " ")
			&& !ft_strcmp(lex->next->next->string, "|")))
			return (mini_printf(2, "minishell: syntax err near unexpected token `|'\n"), 0);
	return (1);
}

int	check_syntax(t_lex *lex)
{
	if (lex->type == PIPE_LINE)
		pipe_checks(lex);
	return (1);
}
