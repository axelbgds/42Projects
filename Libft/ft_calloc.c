#include"libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*x;

	x = lb(count * size, 1);
	if (!x)
		return (x);
	ft_bzero(x, (count * size));
	return (x);
}
