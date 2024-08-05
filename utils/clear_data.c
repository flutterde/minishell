/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear_data.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ochouati <ochouati@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 14:58:32 by ochouati          #+#    #+#             */
/*   Updated: 2024/08/04 19:30:16 by ochouati         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	clear_data(t_data **data)
{
	if (!data || !*data)
		return ;
	if ((*data)->env)
		ls_clear_env(&(*data)->env);
	if ((*data)->lexer)
		lex_clear_list(&(*data)->lexer);
	if ((*data)->command)
		cmd_clear(&(*data)->command);
	free((*data)->childs);
	(*data)->childs = NULL;
	free(*data);
	*data = NULL;
}

void	data_cleanup(t_data **data, bool all)
{
	if (!data || !*data)
		return ;
	(*data)->sigint = 0;
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
		if ((*data)->childs)
			free((*data)->childs);
		(*data)->childs = NULL;
	}
}
