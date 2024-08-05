/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_create.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ochouati <ochouati@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/13 09:43:57 by ochouati          #+#    #+#             */
/*   Updated: 2024/07/31 17:50:35 by ochouati         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

t_cmd	*cmd_create(t_data *data, t_cmd_utils *utils)
{
	t_cmd	*new;

	if (!data || !utils)
		return (NULL);
	new = ft_calloc(1, sizeof(t_cmd));
	if (!new)
		return (NULL);
	if (utils->args)
	{
		new->path = get_absolute_path(utils->args[0], data->env);
		new->cmd = ft_strdup(utils->args[0]);
		if (is_builtin(utils->args[0]))
			new->is_builtin = 1;
		new->args = utils->args;
	}
	new->redire = utils->redir;
	new->red_fd[0] = -2;
	new->red_fd[1] = -2;
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
