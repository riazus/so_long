/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jannabel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/29 16:09:15 by jannabel          #+#    #+#             */
/*   Updated: 2022/02/02 15:44:06 by jannabel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_haters(char **map)
{
	int	i;
	int	j;
	int	haters;

	i = 0;
	haters = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'H')
				haters++;
			j++;
		}
		i++;
	}
	if (!haters)
		return (FAIL);
	return (SUCCESS);
}

int	check_all(t_vars *vars)
{
	int		i;
	size_t	j;

	i = 0;
	while (vars->map.map[i])
	{
		j = 0;
		while (j < ft_strlen(vars->map.map[i]) - 1)
		{
			if (!ft_strchr_long("01CPEH", vars->map.map[i][j]))
				return (FAIL);
			j++;
		}
		i++;
	}
	return (SUCCESS);
}

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
