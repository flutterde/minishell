/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   join_lexer.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboujama <mboujama@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/14 15:04:55 by mboujama          #+#    #+#             */
/*   Updated: 2024/07/18 15:12:58 by mboujama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char	**get_args(t_lex *lexer)
{
	t_lex	*tmp;
	char	**args;

	args = NULL;
	tmp = lexer;
	while (tmp && tmp->type != PIPELINE)
	{
		if ((tmp->type == D_QUOTE || tmp->type == QUOTE) // TODO: make this condition in a separate function
			&& tmp->status == GENERAL)
		{
			if (tmp->next
				&& ((tmp->type == D_QUOTE && tmp->next->type == D_QUOTE) 
					|| (tmp->type == QUOTE && tmp->next->type == QUOTE)))
			{
				args = insert_to2d_array(args, "");
				if (!args)
					return (NULL);
				tmp = tmp->next;
			}
			tmp = tmp->next;
			continue ;
		}
		printf("====> %s\n", tmp->string);
		tmp = tmp->next;
	}
	return (args);
}

int	join_lexer(t_data *dt)
{
	t_lex	*tmp;
	t_cmd	*cmd;
	char	**args;

	(void) cmd;
	(void) args;
	tmp = dt->lexer;
	while (tmp)
	{
		if (tmp->type == W_SPACE && tmp->status == GENERAL)
		{
			tmp = tmp->next;
			continue ;
		}
		printf("--> %s\n", tmp->string);
		// args = get_args(tmp);
		// if (!args)
		// 	return (0);
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
