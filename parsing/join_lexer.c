/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   join_lexer.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboujama <mboujama@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/14 15:04:55 by mboujama          #+#    #+#             */
/*   Updated: 2024/07/20 20:51:21 by mboujama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

t_cmd	*get_cmd(t_lex **lex)
{
	t_cmd		*cmd;
	t_inred		in;
	t_outred	out;
	char		**args;

	(void) args;
	cmd = NULL;
	while ((*lex) && (*lex)->type != PIPELINE && (*lex)->status == GENERAL)
	{
		if ((*lex)->type == W_SPACE)
			printf("space\n");
		else if (is_redirection(*lex))
			fill_redirect(lex, &in, &out);
		else if ((*lex)->type == D_QUOTE || (*lex)->type == QUOTE)
			printf("quote\n");
		else
			printf("argument\n");
		*lex = (*lex)->next;
	}
	return (cmd);
}

int	join_lexer(t_data *dt)
{
	t_cmd	*cmd;
	t_lex	*tmp;

	tmp = dt->lexer;
	while (tmp)
	{
		if (tmp->type == W_SPACE && tmp->status == GENERAL)
		{
			tmp = tmp->next;
			continue ;
		}
		cmd = get_cmd(&tmp);
		if (tmp)
			tmp = tmp->next;
	}
	return (1);
}
