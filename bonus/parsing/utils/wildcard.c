/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wildcard.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboujama <mboujama@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/06 16:17:13 by ochouati          #+#    #+#             */
/*   Updated: 2024/08/05 15:46:43 by mboujama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

static int	is_matching(char *wcard, char *file)
{
	if (*wcard == '\0' && *file == '\0')
		return (0);
	if (*wcard == WILD_C)
	{
		if (!is_matching(wcard + 1, file) 
			|| (*file != '\0' && !is_matching(wcard, file + 1)))
			return (0);
		else
			return (1);
	}
	if (*wcard == *file)
		return (is_matching(wcard + 1, file + 1));
	return (1);
}

static void	_ft_help(t_wild_help *wild_h, char *str)
{
	while (wild_h->entry)
	{
		if (ft_strlen(str) == 1 && str[0] == WILD_C
			&& wild_h->entry->d_name[0] == '.')
		{
			wild_h->entry = readdir(wild_h->dir);
			continue ;
		}
		else if (!is_matching(str, wild_h->entry->d_name))
		{
			wild_h->tmp = wild_h->files;
			wild_h->files
				= insert_to2d_array(wild_h->files, wild_h->entry->d_name);
			if (wild_h->tmp)
				ft_free_strs(wild_h->tmp);
		}
		wild_h->entry = readdir(wild_h->dir);
	}
}

char	**ft_wildcard(char *str, char *dir_path)
{
	t_wild_help		wild_h;

	if (!str || !dir_path)
		return (ft_free((void **) &str), NULL);
	wild_h.dir = opendir(dir_path);
	if (!wild_h.dir)
		return (ft_printf("Can't open it\n"), ft_free((void **) &str), NULL);
	wild_h.entry = readdir(wild_h.dir);
	wild_h.files = NULL;
	_ft_help(&wild_h, str);
	closedir(wild_h.dir);
	return (ft_free((void **) &str), wild_h.files);
}

void	old_value_many(char **args)
{
	int	i;
	int	j;

	i = 0;
	while (args && args[i])
	{
		j = 0;
		while (args[i][j])
		{
			if (args[i][j] == WILD_C)
				args[i][j] = '*';
			j++;
		}
		i++;
	}
}

int	wildcard_pattern(t_data *data)
{
	t_wildcard	wild;

	ft_bzero(&wild, sizeof(t_wildcard));
	wild.cmd = data->command;
	while (wild.cmd)
	{
		wild.i = 0;
		if (!ft_strcmp("export", wild.cmd->cmd))
		{
			old_value_many(wild.cmd->args);
			wild.cmd = wild.cmd->next;
			continue ;
		}
		while (wild.cmd->args && wild.cmd->args[wild.i])
		{
			if (ft_strchr(wild.cmd->args[wild.i], WILD_C))
				if (!expand_wildcard(&wild))
					return (0);
			wild.i++;
		}
		if (!get_new_args(&wild))
			return (0);
		wild.cmd = wild.cmd->next;
	}
	return (1);
}
