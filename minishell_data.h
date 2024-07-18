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

# define D_QUOTE 34
# define S_QUOTE 39

/* -- ENUMS -- */
typedef enum e_token {
	ESCAPE = '\\',
	W_SPACE = ' ',
	QUOTE = '\'',
	DOUBLE_QUOTE = '"',
	PIPELINE = '|',
	REDIR_IN = '<',
	REDIR_OUT = '>',
	HEREDOC, // <<
	SUPER_HEREDOC, // << $ ex
	DREDIR_OUT, // >>
	WORD = -1,
	ENV = '$',
}	t_token;

typedef enum s_status {
	GENERAL = 'G',
	IN_D_QUOTE = 'D',
	IN_S_QUOTE = 'S'
}	t_status;

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
	t_status		status;
	t_token			type;
	struct s_lex	*next;
	struct s_lex	*prev;
}	t_lex;

typedef struct s_lex_helper {
	int		in_s_quote;
	int		in_d_quote;
	t_lex	*lexer;
	t_lex	*lex;
}	t_lex_helper;

/* -- PARSING STRUCT -- */
typedef struct s_parse {
	char	*new_str;
	int		in_d_quote;
	int		in_s_quote;
	char	*str_char;
	char	type_q;
}	t_parse;

typedef struct s_quote
{
	int		nb_s_quote;
	int		nb_d_quote;
	int		in_s_quote;
	int		in_d_quote;
	t_lex	*tmp;
}	t_quote;

/* -- REDIRECTION STRUCT -- */
/// @brief herdoc <<, in < 
typedef struct s_in_red {
	t_token			type;
	char			*file;
	char			*delim; // "" | NULL
	bool			to_expand;
	struct s_in_red	*next;
}	t_inred;

typedef struct s_out_red {
	t_token				type;
	char				*file;
	struct s_out_red	*next;
}	t_outred;

/* -- COMMAND STRUCT -- */
typedef struct s_cmd
{
	char			*path;
	char			*cmd;
	t_env			*env;
	char			**args;
	t_outred		*out;
	t_inred			*in;
	bool			is_ambiguous;
	struct s_cmd	*next;
}	t_cmd;

/* -- GLOBAL DATA STRUCT -- */
typedef struct s_data {
	t_env		*env;
	t_lex		*lexer;
	int			last_exit;
	uint32_t	npipes;
	t_cmd		*command;
}	t_data;

#endif