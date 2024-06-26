#ifndef HEAD_H
# define HEAD_H

# define COL_RED "\033[0;91m"
# define END_COL "\033[0m"
# include "../libft/libft.h"
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
#include <errno.h>


typedef struct s_cmd {
	struct s_cmd	*next;
	char			*path;
	char			*cmd;
}	t_cmd;

char	*cmd_path(char *path, char *cmd);

#endif