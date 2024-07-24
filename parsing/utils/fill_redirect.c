/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_redirect.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboujama <mboujama@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/20 20:34:25 by mboujama          #+#    #+#             */
/*   Updated: 2024/07/24 13:00:07 by mboujama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

static int	is_ambiguous(t_lex **lex, t_cmd_utils *utils)
{
	char	**strs;
	int		i;

	i = 0;
	if ((*lex)->type == ENV && ft_strlen((*lex)->string) == 0)
		return (printf("minishell: $: ambiguous redirect"), 1);
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
	return (printf("minishell: $: ambiguous redirect"), 1);
}

static int	heredoc(t_lex **lex, t_cmd_utils *utils)
{
	t_inred	*in;

	(*lex) = (*lex)->next;
	while ((*lex) && (*lex)->type == W_SPACE)
		(*lex) = (*lex)->next;
	if ((*lex)->type == DOUBLE_QUOTE || (*lex)->type == QUOTE)
	{
		utils->delim = get_str(lex);
		utils->heredoc_expand = false;
	}
	else
	{
		utils->delim = (*lex)->string;
		utils->heredoc_expand = true;
	}
	in = inred_create(utils->delim, NULL, HEREDOC, utils->heredoc_expand);
	inred_addback(&utils->in, in);
	return (1);
}

static int	redirect_in(t_lex **lex, t_cmd_utils *utils)
{
	t_inred		*in;
	int			in_quote;

	in_quote = 0;
	(*lex) = (*lex)->next;
	while ((*lex) && (*lex)->type == W_SPACE)
		(*lex) = (*lex)->next;
	if ((*lex)->type == DOUBLE_QUOTE || (*lex)->type == QUOTE)
	{
		utils->file = get_str(lex);
		in_quote = 1;
	}
	else
		utils->file = (*lex)->string;
	if (!in_quote && (*lex)->type != ENV)
	{
		if (is_ambiguous(lex, utils))
			utils->is_ambiguous = true;
	}
	in = inred_create(NULL, utils->file, REDIR_IN, false);
	inred_addback(&utils->in, in);
	return (1);
}

static int	redirect_out(t_lex **lex, t_cmd_utils *utils, t_token token)
{
	t_outred	*out;
	int			in_quote;

	out = NULL;
	in_quote = 0;
	(*lex) = (*lex)->next;
	while ((*lex) && (*lex)->type == W_SPACE)
		(*lex) = (*lex)->next;
	if ((*lex)->type == DOUBLE_QUOTE || (*lex)->type == QUOTE)
	{
		utils->file = get_str(lex);
		in_quote = 1;
	}
	else
		utils->file = (*lex)->string;
	if (!in_quote  && (*lex)->type == ENV)
	{
		if (is_ambiguous(lex, utils))
			utils->is_ambiguous = true;
	}
	if (token == REDIR_OUT)
		out = outred_create(utils->file, REDIR_OUT);
	else if (token == DREDIR_OUT)
		out = outred_create(utils->file, DREDIR_OUT);
	outred_addback(&utils->out, out);
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
		if (!redirect_in(lex, utils))
			return (0);
	}
	else if ((*lex)->type == REDIR_OUT)
	{
		if (!redirect_out(lex, utils, REDIR_OUT))
			return (0);
	}
	else if ((*lex)->type == DREDIR_OUT)
	{
		if (!redirect_out(lex, utils, DREDIR_OUT))
			return (0);
	}
	return (1);
}
