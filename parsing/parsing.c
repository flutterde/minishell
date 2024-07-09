/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboujama <mboujama@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/06 10:46:04 by mboujama          #+#    #+#             */
/*   Updated: 2024/07/09 10:31:13 by mboujama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	parsing(t_data *data, char *line)
{
	t_lex	*tmp;

	data->lexer = create_lexer(line);
	tmp = data->lexer;
	ft_print_lexer(tmp);
	if (!ft_strcmp(tmp->string, "|"))
		return (data->last_exit = 258, mini_printf(2,
				"minishell: syntax error near unexpected token `|'\n"), 258);
	while (tmp)
	{
		if (!check_syntax(data, tmp))
			return (0);
		tmp = tmp->next;
	}
	tmp = data->lexer;
	if (!quotes_check(data, tmp))
		return (0);
	return (1);
}
