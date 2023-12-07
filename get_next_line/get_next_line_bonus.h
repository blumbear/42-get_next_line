/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttaquet <ttaquet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 15:31:12 by ttaquet           #+#    #+#             */
/*   Updated: 2023/12/07 15:06:57 by ttaquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
# include <stdio.h>
# include <limits.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1000000
# endif

# define MAX_FD 128

char	*get_next_line(int fd);
char	*ft_read2buff(char *line, char *buffer, int fd);
char	*ft_strjoin(char *s1, char *s2);
int		ft_not_in(char	*str, char c);
char	*ft_calloc(int memb, int size);
char	*ft_strcpy(char *dst, char *src);

#endif