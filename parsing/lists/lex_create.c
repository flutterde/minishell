/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lex_create.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboujama <mboujama@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 15:33:12 by ochouati          #+#    #+#             */
/*   Updated: 2024/07/04 19:02:43 by mboujama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

t_lex	*lex_create(char *str, t_token type, int len, t_status status)
{
	t_lex	*new;

	new = ft_calloc(1, sizeof(t_lex));
	if (!new)
		return (NULL);
	new->string = str;
	new->type = type;
	new->len = len;
	new->status = status;
	return (new);
}
