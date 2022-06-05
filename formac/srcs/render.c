/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jannabel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/29 16:43:24 by jannabel          #+#    #+#             */
/*   Updated: 2022/01/29 16:43:50 by jannabel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	parse_chars(t_vars *vars, int width, int i, int j)
{
	if (vars->map.map[i][j] == '1')
		mlx_put_image_to_window(vars->mlx, vars->win, vars->img.wall,
			width, i * IMG_SIZE);
	else if (vars->map.map[i][j] == 'P')
		mlx_put_image_to_window(vars->mlx, vars->win, vars->img.player,
			width, i * IMG_SIZE);
	else if (vars->map.map[i][j] == 'E')
		mlx_put_image_to_window(vars->mlx, vars->win, vars->img.exit,
			width, i * IMG_SIZE);
	else if (vars->map.map[i][j] == '0')
		mlx_put_image_to_window(vars->mlx, vars->win, vars->img.floor,
			width, i * IMG_SIZE);
	else if (vars->map.map[i][j] == 'C')
		mlx_put_image_to_window(vars->mlx, vars->win, vars->img.collect,
			width, i * IMG_SIZE);
}

int	render(t_vars *vars)
{
	int	i;
	int	j;
	int	width;

	i = 0;
	while (vars->map.map[i])
	{
		j = 0;
		width = 0;
		while (vars->map.map[i][j] != '\n' && vars->map.map[i][j])
		{
			parse_chars(vars, width, i, j);
			width += IMG_SIZE;
			j++;
		}
		i++;
	}
	return (SUCCESS);
}
