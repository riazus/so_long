/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jannabel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/29 16:17:41 by jannabel          #+#    #+#             */
/*   Updated: 2022/01/29 16:18:20 by jannabel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	t_vars	vars;

	if (argc == 2)
	{
		check_ber(argv[1], &vars);
		create_map(argv[1], &vars);
		init_map(&vars);
		check_map(&vars);
		init_player(&vars);
		init_window(&vars);
		init_images(&vars);
		render(&vars);
		loop_images(vars);
		free(vars.mlx);
		if (vars.map.map)
			ft_free(vars.map.map);
	}
	else
		ft_putstr_fd("Please, write 2 arguments\n", 1);
}
