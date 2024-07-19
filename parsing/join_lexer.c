/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   join_lexer.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ochouati <ochouati@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/14 15:04:55 by mboujama          #+#    #+#             */
/*   Updated: 2024/07/19 11:48:39 by ochouati         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

t_cmd	*get_cmd(t_lex **lex)
{
	t_cmd		*cmd;
	char		**args;
	char		*str;

	cmd = NULL;
	args = NULL;
	str = ft_strdup("");
	while (*lex && (*lex)->type != PIPELINE)
	{
		if (((*lex)->type == D_QUOTE || (*lex)->type == QUOTE)
			&& (*lex)->status == GENERAL)
		{
			if ((*lex)->next
				&& (((*lex)->type == D_QUOTE && (*lex)->next->type == D_QUOTE) 
					|| ((*lex)->type == QUOTE && (*lex)->next->type == QUOTE)))
			{
				args = insert_to2d_array(args, "");
				if (!args)
					return (NULL);
				*lex = (*lex)->next;
			}
			else
			{
				*lex = (*lex)->next;
				while (((*lex)->status == D_QUOTE && (*lex)->type != D_QUOTE)
					|| ((*lex)->status == QUOTE && (*lex)->type != QUOTE))
				{
					str = ft_strjoin(str, (*lex)->string);
					*lex = (*lex)->next;
				}
				args = insert_to2d_array(args, str);
				if (!args)
					return (free(str), str = NULL, NULL);
				free(str);
			}
			*lex = (*lex)->next;
			continue ;
		}
		*lex = (*lex)->next;
	}
	return (cmd);
}

int	join_lexer(t_data *dt)
{
	t_lex	*tmp;
	t_cmd	*cmd;

	tmp = dt->lexer;
	while (tmp)
	{
		if (tmp->type == W_SPACE && tmp->status == GENERAL)
		{
			tmp = tmp->next;
			continue ;
		}
		cmd = get_cmd(&tmp);
		// if (!cmd)
		if (tmp)
			tmp = tmp->next;
	}
	return (1);
}

// * Skip General Quote and D_Quote
// if ((tmp->type == D_QUOTE || tmp->type == QUOTE)
// 	&& tmp->status == GENERAL)
// {
// 	tmp = tmp->next;
// 	continue ;
// }

// * create new command when pipe found
// if (dt->lexer->type == PIPELINE)
// {
// 	cmd_create(dt, args);
// 	cmd_addback(&dt->command, cmd);
// 	ft_free_strs(args);
// 	continue ;
// }
