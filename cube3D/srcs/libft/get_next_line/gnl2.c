/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl2.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeaugra <abeaugra@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 15:35:11 by alsaez            #+#    #+#             */
/*   Updated: 2023/09/18 22:07:24 by abeaugra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char	*ft_strcpy(char *buff, char *str, int i)
{
	int	j;

	j = 0;
	while (buff[i])
		str[j++] = buff[i++];
	str[j] = '\0';
	return (str);
}

char	*store_rest(char *buff)
{
	char	*str;
	int		i;
	int		len;

	i = 0;
	while (buff[i] != '\n' && buff[i])
		i++;
	if (buff[i])
		i++;
	if (!buff[i])
	{	
		free(buff);
		return (NULL);
	}
	len = ft_strlen(&buff[i]);
	str = (char *)malloc(sizeof(char) * len + 1);
	if (!str)
		return (NULL);
	str = ft_strcpy(buff, str, i);
	free(buff);
	return (str);
}

char	*get_linef(char *buff)
{
	char	*str;
	int		i;

	i = 0;
	while (buff[i] != '\n' && buff[i])
		i++;
	str = (char *)malloc(sizeof(char) * i + 2);
	if (!str)
		return (NULL);
	i = 0;
	while (buff[i] != '\n' && buff[i])
	{
		str[i] = buff[i];
		i++;
	}
	if (buff[i] == '\n')
	{
		str[i] = buff[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

char	*store_txt(int fd, char *buff)
{
	char	*str;
	int		byte_count;

	str = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!str)
		return (NULL);
	byte_count = 1;
	while (!ft_strchrgnl(buff, '\n') && byte_count != 0)
	{
		byte_count = read(fd, str, BUFFER_SIZE);
		if (byte_count == -1)
		{
			free(str);
			return (NULL);
		}
		str[byte_count] = '\0';
		buff = ft_strjoingnl(buff, str);
	}
	free(str);
	return (buff);
}

char	*get_next_line(int fd)
{
	static char	*buff[1024];
	char		*str;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
		return (free(buff[fd]), buff[fd] = NULL, NULL);
	if (!buff[fd])
	{
		buff[fd] = (char *)malloc(sizeof(char) * 1);
		buff[fd][0] = '\0';
	}
	buff[fd] = store_txt(fd, buff[fd]);
	if (!buff[fd])
		return (NULL);
	str = get_linef(buff[fd]);
	buff[fd] = store_rest(buff[fd]);
	if (!ft_strlen(str))
	{
		free(str);
		return (NULL);
	}
	return (str);
}
