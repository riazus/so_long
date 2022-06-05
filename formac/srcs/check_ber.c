/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_ber.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jannabel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 14:57:19 by jannabel          #+#    #+#             */
/*   Updated: 2022/02/02 15:43:37 by jannabel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_ber(char *str, t_vars *vars)
{
	int	i;

	i = ft_strlen(str) - 1;
	while (str[i])
	{
		if (str[i] != 'r')
			error_msg("file mast be .ber", vars);
		i--;
		if (str[i] != 'e')
			error_msg("file mast be .ber", vars);
		i--;
		if (str[i] != 'b')
			error_msg("file mast be .ber", vars);
		i--;
		if (str[i] != '.')
			error_msg("file mast be .ber", vars);
		i--;
		if (str[i] == '/')
			error_msg("it's a hidden file", vars);
		return (SUCCESS);
	}
	return (FAIL);
}
