/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jannabel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/29 16:20:36 by jannabel          #+#    #+#             */
/*   Updated: 2022/01/31 17:52:21 by jannabel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	init_window(t_vars *vars)
{
	vars->mlx = mlx_init();
	if (vars->mlx == NULL)
		return (ERROR);
	vars->win = mlx_new_window(vars->mlx, vars->win_width,
			vars->win_height, NAME);
	if (vars->win == NULL)
	{
		free(vars->win);
		return (ERROR);
	}
	return (SUCCESS);
}

int	put_img2(t_vars *vars)
{
	vars->img.collect[0] = mlx_xpm_file_to_image(vars->mlx, COLLECT,
			&vars->img.width, &vars->img.height);
	vars->img.collect[1] = mlx_xpm_file_to_image(vars->mlx, COLLECT1,
			&vars->img.width, &vars->img.height);
	vars->img.collect[2] = mlx_xpm_file_to_image(vars->mlx, COLLECT2,
			&vars->img.width, &vars->img.height);
	vars->img.collect[3] = mlx_xpm_file_to_image(vars->mlx, COLLECT3,
			&vars->img.width, &vars->img.height);
	vars->img.hater = mlx_xpm_file_to_image(vars->mlx, HATER,
			&vars->img.width, &vars->img.height);
	if (!vars->img.collect[0])
		return (FAIL);
	else if (!vars->img.collect[1])
		return (FAIL);
	else if (!vars->img.collect[2])
		return (FAIL);
	else if (!vars->img.collect[3])
		return (FAIL);
	else if (!vars->img.hater)
		return (FAIL);
	return (SUCCESS);
}

int	put_img1(t_vars *vars)
{
	vars->img.floor = mlx_xpm_file_to_image(vars->mlx, FLOOR,
			&vars->img.width, &vars->img.height);
	vars->img.exit = mlx_xpm_file_to_image(vars->mlx, EXIT,
			&vars->img.width, &vars->img.height);
	vars->img.player = mlx_xpm_file_to_image(vars->mlx, PLAYER,
			&vars->img.width, &vars->img.height);
	vars->img.wall = mlx_xpm_file_to_image(vars->mlx, WALL,
			&vars->img.width, &vars->img.height);
	if (!vars->img.floor)
		return (FAIL);
	else if (!vars->img.exit)
		return (FAIL);
	else if (!vars->img.player)
		return (FAIL);
	else if (!vars->img.wall)
		return (FAIL);
	return (SUCCESS);
}

void	init_images(t_vars *vars)
{
	if (!put_img1(vars))
		error_msg("Incorrect image", vars);
	else if (!put_img2(vars))
		error_msg("Incorrect image", vars);
}

void	loop_images(t_vars vars)
{
	mlx_loop_hook(vars.mlx, &update_frames, &vars);
	mlx_key_hook(vars.win, take_handle, &vars);
	mlx_hook(vars.win, 17, 1L << 0, ft_exit, &vars);
	mlx_loop(vars.mlx);
}
