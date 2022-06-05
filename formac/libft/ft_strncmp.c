/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strncmp.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jannabel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/09 10:07:45 by jannabel          #+#    #+#             */
/*   Updated: 2021/10/22 10:42:29 by jannabel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

int	ft_strncmp(const char *str1, const char *str2, size_t n)
{
	size_t	i;
	int		res;

	i = 0;
	res = 0;
	while ((str1[i] || str2[i]) && i < n)
	{
		res = ((unsigned char *)str1)[i] - ((unsigned char *)str2)[i];
		if (res != 0)
			return (res);
		i++;
	}
	return (res);
}
