/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttaquet <ttaquet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 15:33:50 by ttaquet           #+#    #+#             */
/*   Updated: 2023/11/25 17:13:55 by ttaquet          ###   ########.fr       */
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
		i++;
		buffer++;
	}
	return (res);
}


// modifier buffer pour supprimer tt ce qu'il y a avant le premier '\n' et 
// renvoyer tt ce qu'il y a entre le premier et le deuxieme '\n'
//donc pouvoir afficher les ligne une a une et ne pas affciher pls fois la meme
char	*ft_start(char	buffer[BUFFER_SIZE], char	*res)
{
	while (*buffer)
	{

	}
}

char	*get_next_line(int fd)
{
	static char	buffer[BUFFER_SIZE];
	char		*res;

	res = NULL;
	res = ft_start(buffer, *&res);
	while(read (fd, buffer, BUFFER_SIZE) && !end_of_line(buffer))
	{
		res = ft_realloc(res, (size_t)(ft_strlen(res) + BUFFER_SIZE + 1) * sizeof(char));
		add_buffer_to_res(res, buffer);
		res[ft_strlen(res)] = '\0';
	}
	res = ft_realloc(res, (size_t)(ft_strlen(res) + BUFFER_SIZE + 1) * sizeof(char));
	add_buffer_to_res(res, buffer);
	res[ft_strlen(res)] = '\0';
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
}