/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_data.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ochouati <ochouati@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 16:47:55 by ochouati          #+#    #+#             */
/*   Updated: 2024/06/27 20:57:37 by ochouati         ###   ########.fr       */
/*                                                                           */
/* ************************************************************************** */

#ifndef MINISHELL_DATA_H
# define MINISHELL_DATA_H

# define COL_RED "\033[0;91m"
# define END_COL "\033[0m"

int	g_sig;

/* -- ENUMS -- */
typedef enum e_token {
	ESCAPE = '\\',
	WHITE_SPACE = ' ',
	NEW_LINE = '\n',
	QUOTE = '\'',
	DOUBLE_QUOTE = '"', 
	PIPE_LINE = '|',
	WORD = -1,
	ENV = '$',
	REDIR_IN = '<',
	REDIR_OUT = '>',
	HERE_DOC,
	DREDIR_OUT,
}	t_token;

typedef enum s_status {
	GENERAL = 'G',
	IN_D_QUOTE = 'D',
	IN_S_QUOTE = 'S'
}	t_status;

/* -- PARSING STRUCT -- */
typedef struct s_parse {
	char	*new_str;
	int		in_d_quote;
	int		in_s_quote;
	char	*str_char;
	char	type_q;
}	t_parse;

/* -- ENVIRONEMNT STRUCT -- */
typedef struct s_env {
	char			*key;
	char			*value;
	struct s_env	*next;
}	t_env;

/* -- LEXER -- */
typedef struct s_lex {
	char			*string;
	int				len;
	t_status		state;
	t_token			type;
	struct s_lex	*next;
}	t_lex;

typedef struct s_lex_helper {
	int		in_s_quote;
	int		in_d_quote;
	t_lex	*lexer;
	t_lex	*lex;
}	t_lex_helper;

/* -- COMMAND STRUCT -- */
typedef struct s_cmd
{
	char			*path;
	char			*cmd;
	t_env			*env;
	char			**args;
	struct s_cmd	*next;
}	t_cmd;

/* -- GLOBAL DATA STRUCT -- */
typedef struct s_data {
	t_env	*env;
}	t_data;

#endif