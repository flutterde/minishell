/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   red_create.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboujama <mboujama@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 18:42:56 by ochouati          #+#    #+#             */
/*   Updated: 2024/08/03 11:43:01 by mboujama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

t_redir	*red_create(t_cmd_utils *utils)
{
	t_redir	*new;

	if (!utils->file && !utils->delim)
		return (NULL);
	new = ft_calloc(1, sizeof(t_redir));
	if (!new)
		return (NULL);
	new->type = utils->type;
	new->file = ft_strdup(utils->file);
	new->delim = ft_strdup(utils->delim);
	new->to_expand = utils->heredoc_expand;
	new->is_ambiguous = utils->is_ambiguous;
	_reset_utils(utils);
	return (new);
}

t_redir	*red_getlast(t_redir *lst)
{
	while (lst && lst->next)
		lst = lst->next;
	return (lst);
}

void	red_addback(t_redir **lst, t_redir *new)
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
	while (lst && (lst->type != APPEND && lst->type != REDIR_OUT))
		lst = lst->prev;
	return (lst);
}

t_redir	*red_last_withtype(t_redir *lst, t_token tp)
{
	t_redir	*last;

	if (!lst)
		return (NULL);
	last = red_getlast(lst);
	if (tp == APPEND || tp == REDIR_OUT)
		return (_get_with_type(lst));
	while (last && last->type != tp)
		last = last->prev;
	return (last);
}
