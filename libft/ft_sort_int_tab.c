/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_int_tab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ochouati <ochouati@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 18:13:20 by ochouati          #+#    #+#             */
/*   Updated: 2024/01/25 18:13:34 by ochouati         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_sort_int_tab(int *tab, int size)
{
	int	i;
	int	j;
	int	min_ix;

	i = 0;
	while (i < size - 1)
	{
		j = i + 1;
		min_ix = i;
		while (j < size)
		{
			if (tab[j] < tab[min_ix])
			{
				min_ix = j;
			}
			j++;
		}
		if (min_ix != i)
		{
			ft_swap(&tab[min_ix], &tab[i]);
		}
		i++;
	}
}
