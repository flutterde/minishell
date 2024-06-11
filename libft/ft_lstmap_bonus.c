/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ochouati <ochouati@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 15:55:44 by ochouati          #+#    #+#             */
/*   Updated: 2023/12/23 17:15:11 by ochouati         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*lnew;
	t_list	*nn;
	void	*f_res;

	if (!lst || !f || !del)
		return (NULL);
	lnew = NULL;
	while (lst)
	{
		f_res = f(lst->content);
		nn = ft_lstnew(f_res);
		if (!nn)
		{
			del(f_res);
			ft_lstclear(&lnew, del);
			return (NULL);
		}
		ft_lstadd_back(&lnew, nn);
		lst = lst->next;
	}
	return (lnew);
}
