
#include <get_next_line.h>

char	*ft_getrest(char *var)
{
	size_t		len;
	char		*rest;

	if (var == NULL || !ft_strchr_gnl(var, '\n'))
		return (free(var), NULL);
	len = ft_strchr_gnl(var, '\n') - var + 1;
	rest = ft_substr_m(var, len, ft_strlen_gnl(var) - len);
	free(var);
	return (rest);
}

char	*ft_getline(char *var)
{
	size_t		len;
	char		*line;

	if (var == NULL || *var == '\0')
		return (NULL);
	if (ft_strchr_gnl(var, '\n'))
		len = ft_strchr_gnl(var, '\n') - var + 1;
	else
		len = ft_strlen_gnl(var);
	line = ft_substr_m(var, 0, len);
	return (line);
}

char	*ft_join(int fd, char *var)
{
	int		ret;
	char	buf[BUFFER_SIZE + 1];

	ret = 1;
	while (!ft_strchr_gnl(var, '\n') && ret > 0)
	{
		ret = read(fd, buf, BUFFER_SIZE);
		if (ret == -1)
			return (free(var), NULL);
		buf[ret] = '\0';
		var = ft_strjoin_m(var, buf);
		if (var == NULL || *var == '\0')
			return (free(var), NULL);
	}
	return (var);
}

char	*get_next_line(int fd)
{
	static char	*var;
	char		*line;

	if (fd == -1 || BUFFER_SIZE <= 0)
		return (NULL);
	var = ft_join (fd, var);
	line = ft_getline(var);
	var = ft_getrest(var);
	return (line);
}
