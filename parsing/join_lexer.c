/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   join_lexer.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboujama <mboujama@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/14 15:04:55 by mboujama          #+#    #+#             */
/*   Updated: 2024/07/25 10:41:22 by mboujama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static int	get_inside_quote(t_cmd_utils *utils, t_lex **lex)
{
	utils->str = get_str(lex);
	if (!utils->str)
		return (0);
	utils->tmp_args = utils->args;
	utils->args = insert_to2d_array(utils->args, utils->str);
	if (!utils->args)
		return (0);
	ft_free((void **)&utils->str);
	return (1);
}

static int	add_arg(t_cmd_utils *utils, t_lex **lex)
{
	utils->tmp_args = utils->args;
	utils->args = insert_to2d_array(utils->args, (*lex)->string);
	if (!utils->args)
		return (0);
	ft_free_strs(utils->tmp_args);
	utils->tmp_args = NULL;
	return (1);
}

static t_cmd	*get_cmd(t_lex **lex, t_data *data)
{
	t_cmd_utils	utils;

	ft_bzero(&utils, sizeof(t_cmd_utils));
	while ((*lex) && (*lex)->type != PIPELINE && (*lex)->status == GENERAL)
	{
		if ((*lex)->type == W_SPACE)
		{
			*lex = (*lex)->next;
			continue ;
		}
		else if (is_redirection(*lex))
		{
			if (!fill_redirect(lex, &utils))
				return (NULL);
		}
		else if ((*lex)->type == DOUBLE_QUOTE || (*lex)->type == QUOTE)
		{
			if (!get_inside_quote(&utils, lex))
				return (NULL);
		}
		else
		{
			if (!add_arg(&utils, lex))
				return (NULL);
		}
		ft_free_strs(utils.tmp_args);
		utils.tmp_args = NULL;
		*lex = (*lex)->next;
	}
	utils.cmd = cmd_create(data, &utils);
	return (utils.cmd);
}

int	join_lexer(t_data *data)
{
	t_cmd	*cmd;
	t_lex	*tmp;

	tmp = data->lexer;
	while (tmp)
	{
		if (tmp->type == W_SPACE && tmp->status == GENERAL)
		{
			tmp = tmp->next;
			continue ;
		}
		cmd = get_cmd(&tmp, data);
		if (!cmd)
			return (0);
		cmd_addback(&data->command, cmd);
		if (tmp)
			tmp = tmp->next;
	}
	return (1);
}
