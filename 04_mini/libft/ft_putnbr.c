/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeaugra <abeaugra@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 10:02:57 by abeaugra          #+#    #+#             */
/*   Updated: 2023/08/28 14:03:07 by abeaugra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

int	ft_putnbr(int n)
{
	char	*number;
	int		count;

	count = 0;
	if (n == -2147483647)
	{
		count += ft_printstr("-2147483647");
		return (count);
	}
	number = ft_itoa(n);
	count += ft_printf("%s", number);
	free(number);
	return (count);
}

int	ft_putnbr_base(unsigned int n, char c)
{
	unsigned int	i;
	unsigned int	t;
	char			*base;

	i = 0;
	t = 16;
	if (c == 'x')
		base = "0123456789abcdef";
	else if (c == 'X')
		base = "0123456789ABCDEF";
	else
	{
		base = "0123456789";
		t = 10;
	}
	if (n > t - 1)
	{
		i += ft_putnbr_base((n / t), c);
		i += ft_putnbr_base((n % t), c);
	}
	else
		i += write(1, &base[n], 1);
	return (i);
}

int	ft_pointer(unsigned long long nb, int start)
{
	unsigned int	i;
	char			*base;

	i = 0;
	base = "0123456789abcdef";
	if (!nb && start == 1)
	{
		i += ft_printstr("(nil)");
		return (i);
	}
	if (start == 1)
		i += ft_printstr("0x");
	if (nb > 15)
	{
		i += ft_pointer((nb / 16), 0);
		i += ft_pointer((nb % 16), 0);
	}
	else
		i += write(1, &base[nb], 1);
	return (i);
}
