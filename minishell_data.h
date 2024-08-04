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
# define EXIT_ERR ": numeric argument required\n"

# define M_IGNORE -2 
# define M_FAIL  -1

int	g_status;

/* -- ENUMS -- */
typedef enum e_token {
	W_SPACE = ' ',
	QUOTE = '\'',
	DOUBLE_QUOTE = '"',
	PIPELINE = '|',
	REDIR_IN = '<',
	REDIR_OUT = '>',
	HEREDOC,
	SUPER_HEREDOC,
	APPEND,
	WORD = -1,
	ENV = '$',
}	t_token;

typedef enum s_status {
	GENERAL = 'G',
	IN_D_QUOTE = 'D',
	IN_S_QUOTE = 'S',
	END = 'E'
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
typedef struct s_quote
{
	int		nb_s_quote;
	int		nb_d_quote;
	int		in_s_quote;
	int		in_d_quote;
	t_lex	*tmp;
}	t_quote;

typedef struct s_expand {
	t_lex	*tmp_lex;
	t_env	*found;
	char	*key;
	char	*tmp;
}	t_expand;

typedef struct s_lex_env {
	char	*str;
	char	*ch;
}	t_lex_env;

/* -- REDIRECTION STRUCT -- */
typedef struct s_redir {
	t_token			type;
	int				index;
	int				is_last;
	bool			to_expand;
	bool			is_ambiguous;
	char			*file;
	char			*delim;
	char			*path;
	struct s_redir	*next;
	struct s_redir	*prev;
}	t_redir;

typedef struct s_red_help {
	t_token	tp;
	char	*file;
	char	*delim;
	bool	expand;
	bool	ambiguous;
	int		index;
	int		is_last;
}	t_red_help;

/* -- COMMAND STRUCT -- */
typedef struct s_cmd
{
	t_redir			*redire;
	t_env			*env;
	char			*path;
	char			*cmd;
	char			**args;
	bool			is_builtin;
	int				red_fd[2];
	struct s_cmd	*next;
}	t_cmd;

typedef struct s_cmd_utils
{
	t_cmd		*cmd;
	t_redir		*redir;
	char		**args;
	char		**tmp_args;
	char		*str;
	bool		is_ambiguous;
	bool		is_builtin;
	bool		heredoc_expand;
	char		*file;
	char		*delim;
	t_token		type;
}	t_cmd_utils;

typedef struct s_exec
{
	t_cmd	*cmd;
	int		fd[2];
	int		count;
	int		fd_stdin;
	int		i;
	int		fails;
}	t_exec;

/* -- GLOBAL DATA STRUCT -- */
typedef struct s_data {
	t_env		*env;
	t_lex		*lexer;
	int			last_exit;
	uint32_t	npipes;
	int			*childs;
	t_cmd		*command;
	int			sigint;
}	t_data;

#endif