/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_create.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ochouati <ochouati@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/13 09:43:57 by ochouati          #+#    #+#             */
/*   Updated: 2024/07/13 10:43:29 by ochouati         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

t_cmd	*cmd_create(char *path, char **args)
{
	t_cmd	*new;

	if (!path || !args || !*args)
		return (NULL);
	new = ft_calloc(1, sizeof(t_cmd));
	if (!new)
		return (NULL);
	new->path = path;
	new->cmd = args[0];
	new->args = args;
	return (new);
}

t_cmd	*cmd_getlast(t_cmd *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next)
		lst = lst->next;
	return (lst);
}

void	cmd_addback(t_cmd **lst, t_cmd *new)
{
	t_cmd	*last;

	if (!new || !lst)
		return ;
	if (!*lst)
	{
		*lst = new;
		return ;
	}
	last = cmd_getlast(*lst);
	if (!last)
		return ;
	last->next = new;
}
