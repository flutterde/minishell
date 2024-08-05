/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wildcards_utils2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboujama <mboujama@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/05 15:07:37 by mboujama          #+#    #+#             */
/*   Updated: 2024/08/05 19:08:49 by mboujama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

void	get_pattern_helper(char **str, char **cha, char **ret_str, int *i)
{
	while ((*str)[*i] == WILD_C)
		(*i)++;
	*cha = char_to_str(WILD_C);
	if (!*cha)
		return ;
	*ret_str = ft_strjoin(*ret_str, *cha);
	ft_free((void **) cha);
}

void	pattern_helper(t_wildcard *wild)
{
	while (wild->cmd->args[wild->i])
	{
		if (!ft_strchr(wild->cmd->args[wild->i], WILD_C))
		{
			wild->new = str_lst_new(ft_strdup(wild->cmd->args[wild->i]));
			str_lst_addback(&wild->list, wild->new);
		}
		else
			expand_wildcard(wild);
		wild->i++;
	}
}
