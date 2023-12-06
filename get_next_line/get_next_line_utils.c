/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttaquet <ttaquet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 15:15:18 by ttaquet           #+#    #+#             */
/*   Updated: 2023/12/06 15:06:25 by ttaquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strlen(char	*str)
{
	int	i;

	i = 0;
	if (str == NULL)
		return (0);
	while (*str)
	{
		i++;
		str++;
	}
	return (i);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*res;
	int		i;
	int		j;

	i = 0;
	j = 0;
	res = malloc((ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!res)
		return (NULL);
	while (s1[j])
	{
		res[i] = s1[j];
		j++;
		i++;
	}
	j = 0;
	while (s2[j])
	{
		res[i] = s2[j];
		j++;
		i++;
	}
	res[i] = '\0';
	free(s1);
	return (res);
}

char	*ft_calloc(int	nmemb, int	size)
{
	char	*bmem;
	int			i;

	i = 0;
	bmem = malloc((nmemb) * size);
	if (!bmem)
		return (NULL);
	while (i < (nmemb) * size)
	{
		bmem[i] = 0;
		i++;
	}
	return (bmem);
}

int	ft_not_in(char	*str, char	c)
{
	int	i;

	i = 0;
	if (str == NULL)
		return (-1);
	while (str[i])
	{
		if (str[i] == c)
			return (i);
		i++;
	}
	return (-1);
}

char	*ft_strcpy(char *dst, char *src)
{
	int	i;

	i = 0;
	while (src[i])
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (dst);
}


// int main(){
// 	printf("%d",ft_strlen("asdsaf,asfq"));
// }