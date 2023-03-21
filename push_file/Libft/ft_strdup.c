#include "libft.h"

char	*ft_strdup(const char *src)
{
	char	*dest;
	int		i;

	i = -1;
	dest = lb(sizeof(char) * ft_strlen(src) + 1, 1);
	if (!dest)
		return (NULL);
	while (src[++i])
		dest[i] = src[i];
	dest[i] = '\0';
	return (dest);
}
