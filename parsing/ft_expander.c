/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_expander.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ochouati <ochouati@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 12:32:47 by mboujama          #+#    #+#             */
/*   Updated: 2024/07/27 16:50:59 by ochouati         ###   ########.fr       */
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

int	ft_expander(t_data *data, t_lex *lexer)
{
	t_lex	*tmp_lex;
	t_env	*found;
	char	*key;
	char	*tmp;

	tmp_lex = lexer;
	while (tmp_lex)
	{
		if (tmp_lex->type == ENV && tmp_lex->status != IN_S_QUOTE)
		{
			if (ft_strcmp(tmp_lex->string, "$?") == 0)
			{
				tmp = tmp_lex->string;
				tmp_lex->string = ft_itoa(g_status);
				ft_free((void **) &tmp);
				tmp_lex = tmp_lex->next;
				continue ;
			}
			if (tmp_lex->len == 1 || is_heredoc_before(tmp_lex))
			{
				tmp_lex = tmp_lex->next;
				continue ;
			}
			key = ft_substr(tmp_lex->string, 1, tmp_lex->len - 1);
			if (!key)
				return (0);
			found = search_env(data->env, key);
			ft_free((void **) &tmp_lex->string);
			if (!found)
				tmp_lex->string = ft_strdup("");
			else
				tmp_lex->string = ft_strdup(found->value);
			ft_free((void **) &key);
		}
		tmp_lex = tmp_lex->next;
	}
	return (1);
}
