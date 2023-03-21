#include"get_next_line.h"

static char	*read_line(int fd, char *buffer, char *hold)
{
	ssize_t	ret;
	char	*str;

	ret = 1;
	while (ret != 0 && !ft_strchr_gnl(buffer, '\n'))
	{
		ret = read(fd, buffer, BUFFER_SIZE);
		if (ret < 0)
		{
			free(buffer);
			return (NULL);
		}
		buffer[ret] = 0;
		str = ft_strjoin_gnl(hold, buffer);
		free(hold);
		hold = str;
	}
	free(buffer);
	return (hold);
}

static char	*get_line(char *hold)
{
	int		i;
	char	*s;

	i = 0;
	while (hold[i] && hold[i] != '\n')
		i++;
	s = ft_substr_gnl(hold, 0, i);
	return (s);
}

static char	*update_hold(char *hold)
{
	char	*s;
	int		i;

	i = 0;
	while (hold[i] && hold[i] != '\n')
		i++;
	if (hold[i] == '\n')
		i++;
	s = ft_substr_gnl(hold, i, ft_strlen_gnl(hold + i));
	free(hold);
	return (s);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*hold;
	char		*buffer;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = (char *)malloc(BUFFER_SIZE + 1);
	if (!buffer)
	{
		free(hold);
		return (NULL);
	}
	buffer[0] = 0;
	hold = read_line(fd, buffer, hold);
	if (!hold)
		return (NULL);
	if (!*hold)
	{
		free(hold);
		return (hold = 0, NULL);
	}
	return (line = get_line(hold), hold = update_hold(hold), line);
}
