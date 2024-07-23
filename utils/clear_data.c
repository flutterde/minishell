/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear_data.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ochouati <ochouati@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 14:58:32 by ochouati          #+#    #+#             */
/*   Updated: 2024/07/23 19:18:45 by ochouati         ###   ########.fr       */
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
	if ((*data)->command)
		cmd_clear(&(*data)->command);
	free((*data)->childs);
	(*data)->childs = NULL;
	free(*data);
	// clear *data;
	*data = NULL;
}

void	data_cleanup(t_data **data, bool all)
{
	if (!data || !*data)
		return ;
	if (all)
		clear_data(data);
	else
	{
		if ((*data)->lexer)
			lex_clear_list(&(*data)->lexer);
		if ((*data)->command)
			cmd_clear(&(*data)->command);
		(*data)->lexer = NULL;
		(*data)->command = NULL;
		(*data)->npipes = 0;
		free((*data)->childs);
		(*data)->childs = NULL;
	}
}
