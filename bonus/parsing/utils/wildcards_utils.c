/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wildcards_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboujama <mboujama@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/04 19:12:35 by mboujama          #+#    #+#             */
/*   Updated: 2024/08/05 18:44:19 by mboujama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

void	search_rep_asterisk(t_lex *lex)
{
	t_lex	*tmp;
	int		i;

	tmp = lex;
	while (tmp)
	{
		if (tmp->status == GENERAL && ft_strchr(tmp->string, '*'))
		{
			i = 0;
			while (tmp->string[i])
			{
				if (tmp->string[i] == '*')
					tmp->string[i] = WILD_C;
				i++;
			}
		}
		tmp = tmp->next;
	}
}

char	*get_pattern(char *str)
{
	char	*ret_str;
	char	*cha;
	int		i;

	i = 0;
	ret_str = ft_strdup("");
	if (!ret_str)
		return (NULL);
	while (str[i])
	{
		if (str[i] == WILD_C)
		{
			get_pattern_helper(&str, &cha, &ret_str, &i);
			if (!ret_str)
				return (NULL);
			continue ;
		}
		cha = char_to_str(str[i]);
		ret_str = ft_strjoin(ret_str, cha);
		if (!ret_str)
			return (NULL);
		ft_free((void **) &cha);
		i++;
	}
	return (ret_str);
}

char	*old_val(char *str)
{
	int		i;
	char	*new;

	i = 0;
	new = ft_strdup(str);
	if (!new)
		return (NULL);
	while (new[i])
	{
		if (new[i] == WILD_C)
			new[i] = '*';
		i++;
	}
	return (new);
}

int	expand_wildcard(t_wildcard *wild)
{
	int	i;

	i = 0;
	wild->tmp_args = ft_wildcard(get_pattern(wild->cmd->args[wild->i]),
			getcwd(wild->buff, 1500));
	if (wild->tmp_args)
	{
		while (wild->tmp_args[i])
		{
			wild->new = str_lst_new(ft_strdup(wild->tmp_args[i]));
			str_lst_addback(&wild->list, wild->new);
			i++;
		}
		ft_free_strs(wild->tmp_args);
		wild->tmp_args = NULL;
	}
	else
	{
		wild->s_tmp = old_val(wild->cmd->args[wild->i]);
		wild->new = str_lst_new(wild->s_tmp);
		str_lst_addback(&wild->list, wild->new);
	}
	return (1);
}
