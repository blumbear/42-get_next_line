/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttaquet <ttaquet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 15:06:39 by ttaquet           #+#    #+#             */
/*   Updated: 2023/11/22 16:47:55 by ttaquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_add_buffer(char	*buffer, char	*res)
{
	char	*tmp;
	int		i;

	tmp = malloc((ft_strlen(buffer) + ft_strlen(res) + 1) * sizeof(char));
	i = 0;
	while (*res)
	{
		tmp[i++] = *res;
		res++;
	}
	while (*buffer)
	{
		tmp[i++] = *buffer;
		buffer++;
	}
	tmp[i] = '\0';
	return (tmp);
}

int	ft_lines_end(char	*buffer)
{
	int	i;

	i = 0;
	while (buffer[i])
	{
		if (buffer[i] == '\n')
			return (i + 1);
		i++;
	}
	return (BUFFER_SIZE);
}

char	*get_next_line(int fd)
{
	static char	*buffer;
	char		*res;
	char		*tmp;
	int			i;

	buffer = malloc(BUFFER_SIZE * sizeof(char));
	res = malloc(BUFFER_SIZE * sizeof(char));
	while (read (fd, buffer, BUFFER_SIZE)
		&& ft_lines_end (buffer) != BUFFER_SIZE)
	{
		tmp = *&res;
		res = ft_add_buffer(buffer, res);
		free (tmp);
	}
	i = 0;
	tmp = malloc(ft_lines_end(buffer) + 1);
	while (buffer[i] && buffer[i] != '\n')
	{
		tmp[i] = buffer[i];
		i++;
	}
	tmp[i] = buffer[i];
	res = ft_add_buffer(tmp, res);
	return (res);
}
int main(){
	int	fd = open("test.txt", O_RDONLY);
	printf("%s\n",get_next_line(fd));
	printf("%s\n",get_next_line(fd));
	printf("%s\n",get_next_line(fd));
	printf("%s\n",get_next_line(fd));
	printf("%s\n",get_next_line(fd));
	printf("%s\n",get_next_line(fd));
	printf("%s\n",get_next_line(fd));
	printf("%s\n",get_next_line(fd));
	printf("%s\n",get_next_line(fd));
	printf("%s\n",get_next_line(fd));
	printf("%s\n",get_next_line(fd));
	printf("%s\n",get_next_line(fd));
	printf("%s\n",get_next_line(fd));
	printf("%s\n",get_next_line(fd));
	printf("%s\n",get_next_line(fd));
	printf("%s\n",get_next_line(fd));
}