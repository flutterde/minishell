// ! this is for testing only


#include "../minishell.h"

void	create_tmp_data(t_data *data)
{
	t_cmd	*cmd;

	data->command = cmd;
	cmd_addback(&data->command, cmd_create(ft_split("ls -la", ' '), data));
	cmd_addback(&data->command, cmd_create(ft_split("gerp main.c", ' '), data));
	cmd_addback(&data->command, cmd_create(ft_split("awk '{print$1}'", ' '), data));
}


void	__handler_exc(t_data *data)
{
	int	fd[2];
	int	size;
	int	*childs;
	int	i;
	int	s;

	size = cmd_lstsize(data->command);
	if (!size)
		return ;
	i = 0;
	childs = malloc(sizeof(int) * size);
	if (!childs)
		return ;
	while (i < size)
	{
		s = pipe(fd);
		if (s == -1)
		{
			perror("Error:");
			data->last_exit = 1;
			return ;
		}

	}
	
}