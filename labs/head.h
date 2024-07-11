/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   head.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ochouati <ochouati@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/29 10:55:32 by mboujama          #+#    #+#             */
/*   Updated: 2024/07/09 17:00:19 by ochouati         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEAD_H
# define HEAD_H

# define COL_RED "\033[0;91m"
# define END_COL "\033[0m"
# include "../libft/libft.h"
# include <stdio.h>
# include <stdbool.h>
# include <string.h>
# include <stdlib.h>
# include <unistd.h>
# include <errno.h>
# include <readline/history.h>
# include <readline/readline.h>

#define CHAR1 1

typedef struct s_cmd {
	struct s_cmd	*next;
	char			*path;
	char			*cmd;
}	t_cmd;

typedef enum {
	OR,
	AND,
	END,
} t_next_type;

typedef struct s_lst {
	char			*tmp;
	struct s_lst	*head;
	struct s_lst	*left;
	struct s_lst	*right;
	t_next_type		next_type;
}	t_lst;

char	*cmd_path(char *path, char *cmd);
int		parse_quote(char *str);

#endif
