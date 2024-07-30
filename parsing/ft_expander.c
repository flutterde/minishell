/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_expander.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboujama <mboujama@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 12:32:47 by mboujama          #+#    #+#             */
/*   Updated: 2024/07/29 16:27:14 by mboujama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static int	is_heredoc_before(t_lex *lexer)
{
	t_lex	*tmp;

	tmp = lexer->prev;
	while (tmp && (tmp->type == W_SPACE || tmp->type == DOUBLE_QUOTE))
		tmp = tmp->prev;
	if (tmp && tmp->type == HEREDOC)
		return (1);
	return (0);
}

static int	ft_expander_helper(t_data *data, t_expand *exp_dt)
{
	exp_dt->key = ft_substr(exp_dt->tmp_lex->string,
			1, exp_dt->tmp_lex->len - 1);
	if (!exp_dt->key)
		return (0);
	exp_dt->found = search_env(data->env, exp_dt->key);
	ft_free((void **) &exp_dt->tmp_lex->string);
	if (!exp_dt->found)
		exp_dt->tmp_lex->string = ft_strdup("");
	else
		exp_dt->tmp_lex->string = ft_strdup(exp_dt->found->value);
	ft_free((void **) &exp_dt->key);
	return (1);
}

static void	ft_expander_helper2(t_expand *exp_dt)
{
	exp_dt->tmp = exp_dt->tmp_lex->string;
	exp_dt->tmp_lex->string = ft_itoa(g_status);
	ft_free((void **) &exp_dt->tmp);
	exp_dt->tmp_lex = exp_dt->tmp_lex->next;
}

int	ft_expander(t_data *data, t_lex *lexer)
{
	t_expand	exp_dt;

	ft_bzero((void *) &exp_dt, sizeof(t_expand));
	exp_dt.tmp_lex = lexer;
	while (exp_dt.tmp_lex)
	{
		if (exp_dt.tmp_lex->type == ENV && exp_dt.tmp_lex->status != IN_S_QUOTE)
		{
			if (ft_strcmp(exp_dt.tmp_lex->string, "$?") == 0)
			{
				ft_expander_helper2(&exp_dt);
				continue ;
			}
			if (exp_dt.tmp_lex->len == 1 || is_heredoc_before(exp_dt.tmp_lex))
			{
				exp_dt.tmp_lex = exp_dt.tmp_lex->next;
				continue ;
			}
			if (!ft_expander_helper(data, &exp_dt))
				return (0);
		}
		exp_dt.tmp_lex = exp_dt.tmp_lex->next;
	}
	return (1);
}
