/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ochouati <ochouati@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 15:29:37 by ochouati          #+#    #+#             */
/*   Updated: 2023/12/23 14:38:26 by ochouati         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	c_words(char *str, char c)
{
	int	i;
	int	cw;

	i = 0;
	cw = 0;
	while (str[i])
	{
		while (str[i] && str[i] == c)
			i++;
		if (str[i])
			cw++;
		while (str[i] && str[i] != c)
			i++;
	}
	return (cw);
}

static int	w_len(char *str, char c)
{
	int	i;

	i = 0;
	while (str[i] && (str[i] != c))
		i++;
	return (i);
}

static char	*full_ptr(char	*str, char *ptr, int n)
{
	int	i;

	i = 0;
	while (i < n)
	{
		ptr[i] = str[i];
		i++;
	}
	ptr[i] = '\0';
	return (ptr);
}

static char	**free_thestr(char **str, int index)
{
	int	i;

	i = 0;
	str[index] = NULL;
	while (str[i])
		free(str[i++]);
	free(str);
	return (NULL);
}

char	**ft_split(char const *s, char c)
{
	int		cw;
	int		i;
	int		j;
	char	**nstr;

	if (!s)
		return (NULL);
	cw = c_words((char *)s, c);
	nstr = malloc(sizeof(char *) * (cw + 1));
	if (!nstr)
		return (0);
	nstr[cw] = NULL;
	i = 0;
	j = -1;
	while (++j < cw)
	{
		while (s[i] && s[i] == c)
			i++;
		nstr[j] = malloc(sizeof(char) * w_len((char *)&s[i], c) + 1);
		if (!nstr[j])
			return (free_thestr(nstr, j));
		full_ptr((char *)&s[i], nstr[j], w_len((char *)&s[i], c));
		i = i + w_len((char *)&s[i], c);
	}
	return (nstr);
}
