/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   join_lexer_helpers.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboujama <mboujama@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 12:44:40 by mboujama          #+#    #+#             */
/*   Updated: 2024/08/03 09:42:40 by mboujama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

int	add_arg_helper(t_cmd_utils *utils, char **str)
{
	utils->tmp_args = utils->args;
	utils->args = insert_to2d_array(utils->args, *str);
	if (!utils->args)
		return (0);
	ft_free_strs(utils->tmp_args);
	ft_free((void **) str);
	utils->tmp_args = NULL;
	return (1);
}

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
		&& ((*lex)->status == IN_D_QUOTE || (*lex)->status == IN_S_QUOTE))
	{
		str = ft_strjoin(str, (*lex)->string);
		if (!str)
			return (NULL);
		(*lex) = (*lex)->next;
	}
	return (str);
}
