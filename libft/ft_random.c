/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_random.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ochouati <ochouati@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/26 16:52:37 by ochouati          #+#    #+#             */
/*   Updated: 2024/08/01 13:14:21 by ochouati         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	fill_buffer(char *buf)
{
	char	c;
	int		i;

	c = 'a';
	i = 0;
	while (c <= 'z' && i <= 61)
		buf[i++] = c++;
	c = '0';
	while (c <= '9' && i <= 61)
		buf[i++] = c++;
	c = 'A';
	while (c <= 'Z' && i <= 61)
		buf[i++] = c++;
}

static size_t	_getrand_ptr(void)
{
	char	*ptr;
	
	ptr = malloc(1);
	if (!ptr)
		return (0);
	return (free(ptr), (size_t)ptr);
}

char	*ft_random(int size)
{
	char	buffer[62];
	char	*nstr;
	size_t	*ad;
	size_t	num;
	int		i;

	fill_buffer(buffer);
	ad = (size_t *)&buffer + _getrand_ptr();
	nstr = malloc(size + 1);
	if (!nstr)
		return (NULL);
	num = (size_t) nstr;
	i = 0;
	nstr[size] = '\0';
	while (i < size)
	{
		nstr[i++] = buffer[num % 61];
		num += ((size_t) & num / (5676 + i));
	}
	return (nstr);
}
