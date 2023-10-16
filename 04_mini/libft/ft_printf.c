/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeaugra <abeaugra@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 13:59:44 by abeaugra          #+#    #+#             */
/*   Updated: 2023/08/28 14:03:07 by abeaugra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

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
