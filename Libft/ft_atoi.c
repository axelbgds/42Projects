#include"libft.h"

int	ft_atoi(const char *str)
{
	int				i;
	int				n;
	long int		result;

	i = 0;
	n = 1;
	result = 0;
	while (((str[i] >= 9 && str[i] <= 13) || str[i] == 32) && str[i])
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			n *= -1;
		i++;
	}
	while (str[i] && str[i] >= '0' && str[i] <= '9')
	{
		result = result * 10 + str[i] - '0';
		i++;
		if (result > INT_MAX || result < INT_MIN)
			return (write(2, "Error\n", 7), lb(0, 0), 0);
	}
	return ((int)result * n);
}
