/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   head.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboujama <mboujama@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/29 10:55:32 by mboujama          #+#    #+#             */
/*   Updated: 2024/06/29 11:01:20 by mboujama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEAD_H
# define HEAD_H

# define COL_RED "\033[0;91m"
# define END_COL "\033[0m"
# include "../libft/libft.h"
# include <stdio.h>
# include <stdbool.h>
# include <stdlib.h>
# include <unistd.h>
# include <errno.h>
# include <readline/history.h>
# include <readline/readline.h>

typedef struct s_cmd {
	struct s_cmd	*next;
	char			*path;
	char			*cmd;
}	t_cmd;

char	*cmd_path(char *path, char *cmd);
int		parse_quote(char *str);

#endif
