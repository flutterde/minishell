/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lex_create_node.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ochouati <ochouati@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 15:33:12 by ochouati          #+#    #+#             */
/*   Updated: 2024/07/04 16:21:28 by ochouati         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

t_lex	*lex_create_node(char *str, t_token type, int len, t_status status)
{
	t_lex	*new;

	new = ft_calloc(1, sizeof(t_lex));
	if (!new)
		return (NULL);
	new->string = str;
	new->type = type;
	new->len = len;
	new->state = status;
	return (new);
}
