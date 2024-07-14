/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   red_create.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ochouati <ochouati@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/14 15:12:47 by ochouati          #+#    #+#             */
/*   Updated: 2024/07/14 19:15:37 by ochouati         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

t_redire	*red_getlast(t_redire *lst)
{
	while (lst && lst->next)
		lst = lst->next;
	return (lst);
}

t_redire	*red_create(char *delim, char *file, t_token type)
{
	t_redire	*new;

	new = ft_calloc(1, sizeof(t_redire));
	if (!new)
		return (NULL);
	new->delim = delim;
	new->file = file;
	new->type = type;
	return (new);
}

void	red_addback(t_redire **lst, t_redire *new)
{
	t_redire	*last;

	if (!lst || !new)
		return ;
	if (!*lst)
	{
		*lst = new;
		return ;
	}
	last = red_getlast(*lst);
	if (!last)
		return ;
	last->next = new;
}

void	red_delete1(t_redire *node)
{
	if (!node)
		return ;
	ft_free(&node->file);
	ft_free(&node->delim);
	free(node);
}

void	red_clear(t_redire **lst)
{
	t_redire	*tmp;

	if (!lst || !*lst)
		return ;
	while (*lst)
	{
		tmp = (*lst)->next;
		red_delete1(*lst);
		*lst = tmp;
	}
}
