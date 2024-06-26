/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ochouati <ochouati@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 15:44:57 by ochouati          #+#    #+#             */
/*   Updated: 2024/06/26 16:25:10 by ochouati         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

int	ft_export(t_env **lst, char *str)
{
	char	*key;
	char	*value;
	char	*tmp;

	if (!lst || !*lst || !str)
		return (0);
	tmp = ft_strchr(str, '=');
	if (!tmp)
		return (0);
	key = ft_substr(str, 0, (ft_strlen(str) - ft_strlen(tmp)));
	value = ft_strdup(tmp + 1);
	tmp = value;
	value = ft_strtrim(tmp, "\"");
	free(tmp);
	if (!key || !value)
		return (0);
	removeif_env(lst, key);
	ls_add2end_env(lst, ls_create_env(key, value));
	return (1);
}
