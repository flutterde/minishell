/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   removeif_env.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ochouati <ochouati@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 21:28:44 by ochouati          #+#    #+#             */
/*   Updated: 2024/06/12 16:27:43 by ochouati         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

/// @brief this function remove a key from the ENV
/// @param head linkedlist head
/// @param str the key of the node
int	removeif_env(t_env **head, char *str)
{
	t_env	*target;
	t_env	*tmp;
	t_env	*prev;

	if (!head || !*head || !str)
		return (0);
	target = search_env(*head, str);
	if (!target)
		return (0);
	tmp = *head;
	prev = get_prev_env(*head, target);
	if (target == *head)
		return (*head = tmp->next, ls_delete1_env(tmp), 1);
	else if (!target->next)
		return (prev->next = NULL, ls_delete1_env(target), 1);
	return (prev->next = target->next, ls_delete1_env(target), 1);
}
