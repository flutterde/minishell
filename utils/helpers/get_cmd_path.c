/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_cmd_path.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ochouati <ochouati@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 12:32:00 by ochouati          #+#    #+#             */
/*   Updated: 2024/06/27 12:01:09 by ochouati         ###   ########.fr       */
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
		if (!access(new, X_OK)) // make sure the permissions are right
			return (ft_free_strs(spl), new);
		free(new);
		i++;
	}
	return (ft_free_strs(spl), NULL);
}
