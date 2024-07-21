/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_redirect.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboujama <mboujama@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/20 20:34:25 by mboujama          #+#    #+#             */
/*   Updated: 2024/07/20 20:50:07 by mboujama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

static int	fill_redirect_in(t_lex **lex, t_inred *in)
{
	(void) lex;
	(void) in;
	printf("redirect in\n");
	return (1);
}

static int	fill_redirect_out(t_lex **lex, t_outred *out)
{
	(void) lex;
	(void) out;
	printf("redirect out\n");
	return (1);
}

int	fill_redirect(t_lex **lex, t_inred *in, t_outred *out)
{
	if ((*lex)->type == HEREDOC || (*lex)->type == REDIR_IN)
	{
		if (!fill_redirect_in(lex, in))
			return (0);
	}
	else
	{
		if (fill_redirect_out(lex, out))
			return (0);
	}
	return (1);
}

