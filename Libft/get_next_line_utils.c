#include"get_next_line.h"

char	*ft_substr_gnl(char const *s, unsigned int start, size_t len)
{
	char			*str;
	size_t			i;
	unsigned int	slen;

	if (!s)
		return (NULL);
	slen = ft_strlen_gnl(s + start);
	i = 0;
	if (len > slen)
		len = slen;
	str = malloc(len + 1);
	if (!str)
		return (NULL);
	slen = ft_strlen_gnl(s);
	i = -1;
	while (++i < len && start[s] && start < slen)
		*(str + i) = *(s + start + i);
	str[i] = '\0';
	return (str);
}

size_t	ft_strlen_gnl(const char *s)
{
	size_t	i;

	i = 0;
	while (*(s + i))
		i++;
	return (i);
}

char	*ft_strdup_gnl(const char *src)
{
	char	*dest;
	int		i;

	i = -1;
	dest = malloc(sizeof(char) * ft_strlen_gnl(src) + 1);
	if (!dest)
		return (NULL);
	while (src[++i])
		dest[i] = src[i];
	dest[i] = '\0';
	return (dest);
}

char	*ft_strchr_gnl(const char *s, int c)
{
	int	i;

	i = -1;
	while (*(s + (++i)))
		if (*(s + i) == (unsigned char)c)
			return ((char *)s + i);
	return (NULL);
}

char	*ft_strjoin_gnl(const char *s1, const char *s2)
{
	int		j;
	char	*str;
	char	*str1;
	int		i;

	i = -1;
	if (!s1)
		str1 = ft_strdup_gnl("");
	else
		str1 = ft_strdup_gnl(s1);
	str = malloc(sizeof (char) * ((ft_strlen_gnl(str1))
				+ ft_strlen_gnl(s2)) + 1);
	if (!str)
		return (NULL);
	while (str1[++i])
		str[i] = str1[i];
	j = i;
	i = -1;
	while (s2[++i])
		str[j++] = s2[i];
	str[j] = '\0';
	free(str1);
	return (str);
}
