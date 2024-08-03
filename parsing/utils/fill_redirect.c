/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_redirect.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboujama <mboujama@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/20 20:34:25 by mboujama          #+#    #+#             */
/*   Updated: 2024/08/03 11:58:54 by mboujama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

static int	is_ambiguous(t_lex **lex, t_cmd_utils *utils)
{
	char	**strs;
	int		i;

	i = 0;
	if ((*lex)->type == ENV && ft_strlen((*lex)->string) == 0)
		return (1);
	else if ((*lex)->type == ENV)
	{
		strs = ft_split(utils->file, ' ');
		if (!strs)
			return (0);
		while (strs[i])
			i++;
		if (i == 1)
			return (ft_free_strs(strs), 0);
	}
	return (1);
}

static int	heredoc(t_lex **lex, t_cmd_utils *utils)
{
	t_redir	*redire;

	redire = NULL;
	(*lex) = (*lex)->next;
	while ((*lex) && (*lex)->type == W_SPACE)
		(*lex) = (*lex)->next;
	utils->type = HEREDOC;
	utils->delim = get_arg(lex);
	if (!utils->delim)
		return (0);
	redire = red_create(utils);
	if (!redire)
		return (0);
	red_addback(&utils->redir, redire);
	return (1);
}

static int	redirection(t_lex **lex, t_cmd_utils *utils, t_token token)
{
	t_redir		*redire;
	int			in_quote;

	redire = NULL;
	in_quote = 0;
	(*lex) = (*lex)->next;
	while ((*lex) && (*lex)->type == W_SPACE)
		(*lex) = (*lex)->next;
	utils->type = token;
	utils->file = get_arg(lex);
	if (!utils->file)
		return (0);
	if ((*lex)->type == ENV && !in_quote)
	{
		if (is_ambiguous(lex, utils))
			utils->is_ambiguous = true;
	}
	redire = red_create(utils);
	red_addback(&utils->redir, redire);
	return (1);
}

int	fill_redirect(t_lex **lex, t_cmd_utils *utils)
{
	if ((*lex)->type == HEREDOC)
	{
		if (!heredoc(lex, utils))
			return (0);
	}
	else if ((*lex)->type == REDIR_IN)
	{
		if (!redirection(lex, utils, REDIR_IN))
			return (0);
	}
	else if ((*lex)->type == REDIR_OUT)
	{
		if (!redirection(lex, utils, REDIR_OUT))
			return (0);
	}
	else if ((*lex)->type == APPEND)
	{
		if (!redirection(lex, utils, APPEND))
			return (0);
	}
	return (1);
}
