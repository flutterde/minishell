/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   red_clear.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ochouati <ochouati@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 19:06:47 by ochouati          #+#    #+#             */
/*   Updated: 2024/07/23 19:09:22 by ochouati         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

void	red_delete1(t_redir *node)
{
	if (!node)
		return ;
	if (node->file)
		free(node->file);
	if (node->delim)
		free(node->delim);
	free(node);
}

void	red_clear(t_redir **lst)
{
	t_redir	*tmp;

	while (*lst)
	{
		tmp = *lst;
		*lst = (*lst)->next;
		red_delete1(tmp);
	}
	*lst = NULL;
}
