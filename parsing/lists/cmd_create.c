/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_create.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboujama <mboujama@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/13 09:43:57 by ochouati          #+#    #+#             */
/*   Updated: 2024/07/15 15:41:15 by mboujama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

t_cmd	*cmd_create(t_data *data, char **args)
{
	t_cmd	*new;

	if (!args || !*args)
		return (NULL);
	new = ft_calloc(1, sizeof(t_cmd));
	if (!new)
		return (NULL);
	new->path = get_absolute_path(args[0], data->env);
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
