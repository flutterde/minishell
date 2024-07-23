/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboujama <mboujama@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 14:12:59 by ochouati          #+#    #+#             */
/*   Updated: 2024/07/23 07:58:44 by mboujama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# define M_NAME "\033[0;92mminishell$\033[0m "
# include "libft/libft.h"
# include "minishell_data.h"
# include <readline/history.h>
# include <readline/readline.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>
# include <errno.h>
# include <dirent.h>
# include <string.h>
# include <sys/wait.h>

void		ft_init(int ac, char **av, char **env, t_env *envs);
void		ft_exit(char *msg, int status, int fd);
void		clear_data(t_data **data);

/* -- PARSING PART -- */
int			parsing(t_data *data, char *line);
t_lex		*create_lexer(char *line);
int			join_lexer(t_data *data);
// utils
char		*handle_spaces(t_parse *parse_dt);
char		get_type(char ch);
int			search_len(char *str);
t_status	_status(t_lex_helper lex);
void		lex_red_in(t_lex_helper *lex, char **line);
void		lex_red_out(t_lex_helper *lex, char **line);
void		lex_env(t_lex_helper *lex, char **line);
void		lex_word(t_lex_helper *lex, char **line);
int			check_syntax(t_data *data, t_lex *lex);
int			consec_spaces(t_lex *str, t_token token);
int			rev_consec_spaces(t_lex *lex, t_token token);
int			check_chars_env(t_lex *lex);
int			quotes_check(t_data *data, t_lex *lex);
int			ft_expander(t_data *data, t_lex *lexer);
int			is_redirection(t_lex *lex);
int			fill_redirect(t_lex **lex, t_cmd_utils *utils);
char		*get_str(t_lex **lex);
void		print_linked_list(t_cmd *cmd);
// lists
t_lex		*lex_getlast(t_lex *lst);
t_lex		*lex_create(char *str, t_token type, int len, t_status status);
void		lex_add_back(t_lex **list, t_lex *new);
void		lex_delete_node(t_lex *node);
void		lex_clear_list(t_lex **list);

/* -- ENV_LINKED_LISTS -- */
// ENV
t_env		*ls_create_env(char *key, char *val);
t_env		*ls_last_env(t_env *lst);
void		ls_add2end_env(t_env **lst, t_env *new);
void		ls_clear_env(t_env **lst);
int			size_env(t_env *lst);
t_env		*dup_env(char **env);
void		ls_delete1_env(t_env *node);
int			removeif_env(t_env **head, char *key);
t_env		*search_env(t_env *head, char *key);
t_env		*get_prev_env(t_env *head, t_env *node);

/* -- HELPERS FUNCTIONS -- */
void		ft_errno(int nbr);
char		*get_cmd_path(char *path, char *cmd);
char		*get_absolute_path(char *path, t_env *env);
char		**env_lst_to_2dchar(t_env *lst);
void		_print_env(t_env *env);
int			ft_export_no_args(t_env *env);
t_cmd		*set_data(t_env *env, char *path, char **args, char *cmd);
void		ft_print_lexer(t_lex *lex);

/* -- SRCS -- */
void		ft_execve(t_cmd *cmd);

/* -- BUILT-IN PART -- */
void		_print_env(t_env *env);
int			ft_export(t_env **lst, char *str);
// int			ft_pwd(t_env *env);
int			ft_echo(t_cmd *cmd, char *str);
int			pwd_cmd(void);
char		*ft_cd(char *arg);
void		cd_handler(t_env *env, char *path);

// CMD LIST 
void		cmd_delete1(t_cmd *node);
void		cmd_clear(t_cmd **lst);
t_cmd		*cmd_create(t_data *data, t_cmd_utils *utils);
t_cmd		*cmd_getlast(t_cmd *lst);
void		cmd_addback(t_cmd **lst, t_cmd *new);
int			cmd_lstsize(t_cmd *lst);

// Rediretions LIST

t_inred		*inred_getlast(t_inred *lst);
t_inred		*inred_create(char *delim, char *file, t_token type, bool to_expand);
void		inred_addback(t_inred **lst, t_inred *new);
void		inred_delete1(t_inred *node);
void		inred_clear(t_inred **lst);

t_outred	*outred_getlast(t_outred *lst);
t_outred	*outred_create(char *file, t_token type);
void		outred_addback(t_outred **lst, t_outred *new);
void		outred_delete1(t_outred *node);
void		outred_clear(t_outred **lst);

void		ft_free(void **ptr);
// testing
int			execve_handler(t_data *data, char *prompt);

#endif
