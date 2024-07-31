/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboujama <mboujama@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 11:14:48 by ochouati          #+#    #+#             */
/*   Updated: 2024/07/31 15:22:27 by mboujama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

static char	*generate_path(void)
{
	char	*path;
	char	*rand;

	rand = ft_random(30);
	if (!rand)
		return (NULL);
	path = ft_strjoin(ft_strdup("/tmp/.minishell_"), rand);
	if (!path)
		return (free(rand), NULL);
	return (free(rand), path);
}

int	_open_file(t_data *data, t_redir *node)
{
	int		fd;
	char	*path;

	if (!node)
		return (-1);
	path = generate_path();
	fd = open(path, O_CREAT | O_TRUNC | O_RDWR);
	if (fd < 0)
		return (free(path), -1);
	if (node->is_last)
		return (free(path), fd);
	return (close(fd), free(path), -2);
}

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
	fd = open(NULL, O_CREAT | O_TRUNC | O_RDWR, 0666);
	if (fd < 0)
	{
		perror("Error");
		return (free(path), -1);
	}
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