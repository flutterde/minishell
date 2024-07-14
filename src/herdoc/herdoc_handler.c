/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   herdoc_handler.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ochouati <ochouati@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/13 18:38:36 by ochouati          #+#    #+#             */
/*   Updated: 2024/07/14 14:56:30 by ochouati         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

void	herdoc_handler(t_data *data, char *eof)
{
	int		fd;
	char	*fl;
	char	*str;

	fl = ft_random(30);
	if (!fl)
		return ;
	fd = open(fl, O_RDWR | O_CREAT | O_APPEND);
	str = get_next_line(0);
	while (ft_strcmp(str, eof))
	{
		write(fd, str, ft_strlen(str));
		free(str);
		str = get_next_line(0);
	}
	
}
