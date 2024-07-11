/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear_data.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ochouati <ochouati@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 14:58:32 by ochouati          #+#    #+#             */
/*   Updated: 2024/07/09 15:05:41 by ochouati         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	clear_data(t_data **data)
{
	if (!data || !*data)
		return ;
	// clear (*data)->env
	if ((*data)->env)
		ls_clear_env(&(*data)->env);
	// if (*data)->lexer, clear it.
	if ((*data)->lexer)
		lex_clear_list(&(*data)->lexer);
	free(*data);
	// clear *data;
	*data = NULL;
}
