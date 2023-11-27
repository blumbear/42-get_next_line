/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttaquet <ttaquet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 15:33:50 by ttaquet           #+#    #+#             */
/*   Updated: 2023/11/27 16:20:13 by ttaquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	end_of_line(char	buffer[BUFFER_SIZE])
{
	while (*buffer)
	{
		if (*buffer == '\n')
			return (1);
		buffer++;
	}
	return (0);
}

char	*add_buffer_to_res(char	*res, char	buffer[BUFFER_SIZE])
{
	int	i;

	i = ft_strlen(res);
	while (*buffer && *buffer != '\n')
	{
		res[i] = *buffer;
		buffer++;
		i++;
	}
	return (res);
}

int	ft_start(char	buffer[BUFFER_SIZE])
{
	int		i;
	int		tmp;

	i = 0;
	while (buffer[i] && buffer[i] != '\n')
		i++;
	tmp = 1;
	if (buffer[i] != '\n')
		tmp = 0;
	i++;
	//printf("&%s\n",buffer);
	ft_memmove(buffer, &buffer[i], BUFFER_SIZE - i);
	return (tmp);
}

char	*get_next_line(int fd)
{
	static char	buffer[BUFFER_SIZE];
	char		*res;
	int			read_test;

	res = NULL;
	res = ft_realloc(res, (BUFFER_SIZE + 1) * sizeof(char));
	if (ft_start(buffer) == 1)
		read_test = read (fd, buffer, BUFFER_SIZE);
	while(read (fd, buffer, BUFFER_SIZE) && !end_of_line(buffer))
	{
		res = ft_realloc(res, (ft_strlen(res) + BUFFER_SIZE + 1) * sizeof(char));
		add_buffer_to_res(res, buffer);
		res[ft_strlen(res)] = '\0';
	}
	if (!read_test && buffer[0] == '\0')
		return (NULL);
	res = ft_realloc(res, (ft_strlen(res) + BUFFER_SIZE + 1) * sizeof(char));
	add_buffer_to_res(res, buffer);
	res[ft_strlen(res)] = '\0';
	return (res);
}

int main(){
	int	fd = open("test.txt", O_RDONLY);
	// get_next_line(fd);
	// get_next_line(fd);
	// get_next_line(fd);
	// get_next_line(fd);
	// get_next_line(fd);
	// get_next_line(fd);
	// get_next_line(fd);
	printf("%s\n",get_next_line(fd));
	printf("%s\n",get_next_line(fd));
	printf("%s\n",get_next_line(fd));
	printf("%s\n",get_next_line(fd));
	printf("%s\n",get_next_line(fd));
	printf("%s\n",get_next_line(fd));
	printf("%s\n",get_next_line(fd));
}