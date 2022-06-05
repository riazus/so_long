/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jannabel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/29 16:23:21 by jannabel          #+#    #+#             */
/*   Updated: 2022/01/29 16:25:54 by jannabel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	take_handle(int keycode, t_vars *vars)
{
	if (keycode == 53)
		ft_exit(vars);
	else if (keycode == 0)
		keycode = 'a';
	else if (keycode == 1)
		keycode = 's';
	else if (keycode == 2)
		keycode = 'd';
	else if (keycode == 13)
		keycode = 'w';
	if (ft_strchr_long("wasd", keycode))
		move_player(vars, keycode);
	return (FAIL);
}

int	check_next_tile(t_vars *vars, char direction, char tile)
{
	if ((direction == 'd' && vars->map.map[vars->p_i][vars->p_j + 1] == tile)
		|| (direction == 'a' && vars->map.map[vars->p_i][vars->p_j - 1] == tile)
		|| (direction == 's' && vars->map.map[vars->p_i + 1][vars->p_j] == tile)
		|| (direction == 'w' && vars->map.map[vars->p_i - 1][vars->p_j] == tile)
		)
		return (SUCCESS);
	else
		return (FAIL);
}

void	collect_coins(t_vars *vars, char direction)
{
	if ((direction == 'd' && vars->map.map[vars->p_i][vars->p_j + 1] == 'C')
		|| (direction == 'a' && vars->map.map[vars->p_i][vars->p_j - 1] == 'C')
		|| (direction == 's' && vars->map.map[vars->p_i + 1][vars->p_j] == 'C')
		|| (direction == 'w' && vars->map.map[vars->p_i - 1][vars->p_j] == 'C'))
		vars->map.collected++;
}

void	move_player(t_vars *vars, char direction)
{
	if (check_next_tile(vars, direction, '1')
		|| (!vars->map.can_exit && check_next_tile(vars, direction, 'E')))
		return ;
	if (check_next_tile(vars, direction, 'H'))
		return (lose_game(vars));
	vars->steps_count++;
	collect_coins(vars, direction);
	if (vars->map.collected == vars->map.count_c)
		vars->map.can_exit = 1;
	vars->map.map[vars->p_i][vars->p_j] = '0';
	if (direction == 'd')
		vars->p_j++;
	else if (direction == 'a')
		vars->p_j--;
	else if (direction == 's')
		vars->p_i++;
	else if (direction == 'w')
		vars->p_i--;
	if (vars->map.can_exit == 1 && vars->map.map[vars->p_i][vars->p_j] == 'E')
		ft_exit(vars);
	vars->map.map[vars->p_i][vars->p_j] = 'P';
}
