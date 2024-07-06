/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_quote.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboujama <mboujama@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/29 10:42:22 by mboujama          #+#    #+#             */
/*   Updated: 2024/07/04 19:04:21 by mboujama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

static void	expand_env(t_env *env, t_parse *parse_dt, char *search)
{
	t_env	*found_env;
	int		i;

	i = -1;
	found_env = search_env(env, search);
	if (!found_env)
		return ;
	parse_dt->new_str = ft_strjoin(parse_dt->new_str, found_env->value);
	free(search);
}

static void	ft_expand(t_env *env, t_parse *parse_dt, char **str)
{
	char	*search;
	char	*tmp;
	int		len;
	int		i;

	len = search_len(*str);
	tmp = *str;
	if (len == 0)
		return ;
	search = (char *) ft_calloc(len + 1, sizeof(char));
	if (!search)
		return ;
	i = 0;
	printf("STR 3 = %s\n", *str);
	while (i < len)
	{
		search[i] = **str;
		(*str)++;
		i++;
	}
	search[i] = '\0';
	expand_env(env, parse_dt, search);
}

static void	check_special_chars(t_parse *parse_dt, t_env *env, char **str)
{
	if (**str == '$' && !parse_dt->in_s_quote)
	{
		//TODO: if whitespace after $ or '\0'
		while (**str == '$')
		{
			(*str)++;
			ft_expand(env, parse_dt, str);
		}
	}
}

char	*parse_quote(t_data *data, char *str)
{
	t_parse	parse_dt;

	if (!str)
		return (NULL);
	ft_bzero(&parse_dt, sizeof(t_parse));
	parse_dt.new_str = ft_strdup("");
	while (*str)
	{
		check_special_chars(&parse_dt, data->env, &str);
		parse_dt.type_q = get_type(*str);
		if (parse_dt.type_q == S_QUOTE && !parse_dt.in_d_quote)
			parse_dt.in_s_quote = !parse_dt.in_s_quote;
		else if (parse_dt.type_q == D_QUOTE && !parse_dt.in_s_quote)
			parse_dt.in_d_quote = !parse_dt.in_d_quote;
		else
		{
			parse_dt.str_char = char_to_str(*str);
			parse_dt.new_str = ft_strjoin(parse_dt.new_str, parse_dt.str_char);
			free(parse_dt.str_char);
		}
		str++;
	}
	return (handle_spaces(&parse_dt));
}
