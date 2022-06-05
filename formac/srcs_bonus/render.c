/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jannabel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/29 16:26:44 by jannabel          #+#    #+#             */
/*   Updated: 2022/01/29 16:27:59 by jannabel         ###   ########.fr       */
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
		mlx_put_image_to_window(vars->mlx, vars->win, vars->img.current_col,
			width, i * IMG_SIZE);
	else if (vars->map.map[i][j] == 'H')
		mlx_put_image_to_window(vars->mlx, vars->win, vars->img.hater,
			width, i * IMG_SIZE);
}

void	put_step_counts(t_vars *vars)
{
	char	*str;
	int		x;

	x = vars->map.line_len * IMG_SIZE / 2;
	str = step_conter(vars);
	mlx_string_put(vars->mlx, vars->win, x, 20, 1, str);
	free(str);
}

int	update_frames(t_vars *vars)
{
	static int	frames;

	if (frames == 15)
		vars->img.current_col = vars->img.collect[0];
	else if (frames == 30)
		vars->img.current_col = vars->img.collect[1];
	else if (frames == 45)
		vars->img.current_col = vars->img.collect[2];
	else if (frames == 60)
		vars->img.current_col = vars->img.collect[3];
	else if (frames == 75)
		frames = 0;
	frames++;
	render(vars);
	return (SUCCESS);
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
	put_step_counts(vars);
	return (SUCCESS);
}
