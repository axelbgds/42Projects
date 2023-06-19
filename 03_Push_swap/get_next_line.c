/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeaugra <abeaugra@student.42perp.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 21:28:38 by abeaugra          #+#    #+#             */
/*   Updated: 2023/06/19 21:30:57 by abeaugra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_strchr(char *str)
{
	int	index;

	index = 0;
	if (!str)
		return (0);
	while (str[index])
	{
		if (str[index] == '\n')
			return (1);
		index++;
	}
	return (0);
}

static inline char
	*ft_strjoin(char *s1, char *s2, int i, int j)
{
	char	*str;

	if (!s1)
	{
		s1 = (char *)malloc(sizeof(char));
		s1[0] = '\0';
	}
	while (s1[i])
		i++;
	while (s2[j])
		j++;
	str = (char *)malloc(sizeof(char) * (i + j + 1));
	i = -1;
	j = 0;
	if (!str)
		return (NULL);
	while (++i, s1[i])
		str[i] = s1[i];
	while (s2[j++] != '\0')
		str[i - 1 + j] = s2[j - 1];
	str[i + j - 1] = '\0';
	free(s1);
	return (str);
}

static inline char
	*ft_new_create_buffer(char *buffer, int index, int jndex)
{
	char	*res;
	int		len;

	len = 0;
	while (buffer[len])
		len++;
	while (buffer[index] && buffer[index] != '\n')
		index++;
	if (!buffer[index])
	{
		free(buffer);
		return (NULL);
	}
	res = (char *)malloc(sizeof(char) * (len - index + 1));
	if (!res)
		return (NULL);
	index++;
	while (buffer[index])
		res[jndex++] = buffer[index++];
	res[jndex] = '\0';
	free(buffer);
	return (res);
}

static inline char
	*ft_create_buffer(char *buffer, int buff_size, int fd, int *index)
{
	char	*temp;

	*index = 0;
	temp = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!temp)
		return (NULL);
	while ((buff_size != 0 && !ft_strchr(buffer)))
	{
		buff_size = read(fd, temp, BUFFER_SIZE);
		if (buff_size == -1)
		{
			free(temp);
			return (NULL);
		}
		temp[buff_size] = '\0';
		buffer = ft_strjoin(buffer, temp, 0, 0);
	}
	free(temp);
	if (buffer[0] == 0)
	{
		free(buffer);
		return (NULL);
	}
	return (buffer);
}

char	*get_next_line(int fd)
{
	static char	*buffer;
	char		*line;
	int			index;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = ft_create_buffer(buffer, 1, fd, &index);
	if (!buffer)
		return (NULL);
	while (buffer[index] && buffer[index] != '\n')
		index++;
	line = (char *)malloc(sizeof(char) * (index + 2));
	if (!line)
		return (NULL);
	index = -1;
	while (buffer[++index] && buffer[index] != '\n')
		line[index] = buffer[index];
	if (buffer[index] == '\n')
	{
		line[index] = buffer[index];
		index++;
	}
	line[index] = '\0';
	buffer = ft_new_create_buffer(buffer, 0, 0);
	return (line);
}
