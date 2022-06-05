/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jannabel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 21:01:53 by jannabel          #+#    #+#             */
/*   Updated: 2021/11/16 21:02:24 by jannabel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_output_line(char *saved_read_line)
{
	int		i;
	char	*line;

	i = 0;
	if (!saved_read_line[i])
		return (NULL);
	while (saved_read_line[i] && saved_read_line[i] != '\n')
		i++;
	line = malloc(i + 2);
	if (!line)
		return (NULL);
	i = 0;
	while (saved_read_line[i] && saved_read_line[i] != '\n')
	{
		line[i] = saved_read_line[i];
		i++;
	}
	if (saved_read_line[i] == '\n')
	{
		line[i] = '\n';
		i++;
	}
	line[i] = '\0';
	return (line);
}

char	*get_next_line(int fd)
{
	static char	*saved_read_line;
	char		*output_line;

	if (BUFFER_SIZE <= 0 || fd < 0)
		return (NULL);
	saved_read_line = ft_read_line(fd, saved_read_line);
	if (!saved_read_line)
		return (NULL);
	output_line = ft_output_line(saved_read_line);
	saved_read_line = ft_cut_read_line(saved_read_line);
	return (output_line);
}
