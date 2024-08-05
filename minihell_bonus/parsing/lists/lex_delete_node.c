/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lex_delete_node.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboujama <mboujama@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 17:08:18 by ochouati          #+#    #+#             */
/*   Updated: 2024/07/07 15:37:43 by mboujama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

void	lex_delete_node(t_lex *node)
{
	if (!node)
		return ;
	if (node->string)
		free(node->string);
	free(node);
}
