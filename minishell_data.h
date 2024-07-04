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

typedef struct s_env {
	char			*key;
	char			*value;
	struct s_env	*next;
}	t_env;

typedef struct s_cmd
{
	char			*path;
	char			*cmd;
	t_env			*env;
	char			**args;
	struct s_cmd	*next;
}	t_cmd;

typedef struct s_data {
	t_env	*env;
}	t_data;

typedef enum s_cmd_type {
	BUILT_IN,
}	t_cmd_type;

typedef enum e_token {
    WORD = -1,
    WHITE_SPACE = ' ',
    NEW_LINE = '\n',
    QUOTE = '\'',
    DOUBLE_QUOTE = '"', 
    ESCAPE = '\\',
    ENV = '$',
    PIPE_LINE = '|',
    REDIR_IN = '<',
    REDIR_OUT = '>',
    HERE_DOC,
    DREDIR_OUT,
}    t_token;

typedef enum s_status {
    GENERAL,
    IN_D_QUOTE,
    IN_S_QUOTE
}    t_status;

typedef struct s_lex {
	char			*string;
	int				len;
	t_status		state;
	t_token			type;
	struct s_lex	*next;
}	t_lex;

#endif