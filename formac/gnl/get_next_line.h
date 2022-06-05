/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jannabel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 21:02:43 by jannabel          #+#    #+#             */
/*   Updated: 2021/11/16 21:02:46 by jannabel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>
# include "../srcs/so_long.h"
# define BUFFER_SIZE 1

char	*get_next_line(int fd);
char	*ft_read_line(int fd, char *saved_read_line);
char	*ft_output_line(char *saved_read_line);
char	*ft_cut_read_line(char	*saved_read_line);
char	*ft_strchr_gnl(char *s, int c);
char	*modified_ft_strjoin(char *s1, char *s2);
size_t	ft_strlen(const char *s);

#endif
