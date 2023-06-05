/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeaugra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 11:43:19 by abeaugra          #+#    #+#             */
/*   Updated: 2023/06/05 11:43:21 by abeaugra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	putstr_len(char *str)
{
	size_t	len;

	len = 0;
	if (!str)
		return (write(1, "(null)", 6));
	while (str[len++])
		write(1, &str[len - 1], 1);
	return (len - 1);
}

static size_t	putnbr_len(long long nb)
{
	size_t				len;
	unsigned long long	n;

	len = 0;
	if (nb < 0)
	{
		write(1, "-", 1);
		n = -nb;
		len++;
	}
	else
		n = nb;
	if (n > 9)
		len += putnbr_len(n / 10);
	n = (n % 10) + 48;
	len += write(1, &n, 1);
	return (len);
}

static size_t	puthex_len(unsigned long nb, int up_case, int pre)
{
	size_t	len;
	char	*base;

	len = 0;
	if (pre)
		len += write(1, "0x", 2);
	if (up_case)
		base = "0123456789ABCDEF";
	if (!up_case)
		base = "0123456789abcdef";
	if (nb > 15)
		len += puthex_len((nb / 16), up_case, 0);
	len += write(1, &base[nb % 16], 1);
	return (len);
}

static size_t	control_print(char c, va_list args)
{
	size_t	len;

	len = 0;
	if (c == 'c')
	{
		c = va_arg(args, int);
		len += write(1, &c, 1);
	}
	else if (c == 's')
		len += putstr_len(va_arg(args, char *));
	else if (c == 'p')
		len += puthex_len(va_arg(args, unsigned long), 0, 1);
	else if (c == 'd' || c == 'i')
		len += putnbr_len(va_arg(args, int));
	else if (c == 'u')
		len += putnbr_len(va_arg(args, unsigned int));
	else if (c == 'x')
		len += puthex_len(va_arg(args, unsigned int), 0, 0);
	else if (c == 'X')
		len += puthex_len(va_arg(args, unsigned int), 1, 0);
	else if (c == '%')
		len += write(1, "%", 1);
	return (len);
}

int	ft_printf(const char *fmt, ...)
{
	va_list	args;
	size_t	len;

	if (!fmt)
		return (0);
	va_start(args, fmt);
	len = 0;
	while (*fmt)
	{
		if (*fmt == '%')
			len += control_print(*++fmt, args);
		else
			len += write(1, fmt, 1);
		fmt++;
	}
	va_end(args);
	return (len);
}
