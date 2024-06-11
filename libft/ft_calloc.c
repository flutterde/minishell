/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ochouati <ochouati@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 15:20:56 by ochouati          #+#    #+#             */
/*   Updated: 2023/12/22 17:15:48 by ochouati         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*data;
	size_t	i;

	i = count * size;
	if (count != 0 && (i / count) < size)
		return (NULL);
	data = malloc(size * count);
	if (!data)
		return (NULL);
	ft_bzero(data, count * size);
	return (data);
}
