/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ochouati <ochouati@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 19:31:37 by ochouati          #+#    #+#             */
/*   Updated: 2023/12/23 16:47:25 by ochouati         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

typedef struct s_res
{
	int	s_i;
	int	e_i;
	int	size;
}	t_res;

static int	x_is_set(char const *set, char c)
{
	while (*set)
	{
		if (*set == c)
			return (1);
		set++;
	}
	return (0);
}

static void	the_resp(t_res *data, char const *str, char const *set)
{
	int		i;
	int		l;

	i = 0;
	l = ft_strlen(str) - 1;
	while (str[i] && x_is_set(set, str[i]))
		i++;
	data->s_i = i;
	while (l > i && x_is_set(set, str[l]))
		l--;
	data->e_i = l;
	data->size = (data->e_i - data->s_i) + 1;
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		i;
	char	*nstr;
	t_res	data;

	if (!s1 || !set)
		return (NULL);
	the_resp(&data, s1, set);
	i = 0;
	nstr = (char *)malloc(sizeof(char) * data.size + 1);
	if (!nstr)
		return (NULL);
	nstr[data.size] = '\0';
	while (i < data.size)
		nstr[i++] = s1[data.s_i++];
	return (nstr);
}
