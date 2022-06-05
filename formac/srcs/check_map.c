/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jannabel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/29 16:36:17 by jannabel          #+#    #+#             */
/*   Updated: 2022/01/29 16:38:48 by jannabel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_chars(t_vars *vars)
{
	while (vars->map.map[vars->i])
	{
		vars->j = 0;
		while (vars->map.map[vars->i][vars->j])
		{
			if (vars->map.map[vars->i][vars->j] == 'C')
				vars->map.count_c++;
			else if (vars->map.map[vars->i][vars->j] == 'P')
				vars->map.count_p++;
			else if (vars->map.map[vars->i][vars->j] == 'E')
				vars->map.count_e++;
			vars->j++;
		}
		vars->i++;
	}
	if (!vars->map.count_c || !vars->map.count_p || !vars->map.count_e)
		return (FAIL);
	else
		return (SUCCESS);
}

int	check_rectangle(t_vars *vars)
{
	int		i;
	size_t	j;

	i = 0;
	vars->map.line_len = ft_strlen(vars->map.map[i]) - 1;
	while (vars->map.map[i])
	{
		j = 0;
		while (vars->map.map[i][j] && vars->map.map[i][j] != '\n')
			j++;
		if (j != vars->map.line_len)
			return (FAIL);
		i++;
	}
	return (SUCCESS);
}

int	check_top_bot(int row, char **map)
{
	int	i;

	i = 0;
	while (map[row][i] && map[row][i] != '\n')
	{
		if (map[row][i] != '1')
			return (FAIL);
		i++;
	}
	return (SUCCESS);
}

int	check_edges(int line_count, char **map)
{
	int	i;
	int	j;

	i = 1;
	j = ft_strlen(map[0]) - 2;
	if (!check_top_bot(0, map)
		&& !check_top_bot(line_count, map))
		return (FAIL);
	while (i < line_count)
	{
		if ((map[i][0] != '1') || (map[i][j] != '1'))
			return (FAIL);
		i++;
	}
	return (SUCCESS);
}

int	check_map(t_vars *vars)
{
	int		i;
	size_t	j;

	i = 0;
	while (vars->map.map[i])
	{
		j = 0;
		while (j < ft_strlen(vars->map.map[i]) - 1)
		{
			if (!ft_strchr_long("01CPE", vars->map.map[i][j]))
				error_msg("Invalid type item", vars);
			j++;
		}
		i++;
	}
	if (!check_chars(vars))
		error_msg("In game must be min 1 P,E,C!", vars);
	if (vars->map.count_p > 1)
		error_msg("In game must be only 1 player(", vars);
	if (!check_rectangle(vars))
		error_msg("MAP MUST BE RECTANGLE!!!!", vars);
	if (!check_edges(vars->map.line_count, vars->map.map))
		error_msg("Check map's edge", vars);
	return (SUCCESS);
}
