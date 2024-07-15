/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   out_create.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ochouati <ochouati@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/14 15:12:47 by ochouati          #+#    #+#             */
/*   Updated: 2024/07/15 15:15:11 by ochouati         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

t_outred	*outred_getlast(t_outred *lst)
{
	while (lst && lst->next)
		lst = lst->next;
	return (lst);
}

t_outred	*outred_create(char *file, t_token type)
{
	t_outred	*new;

	new = ft_calloc(1, sizeof(t_outred));
	if (!new)
		return (NULL);
	new->file = file;
	new->type = type;
	return (new);
}

void	outred_addback(t_outred **lst, t_outred *new)
{
	t_outred	*last;

	if (!lst || !new)
		return ;
	if (!*lst)
	{
		*lst = new;
		return ;
	}
	last = outred_getlast(*lst);
	if (!last)
		return ;
	last->next = new;
}

void	outred_delete1(t_outred *node)
{
	if (!node)
		return ;
	ft_free((void **)&node->file);
	free(node);
}

void	outred_clear(t_outred **lst)
{
	t_outred	*tmp;

	if (!lst || !*lst)
		return ;
	while (*lst)
	{
		tmp = (*lst)->next;
		outred_delete1(*lst);
		*lst = tmp;
	}
}
