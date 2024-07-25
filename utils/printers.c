/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printers.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboujama <mboujama@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 10:41:39 by mboujama          #+#    #+#             */
/*   Updated: 2024/07/25 11:04:56 by mboujama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char	*print_token(t_token token)
{
	if (token == W_SPACE)
		return ("W_SPACE");
	else if (token == QUOTE)
		return ("QUOTE");
	else if (token == DOUBLE_QUOTE)
		return ("DOUBLE_QUOTE");
	else if (token == PIPELINE)
		return ("PIPELINE");
	else if (token == REDIR_IN)
		return ("REDIR_IN");
	else if (token == REDIR_OUT)
		return ("REDIR_OUT");
	else if (token == HEREDOC)
		return ("HEREDOC");
	else if (token == APPEND)
		return ("APPEND");
	else if (token == WORD)
		return ("WORD");
	else if (token == ENV)
		return ("ENV");
	return (NULL);
}

char	*print_status(t_status status)
{
	if (status == GENERAL)
		return ("GENERAL");
	else if (status == IN_S_QUOTE)
		return ("IN_S_QUOTE");
	else if (status == IN_D_QUOTE)
		return ("IN_D_QUOTE");
	else if (status == END)
		return ("END");
	return (NULL);
}

void	print_linked_list(t_cmd *cmd)
{
	printf("COMMAND LINKED LIST:\n");
	while (cmd)
	{
		printf("\n----> ARGUMENTS <----\n");
		ft_print_strs(cmd->args);
		printf("\n----> REDIRECTS <----\n");
		while (cmd->redire)
		{
			printf("delim => %s\t| file => %s\t| type => %s\n",
				cmd->redire->delim, cmd->redire->file,
				print_token(cmd->redire->type));
			cmd->redire = cmd->redire->next;
		}
		cmd = cmd->next;
	}
}

void	ft_print_lexer(t_lex *lex)
{	
	printf("LEXER:\n");
	printf("-----------------------------------------------------------------\n");
	printf("| content	| status	| len	| type	|\n");
	printf("-----------------------------------------------------------------\n");
	while (lex)
	{
		printf("| '%s'		| %s		| %d	| %s	|\n",
			lex->string, print_status(lex->status),
			lex->len, print_token(lex->type));
		lex = (lex)->next;
	}
	printf("-----------------------------------------------------------------\n");
}
