/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minor_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jannabel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/29 16:40:00 by jannabel          #+#    #+#             */
/*   Updated: 2022/01/29 16:40:45 by jannabel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_exit(t_vars *vars)
{
	mlx_destroy_window(vars->mlx, vars->win);
	vars->win = NULL;
	if (vars->map.can_exit == 1 && vars->map.map[vars->p_i][vars->p_j] == 'E')
		printf("Congratulations you did it!!!\n");
	else
		printf("Good bye!\n");
	exit(1);
}

int	handle_exit(t_vars *vars)
{
	mlx_destroy_window(vars->mlx, vars->win);
	vars->win = NULL;
	printf("Good bye!\n");
	exit (1);
}

void	move_msg(t_vars *vars)
{
	printf("Step count: %d\n", vars->steps_count);
}

void	error_msg(char *str, t_vars *vars)
{
	if (vars->map.map)
		ft_free(vars->map.map);
	printf("!!!ERROR!!!\n%s\n", str);
	exit (1);
}

int	ft_strchr_long(char *s, int c)
{
	while (*s && *s != (char)c)
		s++;
	if (*s == (char)c)
		return (SUCCESS);
	return (FAIL);
}	
