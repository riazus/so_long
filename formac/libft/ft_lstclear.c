/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jannabel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/23 16:25:06 by jannabel          #+#    #+#             */
/*   Updated: 2021/10/23 19:36:46 by jannabel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*p;

	if (lst)
	{
		while (*lst)
		{
			p = (*lst)-> next;
			ft_lstdelone(*lst, del);
			*lst = p;
		}
		lst = NULL;
	}
}
