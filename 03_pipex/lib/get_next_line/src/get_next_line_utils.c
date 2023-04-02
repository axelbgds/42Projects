
#include <get_next_line.h>

char	*ft_strjoin_m(char *s1, char *s2)
{
	char	*str;
	size_t	len;

	if (s1 == NULL)
	{
		s1 = malloc(sizeof(char));
		s1[0] = '\0';
	}
	len = ft_strlen_gnl(s1) + ft_strlen_gnl(s2) + 1;
	str = (char *)malloc(len * sizeof(char));
	if (!str)
		return (free(s1), NULL);
	ft_memcpy_gnl(str, s1, ft_strlen_gnl(s1));
	ft_memcpy_gnl(str + ft_strlen_gnl(s1), s2, ft_strlen_gnl(s2));
	*(str + ft_strlen_gnl(s1) + ft_strlen_gnl(s2)) = '\0';
	free(s1);
	return (str);
}

size_t	ft_strlen_gnl(const char *s)
{
	size_t	i;

	i = 0;
	if (!s || !*s)
		return (0);
	while (s[i] != '\0')
		i++;
	return (i);
}

void	*ft_memcpy_gnl(void *dst, const void *src, size_t n)
{
	char	*copy_dst;
	char	*copy_src;
	size_t	i;

	if (!src && !dst)
		return (NULL);
	copy_dst = (char *)dst;
	copy_src = (char *)src;
	i = 0;
	while (i < n)
	{
		copy_dst[i] = copy_src[i];
		i++;
	}
	return (dst);
}

char	*ft_strchr_gnl(const char *s, int c)
{
	size_t	i;

	i = 0;
	if (s == NULL)
		return (NULL);
	while (s[i])
	{
		if (s[i] == (char)c)
			return ((char *)s + i);
		i++;
	}
	if (s[i] == (char)c)
		return ((char *)s + i);
	return (NULL);
}

char	*ft_substr_m(char const *s, unsigned int start, size_t len)
{
	char			*ptr;
	unsigned int	i;

	if (!s || len == 0 || start > ft_strlen_gnl(s))
		return (NULL);
	if (start > ft_strlen_gnl(s))
		len = 0;
	if (len > ft_strlen_gnl(s) - start)
		len = ft_strlen_gnl(s) - start;
	ptr = (char *)malloc((len + 1) * sizeof(char));
	if (!ptr)
		return (NULL);
	i = 0;
	while (i < len && *(s + start + i))
	{
		ptr[i] = (char)s[start + i];
		i++;
	}
	ptr[i] = '\0';
	return (ptr);
}
