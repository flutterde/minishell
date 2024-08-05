/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboujama <mboujama@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 14:12:59 by ochouati          #+#    #+#             */
/*   Updated: 2024/08/05 12:07:15 by mboujama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# define M_NAME "\033[0;92mminishell$\033[0m "
# include "../libft/libft.h"
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
# include <signal.h>

void		ft_exit(char *msg, int status, int fd);
void		clear_data(t_data **data);
void		data_cleanup(t_data **data, bool all);

/* -- PARSING PART -- */
int			parsing(t_data *data, char *line);
t_lex		*create_lexer(char *line);
int			join_lexer(t_data *data);
// utils
t_status	_status(t_lex_helper lex);
void		lex_red_in(t_lex_helper *lex, char **line);
void		lex_red_out(t_lex_helper *lex, char **line);
void		lex_env(t_lex_helper *lex, char **line);
void		lex_word(t_lex_helper *lex, char **line);
int			check_syntax(t_lex *lex);
int			consec_spaces(t_lex *str, t_token token);
int			rev_consec_spaces(t_lex *lex, t_token token);
int			check_chars_env(t_lex *lex);
int			quotes_check(t_lex *lex);
int			ft_expander(t_data *data, t_lex *lexer);
int			is_redirection(t_lex *lex);
int			fill_redirect(t_lex **lex, t_cmd_utils *utils);
char		*get_str(t_lex **lex);
void		print_linked_list(t_cmd *cmd);
int			is_builtin(char *cmd);
bool		ft_is_newln(char *op);
char		*get_arg(t_lex **lex);
int			add_arg_helper(t_cmd_utils *utils, char **str);
void		get_last_in(t_redir *last);
void		get_last_out(t_redir *last);
void		lex_env_helper(t_lex_env *e_h, char **line);
void		swap_data(t_red_help red, t_redir *b);
char		*get_file_amb(t_lex **lex, t_cmd_utils *utils);
int			consec_quote_rev(t_lex *lex, t_token token);
int			consec_quote(t_lex *lex, t_token token);
void		left_space(t_lex **lex, t_cmd_utils *utils);
void		right_space(t_lex **lex, t_cmd_utils *utils);
// void		only_space(t_lex **lex, t_cmd_utils *utils);
// lists
t_lex		*lex_getlast(t_lex *lst);
t_lex		*lex_create(char *str, t_token type, int len, t_status status);
void		lex_add_back(t_lex **list, t_lex *new);
void		lex_delete_node(t_lex *node);
void		lex_clear_list(t_lex **list);
// bonus - wildcards
void		search_rep_asterisk(t_lex *lex);
char		**ft_wildcard(char *str, char *dir_path);
int			wildcard_pattern(t_data *data);
int			expand_wildcard(t_wildcard *wild);
int			get_new_args(t_wildcard *wild);

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
char		**env__to_2dchar(t_env *lst);
void		_print_env(t_env *env);
int			ft_export_no_args(t_env *env);
t_cmd		*set_data(t_env *env, char *path, char **args, char *cmd);
void		ft_print_lexer(t_lex *lex);
char		*print_token(t_token token);

/* -- SRCS -- */
void		ft_execve(t_cmd *cmd);
int			out_handler(t_redir *red);
int			redire_handler(t_data *data, t_redir *redire, int	*fd);

/* -- BUILT-IN PART -- */
void		_print_env(t_env *env);
int			ft_export(t_env **lst, char *str);
// int			ft_pwd(t_env *env);
int			ft_echo(t_cmd *cmd, t_data *data);
int			pwd_cmd(void);
char		*ft_cd(char *arg);
void		cd_handler(t_env *env, char *path);
int			unset_handler(t_cmd *cmd, t_data *data);
void		exit_handler(t_data *data, t_cmd *cmd);
int			export_handler(t_cmd *cmd, t_data *data);

// CMD LIST 
void		cmd_delete1(t_cmd *node);
void		cmd_clear(t_cmd **lst);
t_cmd		*cmd_create(t_data *data, t_cmd_utils *utils);
t_cmd		*cmd_getlast(t_cmd *lst);
void		cmd_addback(t_cmd **lst, t_cmd *new);
int			cmd_lstsize(t_cmd *lst);

// REDIR List
t_redir		*red_create(t_cmd_utils *utils);
t_redir		*red_getlast(t_redir *lst);
void		red_addback(t_redir **lst, t_redir *new);
t_redir		*red_last_withtype(t_redir *lst, t_token tp);
void		red_delete1(t_redir *node);
void		red_clear(t_redir **lst);
void		red_sort(t_redir *lst);
void		mark_last(t_redir *lst);
void		_reset_utils(t_cmd_utils *utils);
// REDIRECTIONS UTILS
char		*__generate_path(void);
int			ft_heredoc(t_data *data, t_redir *node, int *redfd);
void		exec_redirections(t_data *data, t_cmd *cmd, t_exec exec);
void		_close_fds(int fd1, int fd2);
int			__out_handler_copy(t_redir *redire, int *redfd);
int			_open_in_copy(t_redir *node, int *redfd);
void		_reopen_fds(t_redir *node, int *fds);
void		_child_redirloop(t_redir	*tmp, int *ints, t_data *data,
				int *red_fd);
void		ft_free(void **ptr);

// EXECUTION
void		exec_handler(t_data *data);
int			s_builtin_handler(t_data *data);
void		exists_and_permissions(t_cmd *cmd);
void		child_builtin_cmd(t_data *data, t_cmd *cmd);
void		_child_prs(t_data *data, t_cmd *cmd, t_exec exec);
void		__err_msg(char *msg, int nbr);
void		__redirections_wrapper(t_data *data);

// testing
int			ve_handler(t_data *data, char *prompt);
void		handle_sigint(int sig);
void		sig_hear(int s);

#endif
