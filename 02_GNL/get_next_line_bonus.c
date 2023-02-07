/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeaugra <abeaugra@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/27 19:40:08 by ddupont           #+#    #+#             */
/*   Updated: 2022/03/31 21:55:25 by ddupont          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

static char	*init_buff(int fd, char *buff)
{
	char	*tmp;
	int		bytes_rd;

	tmp = malloc(sizeof(*tmp) * (BUFFER_SIZE + 1));
	if (!tmp)
		return (NULL);
	bytes_rd = 1;
	while (!nl_isin(buff) && bytes_rd)
	{
		bytes_rd = read(fd, tmp, BUFFER_SIZE);
		if (bytes_rd == -1)
		{
			free(tmp);
			return (NULL);
		}
		tmp[bytes_rd] = '\0';
		buff = ft_strjoin(buff, tmp);
	}
	free(tmp);
	return (buff);
}

static char	*get_line(char *buff)
{
	size_t	i;
	char	*line;
	size_t	j;

	if (!*buff)
		return (NULL);
	i = 0;
	while (buff[i] && (buff[i] != '\n'))
		i++;
	line = malloc(sizeof(*line) * (i + 2));
	if (!line)
		return (NULL);
	j = -1;
	while (buff[++j] && j <= i)
		line[j] = buff[j];
	line[j] = '\0';
	return (line);
}

static char	*update_buff(char *buff)
{
	size_t	i;
	char	*new_buff;
	size_t	j;

	i = 0;
	while (buff[i] && (buff[i] != '\n'))
		i++;
	if (!buff[i])
	{
		free(buff);
		return (NULL);
	}
	new_buff = malloc(sizeof(*new_buff) * (ft_strlen(buff) - i + 1));
	if (!new_buff)
		return (NULL);
	j = 0;
	while (buff[++i])
		new_buff[j++] = buff[i];
	new_buff[j] = '\0';
	free(buff);
	return (new_buff);
}

char	*get_next_line(int fd)
{
	static char	*buff[1024];
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buff[fd] = init_buff(fd, buff[fd]);
	if (!buff[fd])
		return (NULL);
	line = get_line(buff[fd]);
	buff[fd] = update_buff(buff[fd]);
	return (line);
}
