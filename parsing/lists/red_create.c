/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   red_create.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ochouati <ochouati@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 18:42:56 by ochouati          #+#    #+#             */
/*   Updated: 2024/07/24 09:47:14 by ochouati         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"
//! 5 args is a lot!!
t_redir	*red_create(t_token tp, char *file, char *delim, bool expand, bool amb)
{
	t_redir	*new;

	if (!file && !delim)
		return (NULL);
	new = ft_calloc(1, sizeof(t_redir));
	if (!new)
		return (NULL);
	new->type = tp;
	new->file = file;
	new->delim = delim;
	new->to_expand = expand;
	new->is_ambiguous = amb;
	return (new);
}

t_redir	*red_getlast(t_redir *lst)
{
	while (lst && lst->next)
		lst = lst->next;
	return (lst);
}

void	red_lstadd_back(t_redir **lst, t_redir *new)
{
	t_redir	*last;

	if (!new || !lst)
		return ;
	else if (!*lst)
	{
		*lst = new;
		new->prev = NULL;
		new->next = NULL;
		return ;
	}
	last = red_getlast(*lst);
	last->next = new;
	new->prev = last;
	new->next = NULL;
}

static t_redir	*_get_with_type(t_redir *lst)
{
	while (lst && (lst->type != DREDIR_OUT && lst->type != REDIR_OUT))
		lst = lst->prev;
	return (lst);
}

t_redir	*red_last_withtype(t_redir *lst, t_token tp)
{
	t_redir	*last;

	if (!lst)
		return (NULL);
	last = red_getlast(lst);
	if (tp == REDIR_OUT || tp == REDIR_OUT)
		return (_get_with_type(lst));
	while (last && last->type != tp)
		last = last->prev;
	return (last);
}
