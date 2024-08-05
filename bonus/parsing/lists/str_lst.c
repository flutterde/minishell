/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_lst.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboujama <mboujama@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/05 16:00:19 by ochouati          #+#    #+#             */
/*   Updated: 2024/08/05 19:05:19 by mboujama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

t_str_lst	*str_lst_new(char *str)
{
	t_str_lst	*new;

	if (!str)
		return (NULL);
	new = ft_calloc(1, sizeof(t_str_lst));
	if (!new)
		return (NULL);
	new->str = str;
	return (new);
}

t_str_lst	*str_lst_last(t_str_lst *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next)
		lst = lst->next;
	return (lst);
}

void	str_lst_addback(t_str_lst **lst, t_str_lst *new)
{
	t_str_lst	*last;

	if (!new || !lst)
		return ;
	if (!*lst)
	{
		*lst = new;
		return ;
	}
	last = str_lst_last(*lst);
	last->next = new;
}

void	str_lst_delete1(t_str_lst *node)
{
	if (!node)
		return ;
	if (node->str)
		free(node->str);
	free(node);
}

void	str_lst_clear(t_str_lst **lst)
{
	t_str_lst	*tmp;

	if (!lst || !*lst)
		return ;
	while (*lst)
	{
		tmp = (*lst)->next;
		str_lst_delete1(*lst);
		*lst = tmp;
	}
}
