/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   atoi.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jannabel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 19:16:13 by jannabel          #+#    #+#             */
/*   Updated: 2021/10/23 19:04:42 by jannabel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	long	res;
	long	sing;
	int		i;

	sing = 1;
	res = 0;
	i = 0;
	while (str[i] == 32 || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == 43 || str[i] == 45)
	{
		if (str[i++] == 45)
			sing *= -1;
	}	
	while (ft_isdigit(str[i]))
	{		
		res = (res * 10) + (str[i++] - '0');
		if (res < 0)
		{
			if (sing < 0)
				return (0);
			return (-1);
		}
	}
	return (res * sing);
}
