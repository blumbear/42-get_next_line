/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttaquet <ttaquet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 15:33:50 by ttaquet           #+#    #+#             */
/*   Updated: 2023/11/29 17:31:26 by ttaquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_start(char buffer[BUFFER_SIZE])
{
	int		i;
	int		tmp;

	i = 0;
	while (buffer[i] && buffer[i] != '\n')
		i++;
	tmp = buffer[i] == '\n';
	ft_memmove(buffer, &buffer[i + tmp], BUFFER_SIZE);
	return (tmp);
}

char	*add_buffer_to_res(char	*res, char buffer[BUFFER_SIZE])
{
	int	i;
	int	j;

	i = ft_strlen(res);
	j = 0;
	while (buffer[j] && buffer[j] != '\n')
	{
		res[i] = buffer[j];
		i++;
		j++;
	}
	res[i++] = buffer[j];
	res[i] = '\0';
	return (res);
}

char	*get_next_line(int fd)
{
	static char	buffer[BUFFER_SIZE];
	char		*res;
	int			read_test;

	res = NULL;
	if (ft_start(buffer) == 1)
	{
		res = ft_realloc(res, (ft_strlen(buffer) + 1) * sizeof(char));
		add_buffer_to_res(res, buffer);
	}
	read_test = read (fd, buffer, BUFFER_SIZE);
	while (read_test && not_in(buffer, '\n'))
	{
		res = ft_realloc(res, (ft_strlen(res) + BUFFER_SIZE + 1) * sizeof(char));
		add_buffer_to_res(res, buffer);
		read_test = read (fd, buffer, BUFFER_SIZE);
	}
	if (!read_test && (buffer[0] == '\0' || not_in(buffer, EOF)))
		return (res);
	if (buffer[0] != '\0' && (not_in(res, '\n') || res == NULL))
	{
		res = ft_realloc(res, (ft_strlen(res) + BUFFER_SIZE + 1) * sizeof(char));
		add_buffer_to_res(res, buffer);
	}
	return (res);
}

// int main(){
// 	int	fd = open("test.txt", O_RDONLY);
// 	char	*test = NULL;
// 	for (int i = 0; i < 7; i++)
// 	{
// 		test = get_next_line(fd);
// 		if (test == NULL)
// 			printf("(null)\n--\n");
// 		else
// 			printf("%s--\n",test);
// 	}
// }