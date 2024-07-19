/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_clear.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ochouati <ochouati@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/13 10:51:59 by ochouati          #+#    #+#             */
/*   Updated: 2024/07/13 15:00:19 by ochouati         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

void	cmd_delete1(t_cmd *node)
{
	if (!node)
		return ;
	ft_free(&node->cmd);
	ft_free(&node->path);
	ft_free_strs(node->args);
	free(node);
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