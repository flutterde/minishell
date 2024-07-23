/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_expander.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboujama <mboujama@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 12:32:47 by mboujama          #+#    #+#             */
/*   Updated: 2024/07/23 08:54:06 by mboujama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	ft_expander(t_data *data, t_lex *lexer)
{
	t_lex	*tmp_lex;
	t_env	*found;
	char	*key;

	tmp_lex = lexer;
	while (tmp_lex)
	{
		if (tmp_lex->type == ENV && tmp_lex->status != IN_S_QUOTE)
		{
			if (ft_strcmp(tmp_lex->string, "$?") == 0)
			{
				tmp_lex->string = ft_itoa(data->last_exit);
				tmp_lex = tmp_lex->next;
				continue ;
			}
			if (tmp_lex->len == 1)
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
