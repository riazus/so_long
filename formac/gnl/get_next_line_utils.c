/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jannabel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 21:02:34 by jannabel          #+#    #+#             */
/*   Updated: 2021/11/16 21:03:10 by jannabel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_read_line(int fd, char *saved_read_line)
{
	char	*buffer;
	int		count;

	count = 1;
	buffer = malloc(BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	while (!(ft_strchr_gnl(saved_read_line, '\n')) && count != 0)
	{
		count = read(fd, buffer, BUFFER_SIZE);
		if (count == -1)
		{
			free(buffer);
			return (NULL);
		}
		buffer[count] = '\0';
		saved_read_line = modified_ft_strjoin(saved_read_line, buffer);
	}
	free(buffer);
	return (saved_read_line);
}

char	*modified_ft_strjoin(char *s1, char *s2)
{
	char	*news1;
	size_t	i;
	size_t	j;

	i = -1;
	j = 0;
	if (!s1)
	{
		s1 = malloc(1);
		s1[0] = '\0';
	}
	if (!s1 || !s2)
		return (NULL);
	news1 = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (news1 == NULL)
		return (NULL);
	while (s1[++i] != '\0')
		news1[i] = s1[i];
	while (s2[j] != '\0')
		news1[i++] = s2[j++];
	news1[ft_strlen(s1) + ft_strlen(s2)] = '\0';
	free(s1);
	return (news1);
}

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_strchr_gnl(char *s, int c)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	if (c == '\0')
		return ((char *)&s[ft_strlen(s)]);
	while (s[i] != '\0')
	{
		if (s[i] == (char) c)
			return ((char *)&s[i]);
		i++;
	}
	return (0);
}

char	*ft_cut_read_line(char *saved_read_line)
{
	int		i;
	int		j;
	char	*new_saved_read_line;
	int		len;

	i = 0;
	while (saved_read_line[i] && saved_read_line[i] != '\n')
		i++;
	if (!saved_read_line[i])
	{
		free(saved_read_line);
		return (NULL);
	}
	len = ft_strlen(saved_read_line);
	new_saved_read_line = malloc(len - i + 1);
	if (!new_saved_read_line)
		return (NULL);
	i++;
	j = 0;
	while (saved_read_line[i])
		new_saved_read_line[j++] = saved_read_line[i++];
	new_saved_read_line[j] = '\0';
	free(saved_read_line);
	return (new_saved_read_line);
}
