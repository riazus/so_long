/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calloc.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jannabel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 15:09:26 by jannabel          #+#    #+#             */
/*   Updated: 2021/10/19 19:58:39 by jannabel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	char			*buf;
	size_t			total;
	unsigned int	i;

	total = count * size;
	buf = malloc(total);
	if (buf == NULL)
		return (NULL);
	i = 0;
	while (total > 0)
	{
		buf[i] = 0;
		total--;
		i++;
	}
	return ((void *)buf);
}
