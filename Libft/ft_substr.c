#include"libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*str;
	size_t			i;
	unsigned int	slen;

	if (!s)
		return (NULL);
	slen = ft_strlen(s + start);
	i = 0;
	if (len > slen)
		len = slen;
	str = lb(len + 1, 1);
	if (!str)
		return (NULL);
	slen = ft_strlen(s);
	i = -1;
	while (++i < len && start[s] && start < slen)
		*(str + i) = *(s + start + i);
	str[i] = '\0';
	return (str);
}
