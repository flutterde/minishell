/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initial_split_line.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboujama <mboujama@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 13:11:35 by mboujama          #+#    #+#             */
/*   Updated: 2024/06/28 11:18:34 by mboujama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

static int	len_word(char *str, char type)
{
	int	i;
	int	in_qt;

	i = 0;
	in_qt = 0;
	while (str[i] && (str[i] != '|' || in_qt))
	{
		if (str[i] == type)
			in_qt = !in_qt;
		i++;
	}
	return (i);
}

static int	count_words(char *s, char sep, char type)
{
	int	count;
	int	i;
	int	in_qt;

	count = 0;
	in_qt = 0;
	i = 0;
	while (s[i])
	{
		if (s[i] == sep && !in_qt)
			i++;
		else
		{
			while (s[i] && (s[i] != sep || in_qt))
			{
				if (s[i] == type)
					in_qt = !in_qt;
				i++;
			}
			count++;
		}
	}
	return (count);
}

static char	get_type(char *line)
{
	if (ft_strchr(line, '\''))
		return ('\'');
	if (ft_strchr(line, '\"'))
		return ('\"');
	return (0);
}


static char	**smart_split(char *line)
{
	char	**tab;
	char	type;
	int		len;
	int		tab_i;

	type = get_type(line);
	tab = (char **) malloc(sizeof(char *) * count_words(line, '|', type) + 1);
	if (!tab)
		return (0);
	tab_i = 0;
	while (*line)
	{
		if (*line == '|')
			line++;
		else
		{
			len = len_word(line, type);
			tab[tab_i] = ft_substr(line, 0, len);
			line += len;
			tab_i++;
		}
	}
	tab[tab_i] = NULL;
	return (tab);
}

char	**initial_split_line(char *line)
{
	char	**tab;
	int		i;

	i = 0;
	if (!line)
		return (NULL);
	if (ft_strchr(line, '\'') || ft_strchr(line, '\"'))
		tab = smart_split(line);
	else
		tab = ft_split(line, '|');
	while (tab[i])
	{
		tab[i] = ft_strtrim(tab[i], " ");
		i++;
	}
	ft_print_strs(tab);
	return (tab);
}
