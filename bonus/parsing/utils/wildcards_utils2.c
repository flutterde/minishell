/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wildcards_utils2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboujama <mboujama@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/05 15:07:37 by mboujama          #+#    #+#             */
/*   Updated: 2024/08/05 15:13:08 by mboujama         ###   ########.fr       */
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
