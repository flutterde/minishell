/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ochouati <ochouati@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 14:12:59 by ochouati          #+#    #+#             */
/*   Updated: 2024/07/04 16:27:04 by ochouati         ###   ########.fr       */
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
# include <unistd.h>
# include <errno.h>

# define S_QUOTE 39 // '
# define D_QUOTE 34 // "

# include <sys/wait.h>

void	ft_init(int ac, char **av, char **env, t_env *envs);
void	ft_exit(char *msg, int status, int fd);

/* -- PARSING PART -- */
// utils
char	**initial_split_line(char *line);
char	*parse_quote(t_data *data, char *str);
t_lex	*lex_create_node(char *str, t_token type, int len, t_status status);
t_lex	*lex_getlast(t_lex *lst);
void	lex_add_back(t_lex **list, t_lex *new);

/* -->> ENV_LINKED_LISTS <<-- */
/*			ENV					*/
t_env	*ls_create_env(char *key, char *val);
t_env	*ls_last_env(t_env *lst);
void	ls_add2end_env(t_env **lst, t_env *new);
void	ls_clear_env(t_env **lst);
int		size_env(t_env *lst);
t_env	*dup_env(char **env);
void	ls_delete1_env(t_env *node);
int		removeif_env(t_env **head, char *key);
t_env	*search_env(t_env *head, char *key);
t_env	*get_prev_env(t_env *head, t_env *node);

/* -> HELPERS FUNCTIONS <- */
void	ft_errno(int nbr);
char	*get_cmd_path(char *path, char *cmd);
char	**env_lst_to_2dchar(t_env *lst);
void	_print_env(t_env *env);
int		ft_export_no_args(t_env *env);
t_cmd	*set_data(t_env *env, char *path, char **args, char *cmd);

/* -- SRCS -- */
void	ft_execve(t_cmd *cmd);

/* -- BUILT-IN PART -- */
// TODO:: handle this case (in export): (key="vghvhv"), the (") will displayed as a value
void	_print_env(t_env *env);
int		ft_export(t_env **lst, char *str);
// int		ft_pwd(t_env *env);
int		ft_echo(t_cmd *cmd, char *str);
int		pwd_cmd(void);

#endif