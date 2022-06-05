/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jannabel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/29 16:26:08 by jannabel          #+#    #+#             */
/*   Updated: 2022/01/29 16:26:28 by jannabel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_free(char **tab)
{
	size_t	i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
	tab = NULL;
	return ;
}

int	line_number(char *path, t_vars *vars)
{
	int		fd;
	char	*line;
	int		line_count;

	line_count = 0;
	fd = open(path, O_RDONLY);
	if (fd < 0)
		error_msg("Error open file", vars);
	else
	{
		line = get_next_line(fd);
		while (line != NULL)
		{
			line_count++;
			free(line);
			line = get_next_line(fd);
		}
		close(fd);
	}
	return (line_count);
}

void	put_input_in_map(int row, int column, int i, t_vars *vars)
{
	char	*line;

	if ((read(vars->map.fd, 0, 0)) == -1)
		return (error_msg("It's directory", vars));
	line = get_next_line(vars->map.fd);
	while (line != NULL)
	{
		vars->map.map[row] = ft_calloc(ft_strlen(line) + 1, sizeof(char));
		if (!vars->map.map[row])
			return (ft_free(vars->map.map));
		while (line[i] != '\0')
			vars->map.map[row][column++] = line[i++];
		vars->map.map[row++][column] = '\0';
		column = 0;
		i = 0;
		free(line);
		line = get_next_line(vars->map.fd);
	}
	vars->map.map[row] = NULL;
}

void	create_map(char *path, t_vars *vars)
{
	int		row;
	int		i;
	size_t	column;

	i = 0;
	row = 0;
	column = 0;
	vars->map.line_count = line_number(path, vars);
	vars->map.path = path;
	vars->map.map = ft_calloc(vars->map.line_count + 1, sizeof(char *));
	if (!(vars->map.map))
		return ;
	vars->map.fd = open(path, O_RDONLY);
	if (vars->map.fd < 0)
		error_msg("Error open file", vars);
	else
	{
		put_input_in_map(row, column, i, vars);
		close(vars->map.fd);
	}
}
