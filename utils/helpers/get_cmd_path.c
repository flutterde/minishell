/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_cmd_path.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboujama <mboujama@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 12:32:00 by ochouati          #+#    #+#             */
/*   Updated: 2024/07/27 15:26:08 by mboujama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

char	*get_cmd_path(char *path, char *cmd)
{
	char	*new;
	char	**spl;
	int		i;

	if (!path || !cmd)
		return (NULL);
	spl = ft_split(path, ':');
	if (!spl)
		return (NULL);
	i = 0;
	while (spl[i])
	{
		new = ft_strjoin3(spl[i], "/", cmd);
		if (!new)
			return (ft_free_strs(spl), NULL);
		if (!access(new, X_OK))
			return (ft_free_strs(spl), new);
		free(new);
		i++;
	}
	return (ft_free_strs(spl), NULL);
}
