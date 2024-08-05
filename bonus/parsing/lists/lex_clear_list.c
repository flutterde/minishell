/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lex_clear_list.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboujama <mboujama@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 18:34:24 by ochouati          #+#    #+#             */
/*   Updated: 2024/07/07 15:26:52 by mboujama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

void	lex_clear_list(t_lex **list)
{
	t_lex	*tmp;

	if (!list || !*list)
		return ;
	while ((*list)->prev)
		(*list) = (*list)->prev;
	while (*list)
	{
		tmp = (*list)->next;
		lex_delete_node(*list);
		*list = tmp;
	}
	*list = NULL;
}
