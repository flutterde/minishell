/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboujama <mboujama@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/06 10:46:04 by mboujama          #+#    #+#             */
/*   Updated: 2024/07/06 14:43:58 by mboujama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	parsing(t_data *data, char *line)
{
	t_lex	*tmp;

	tmp = data->lexer;
	data->lexer = create_lexer(line);
	print_lexer(data->lexer);
	if (!ft_strcmp(data->lexer->string, "|"))
		return (mini_printf(2, "minishell: syntax err near unexpected token `|'\n"), 0);
	while (data->lexer)
	{
		check_syntax(data->lexer);
		data->lexer = data->lexer->next;
	}
	return (1);
}
