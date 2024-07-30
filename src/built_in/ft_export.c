/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ochouati <ochouati@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 15:44:57 by ochouati          #+#    #+#             */
/*   Updated: 2024/07/30 13:17:56 by ochouati         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

// ! export 
int	ft_export(t_env **lst, char *str)
{
	char	*key;
	char	*value;
	char	*tmp;

	if (!lst || !str)
		return (0);
	tmp = ft_strchr(str, '=');
	if (!tmp)
	{
		ls_add2end_env(lst, ls_create_env(ft_strdup(str), NULL));
		return (0);
	}
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

static int	___iva(char *str)
{
	int	i;

	i = 0;
	while (str && str[i])
	{
		if (!ft_isalnum(str[i]) && str[i] != '_')
			return (0);
		i++;
	}
	return (1);
}

static int	_is_valid(char *str)
{
	char	*tmp;
	char	*tmp2;
	int		i;

	tmp2 = ft_strchr(str, '=');
	if (!tmp2)
	{
		if (str && ((str[0] != '_' && !ft_isalpha(str[0]))
				|| !___iva(&str[1])))
			return (-1);
		return (0);
	}
	tmp = ft_substr(str, 0, (ft_strlen(str) - ft_strlen(tmp2)));
	if (!tmp)
		return (-1);
	if (tmp[0] != '_' && !ft_isalpha(tmp[0]))
		return (free(tmp), -1);
	i = 1;
	while (tmp[i])
	{
		if (!ft_isalnum(tmp[i]) && tmp[i] != '_')
			return (free(tmp), -1);
		i++;
	}
	return (free(tmp), 1);
}

//! check this test exit status:   export a=bjb b=jfbb c=hjfhjfhj -d
//! ==> hgfhgfhg=fhbfjbfnbn
int	export_handler(t_cmd *cmd, t_data *data)
{
	char	**args;
	int		i;

	i = 1;
	if (!cmd || !data || !cmd->args)
		return (0);
	args = cmd->args;
	if (args[0] && !args[1])
		return (ft_export_no_args(data->env), 1);
	while (args[i])
	{
		if (_is_valid(args[i]) < 0)
		{
			g_status = 1;
			mini_printf(2, "export: `%s': not a valid identifier\n", args[i]);
		}
		else
		{
			g_status = 0;
			ft_export(&data->env, args[i]);
		}
		i++;
	}
	return (1);
}
