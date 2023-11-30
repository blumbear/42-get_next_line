/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttaquet <ttaquet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 15:06:50 by ttaquet           #+#    #+#             */
/*   Updated: 2023/11/30 16:39:45 by ttaquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
# include <stdio.h>
# include <string.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 4
# endif

char	*get_next_line(int fd);
int		ft_strlen(char	*str);
void	*ft_realloc(void *ptr, size_t size);
void	*ft_memmove(void	*dest, const void	*src, size_t	n);
void	*ft_memcpy(void	*dest, const void	*src, size_t	n);

/**
 * @brief search c in str
 * 
 * @param str where we search c
 * @param c the caracter who are search
 * @return whether or not c in str and his position
 */
int		not_in(char *str, char c);

#endif