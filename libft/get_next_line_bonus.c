/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ochouati <ochouati@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/03 21:04:58 by ochouati          #+#    #+#             */
/*   Updated: 2024/06/12 12:48:38 by ochouati         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*read_line(char **rest, int fd)
{
	char	*tmp;
	char	*buff;
	int		rb;

	tmp = NULL;
	buff = NULL;
	rb = 1;
	buff = malloc(BUFFER_SIZE + 1);
	if (!buff)
		return (NULL);
	while (!tmp && rb > 0)
	{
		rb = read(fd, buff, BUFFER_SIZE);
		if (rb < 0)
			break ;
		buff[rb] = '\0';
		*rest = _ft_strjoin(*rest, buff);
		tmp = _ft_strchr(buff, '\n');
	}
	free(buff);
	return (*rest);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*rest[1024];
	char		*tmp;
	char		*tmp2;

	line = NULL;
	if (fd < 0 || fd > 1024)
		return (NULL);
	if ((fd <= 2 && fd != 0) || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
		return (free(rest[fd]), rest[fd] = NULL, NULL);
	tmp2 = read_line(&rest[fd], fd);
	tmp = _ft_strchr(rest[fd], '\n');
	if (!tmp)
	{
		line = _ft_strdup(rest[fd]);
		return (free(rest[fd]), rest[fd] = NULL, line);
	}
	else
	{
		line = _substr(rest[fd], tmp + 1);
		tmp2 = rest[fd];
		return (rest[fd] = _ft_strdup(tmp + 1), free(tmp2), line);
	}
	return (NULL);
}
