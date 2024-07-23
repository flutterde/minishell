/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inred_create.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboujama <mboujama@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/14 15:12:47 by ochouati          #+#    #+#             */
/*   Updated: 2024/07/23 13:00:08 by mboujama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

t_inred	*inred_getlast(t_inred *lst)
{
	while (lst && lst->next)
		lst = lst->next;
	return (lst);
}

t_inred	*inred_create(char *delim, char *file, t_token type, bool to_expand)
{
	t_inred	*new;

	new = ft_calloc(1, sizeof(t_inred));
	if (!new)
		return (NULL);
	new->delim = delim;
	new->file = file;
	new->type = type;
	new->to_expand = to_expand;
	return (new);
}

void	inred_addback(t_inred **lst, t_inred *new)
{
	t_inred	*last;

	if (!lst || !new)
		return ;
	if (!*lst)
	{
		*lst = new;
		return ;
	}
	last = inred_getlast(*lst);
	if (!last)
		return ;
	last->next = new;
}

void	inred_delete1(t_inred *node)
{
	if (!node)
		return ;
	ft_free((void **)&node->file);
	ft_free((void **)&node->delim);
	free(node);
}

void	inred_clear(t_inred **lst)
{
	t_inred	*tmp;

	if (!lst || !*lst)
		return ;
	while (*lst)
	{
		tmp = (*lst)->next;
		inred_delete1(*lst);
		*lst = tmp;
	}
}
