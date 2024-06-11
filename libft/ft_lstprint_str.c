/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstprint_str.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ochouati <ochouati@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/03 21:04:04 by ochouati          #+#    #+#             */
/*   Updated: 2024/02/03 21:04:07 by ochouati         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstprint_str(t_list *head)
{
	while (head)
	{
		ft_printf("%s\n", head->content);
		head = head->next;
	}
}
