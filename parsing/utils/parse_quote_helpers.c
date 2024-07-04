/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_quote_helpers.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboujama <mboujama@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 12:28:33 by mboujama          #+#    #+#             */
/*   Updated: 2024/07/04 14:48:14 by mboujama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

char	get_type(char ch)
{
	if (ch == S_QUOTE)
		return (S_QUOTE);
	if (ch == D_QUOTE)
		return (D_QUOTE);
	return (0);
}

int	search_len(char *str)
{
	int	i;

	i = 0;
	while (str[i] && ft_isalpha(str[i]))
		i++;
	return (i);
}

char	*handle_spaces(t_parse *parse_dt)
{
	char	*str;
	int		i;

	i = -1;
	str = ft_strdup("");
	parse_dt->in_d_quote = 0;
	parse_dt->in_s_quote = 0;
	while (parse_dt->new_str[++i])
	{
		if (parse_dt->new_str[i] == S_QUOTE && !parse_dt->in_d_quote)
			parse_dt->in_s_quote = !parse_dt->in_s_quote;
		else if (parse_dt->new_str[i] == D_QUOTE && !parse_dt->in_s_quote)
			parse_dt->in_d_quote = !parse_dt->in_d_quote;
		if (parse_dt->new_str[i] == ' '
			&& !parse_dt->in_d_quote && !parse_dt->in_s_quote)
		{
			if (parse_dt->new_str[i - 1] != ' ')
				str = ft_strjoin(str, char_to_string(parse_dt->new_str[i]));
			else
				continue ;
		}
		else
			str = ft_strjoin(str, char_to_string(parse_dt->new_str[i]));
	}
	return (free(parse_dt->new_str), parse_dt->new_str = NULL, str);
}
