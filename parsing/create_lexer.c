/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_lexer.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboujama <mboujama@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 15:33:09 by mboujama          #+#    #+#             */
/*   Updated: 2024/07/04 15:56:01 by mboujama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	create_lexer(char *line)
{
	int	i;

	i = 0;
	while (*line)
	{
		if (*line == '\'')
			ft_printf("QUOTE %c\n", *line);
		else if (*line == '\"')
			ft_printf("DQUOTE %c\n", *line);
		else if (*line == ' ')
			ft_printf("SPACE %c\n", *line);
		else if (*line == '$')
			ft_printf("ENV %c\n", *line);
		else if (*line == '\n')
			ft_printf("NEWLINE %c\n", *line);
		else if (*line == '|')
			ft_printf("PIPELINE %c\n", *line);
		else if (*line == '<')
			ft_printf("REDIR_IN %c\n", *line);
		else if (*line == '>')
			ft_printf("REDIR_OUT %c\n", *line);
		else if (*line == '>')
			ft_printf("REDIR_OUT %c\n", *line);
		// TODO: HEREDOC, APPEND, WORD
		line++;
	}
	return (1);
}
