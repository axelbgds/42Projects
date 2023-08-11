/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-los- <tde-los-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 13:59:44 by tde-los-          #+#    #+#             */
/*   Updated: 2023/03/01 13:49:05 by tde-los-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_check(const char c, va_list ap)
{
	int	count;

	count = 0;
	if (c == 'c')
		count += ft_printchar(va_arg(ap, int));
	else if (c == 's')
		count += ft_printstr(va_arg(ap, char *));
	else if (c == 'p')
		count += ft_pointer(va_arg(ap, unsigned long long), 1);
	else if (c == 'd' || c == 'i')
		count += ft_putnbr(va_arg(ap, int));
	else if (c == 'x' || c == 'X' || c == 'u')
		count += ft_putnbr_base(va_arg(ap, unsigned int), c);
	else if (c == '%')
		count += ft_printchar('%');
	else
	{
		count += ft_printchar('%');
		count += ft_printchar(c);
	}
	return (count);
}

int	ft_printf(const char *str, ...)
{
	int		i;
	int		count;
	va_list	ap;

	i = 0;
	count = 0;
	va_start (ap, str);
	while (str[i])
	{
		if (str[i] == '%')
		{
			count = count + ft_check(str[i + 1], ap);
			i++;
		}
		else
		{
			ft_printchar(str[i]);
			count++;
		}
		i++;
	}
	va_end (ap);
	return (count);
}
