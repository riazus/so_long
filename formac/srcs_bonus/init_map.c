/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jannabel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/29 16:17:19 by jannabel          #+#    #+#             */
/*   Updated: 2022/01/29 16:17:22 by jannabel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_player(t_vars *vars)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (vars->map.map[i])
	{
		while (vars->map.map[i][j])
		{
			if (vars->map.map[i][j] == 'P')
			{
				vars->p_i = i;
				vars->p_j = j;
			}
			j++;
		}
		j = 0;
		i++;
	}
}

void	init_map(t_vars *vars)
{
	vars->i = 0;
	vars->j = 0;
	vars->map.count_p = 0;
	vars->map.count_e = 0;
	vars->map.count_c = 0;
	vars->map.collected = 0;
	vars->map.can_exit = 0;
	vars->steps_count = 0;
	vars->win_height = vars->map.line_count * IMG_SIZE;
	vars->win_width = (ft_strlen(vars->map.map[0]) - 1) * IMG_SIZE;
	vars->img.height = IMG_SIZE;
	vars->img.width = IMG_SIZE;
}
