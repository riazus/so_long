/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memset.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jannabel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/06 20:08:25 by jannabel          #+#    #+#             */
/*   Updated: 2021/10/13 16:13:14 by jannabel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*b_buf;
	unsigned char	c_buf;

	b_buf = (unsigned char *)b;
	c_buf = (unsigned char)c;
	while (len > 0)
	{
		*b_buf = c_buf;
		b_buf++;
		len--;
	}
	return (b);
}
