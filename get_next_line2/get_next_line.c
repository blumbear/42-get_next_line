/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttaquet <ttaquet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 15:33:50 by ttaquet           #+#    #+#             */
/*   Updated: 2023/11/30 16:50:41 by ttaquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*add_buff_to_line(char	*res, char buffer[BUFFER_SIZE])
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
	static char			buffer[BUFFER_SIZE] = {0};
	char				*line = NULL;
	char				*res;
	int					i;
	
	read(fd, buffer, BUFFER_SIZE);
	while (not_in(line, '\n') && not_in(buffer, EOF))
	{
		line = ft_realloc(line, (ft_strlen(line) + BUFFER_SIZE + 1));
		add_buff_to_line(line, buffer);
		read(fd, buffer, BUFFER_SIZE);
	}
	i = not_in(line, EOF);
	if (not_in(line, EOF) > not_in(line, '\0'))
		i = not_in(line, '\0');
	res = malloc((i + 2) * sizeof(char));
	if(!res)
		return (NULL);
	ft_memcpy(res, line, not_in(line, '\n'));
	ft_memmove(buffer, &line[not_in(buffer, '\n')], not_in(buffer, '\n') + 1);
	return (res);
}

int main(){
	int	fd = open("test.txt", O_RDONLY);
	char	*test = NULL;
	for (int i = 0; i < 7; i++)
	{
		test = get_next_line(fd);
		if (test == NULL)
			printf("(null)\n--\n");
		else
			printf("%s--\n",test);
	}
}