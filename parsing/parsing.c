/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ochouati <ochouati@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/06 10:46:04 by mboujama          #+#    #+#             */
/*   Updated: 2024/07/06 15:25:06 by ochouati         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	parsing(t_data *data, char *line)
{
	t_lex	*tmp;

	tmp = data->lexer;
	data->lexer = create_lexer(line);
	ft_print_lexer(data->lexer);
	if (!ft_strcmp(data->lexer->string, "|"))
		return (mini_printf(2, "minishell: syntax err near unexpected token `|'\n"), 0);
	while (data->lexer)
	{
		check_syntax(data->lexer);
		data->lexer = data->lexer->next;
	}
	return (1);
}
