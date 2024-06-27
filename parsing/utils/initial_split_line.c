/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initial_split_line.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboujama <mboujama@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 13:11:35 by mboujama          #+#    #+#             */
/*   Updated: 2024/06/27 16:35:02 by mboujama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

static int	next_quote(char *str, char type)
{
	int	i;

	if (!str)
		return (0);
	i = -1;
	while (str[i] != type)
		i++;
	return (i);
}

int	count_words(char *s, char sep, char type)
{
	int	count;
	int	i;

	count = 0;
	i = 0;
	while (s[i])
	{
		if (s[i] == sep)
			i++;
		else
		{
			printf("-----> new word <-----\n");
			while (s[i] && s[i] != sep)
			{
				printf("%d %c\n", i, s[i]);
				if (s[i] == type)
				{
					//? skip until the next quote.
					i += next_quote(&s[i], type);
					printf("next quote in ==> %d\n", i);
				}
				i++;
			}
			printf();
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

char	**smart_split(char *line)
{
	char	**tab;
	char	type; // is there '' or "" ?

	type = get_type(line);
	printf("type == %c\n", type);
	printf("%d\n", count_words(line, '|', type));
	tab = (char **) malloc(sizeof(char *) * count_words(line, '|', type));
	if (!tab)
		return (0);
	return (tab);
}

char	**initial_split_line(char *line)
{
	char	**tab;

	if (!line)
		return (NULL);
	tab = ft_split(line, '|');
	if (ft_strchr(line, '\'') || ft_strchr(line, '\"'))
		tab = smart_split(line);
	else
		tab = ft_split(line, '|');
	ft_print_strs(tab);
	return (tab);
}
