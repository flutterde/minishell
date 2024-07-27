/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   herdoc_handler.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboujama <mboujama@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/13 18:38:36 by ochouati          #+#    #+#             */
/*   Updated: 2024/07/27 15:27:15 by mboujama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

void	herdoc_handler(/*t_data *data,*/ char *eof)
{
	int		fd;
	char	*fl0;
	char	*str;
	char	*fl;

	fl0 = ft_random(30);
	if (!fl0)
		return ;
	fl = ft_strjoin(fl0, ".output");
	fd = open(fl, O_RDWR | O_CREAT | O_APPEND, 0666);
	free(fl);
	if (fd < 0)
	{
		ft_putstr_fd("minishell: ", 2);
		ft_putstr_fd(strerror(errno), 2);
		ft_putstr_fd("\n", 2);
		return ;
	}
	ft_putstr_fd("heredoc> ", 1);
	str = get_next_line(0);
	while (1)
	{
		if (!ft_strcmp(str, eof))
		{
			free(str);
			break ;
		}
		write(fd, str, ft_strlen(str));
		free(str);
		ft_putstr_fd("heredoc> ", 1);
		str = get_next_line(0);
	}
}

int	main(void)
{
	herdoc_handler("EOF\n");
	return (0);
}
