/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_clear.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ochouati <ochouati@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/13 10:51:59 by ochouati          #+#    #+#             */
/*   Updated: 2024/07/28 11:38:15 by ochouati         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

void	cmd_delete1(t_cmd *node)
{
	if (!node)
		return ;
	ft_free((void **) &node->cmd);
	ft_free((void **) &node->path);
	ft_free_strs(node->args);
	red_clear(&node->redire);
	free(node);
	node = NULL;
}

void	cmd_clear(t_cmd **lst)
{
	t_cmd	*tmp;

	if (!lst)
		return ;
	while (*lst)
	{
		tmp = (*lst)->next;
		cmd_delete1(*lst);
		*lst = tmp;
	}
}
