/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jannabel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/29 16:44:04 by jannabel          #+#    #+#             */
/*   Updated: 2022/01/29 16:44:10 by jannabel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <sys/types.h>
# include <fcntl.h>
# include "../gnl/get_next_line.h"
# include "../libft/libft.h"
# include "../minilibx/mlx.h"

# define SUCCESS 1
# define FAIL 0
# define ERROR -1
# define IMG_SIZE 60
# define NAME "so_long"
# define PLAYER "assets/hockey/player.xpm"
# define COLLECT "assets/hockey/collect.xpm"
# define FLOOR "assets/hockey/floor.xpm"
# define EXIT "assets/hockey/exit.xpm"
# define WALL "assets/hockey/wall2.xpm"

typedef struct s_map
{
	int		fd;
	int		line_count;
	size_t	line_len;
	int		count_p;
	int		count_e;
	int		count_c;
	char	*path;
	char	**map;
	int		can_exit;
	int		collected;

}				t_map;

typedef struct s_img
{
	void	*mlx_img;
	int		width;
	int		height;
	void	*wall;
	void	*exit;
	void	*floor;
	void	*player;
	int		line_length;
	void	*collect;

}	t_img;

typedef struct s_vars
{
	void	*mlx;
	void	*win;
	int		steps_count;
	int		p_i;
	int		p_j;
	int		i;
	int		j;
	int		win_height;
	int		win_width;
	t_img	img;
	t_map	map;

}				t_vars;

int		check_ber(char *str, t_vars *vars);
int		line_number(char *path, t_vars *vars);
void	create_map(char *path, t_vars *vars);
void	put_input_in_map(int row, int column, int i, t_vars *vars);
void	ft_free(char **tab);
void	ft_exit(t_vars *vars);
int		handle_exit(t_vars *vars);
void	parse_map(t_vars *vars);
void	init_map(t_vars *vars);
void	init_player(t_vars *vars);
void	error_msg(char *str, t_vars *vars);
int		ft_strchr_long(char *s, int c);
int		check_map(t_vars *vars);
int		check_chars(t_vars *vars);
int		check_rectangle(t_vars *vars);
int		check_edges(int line_count, char **map);
int		check_top_bot(int row, char **map);
int		render(t_vars *vars);
void	parse_chars(t_vars *vars, int width, int i, int j);
int		init_window(t_vars *vars);
int		put_img(t_vars *vars);
void	init_images(t_vars *vars);
void	loop_images(t_vars vars);
int		take_handle(int keysym, t_vars *vars);
void	move_msg(t_vars *vars);
void	move_player(t_vars *vars, char direction);
void	collect_coins(t_vars *vars, char direction);
int		check_next_tile(t_vars *vars, char direction, char tile);

#endif
