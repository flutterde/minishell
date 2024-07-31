/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ochouati <ochouati@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 11:14:48 by ochouati          #+#    #+#             */
/*   Updated: 2024/07/31 12:05:57 by ochouati         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

// static char	*generate_path(void)
// {
// 	char	*path;
// 	char	*rand;

// 	rand = ft_random(20);
// 	if (!rand)
// 		return (NULL);
// 	path = ft_strjoin(ft_strdup("/tmp/.minishell_"), rand);
// 	if (!path)
// 		return (free(rand), NULL);
// 	return (free(rand), path);
// }

// int	_open_file(t_data *data, t_redir *node)
// {
// 	int		fd;

// 	if (!node)
// 		return (-1);
	
	
	
// }

int	openherdoc_file()
{
	char	*path;
	char	*rd;
	char	*rand;
	int		fd;

	rand = ft_random(20);
	if (!rand)
		return (-1);
	ft_printf("the random: %s.\n", rand);
	path = ft_strjoin(ft_strdup("/tmp/.minishell_"), rand);
	if (!path)
		return (free(rand), -1);
	ft_printf("the path: %s.\n", path);
	fd = open(path, O_CREAT | O_TRUNC | O_RDWR, 0666);
	if (fd < 0)
		return (free(path), -1);
	ft_putstr_fd("Herdoc_> ", 1);
	rd = get_next_line(0);
	while (rd)
	{
		ft_putstr_fd(rd, fd);
		free(rd); //! use ft_free
		rd = NULL;
		ft_putstr_fd("Herdoc_> ", 1);
		rd = get_next_line(0);
	}
	dup2(fd, STDOUT_FILENO);
	unlink(path);
	return (close(fd), fd);
}

int	main()
{
	ft_printf("the FD: %d.\n", openherdoc_file());
}