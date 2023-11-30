/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_treatment.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alsaez <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 17:36:01 by alsaez            #+#    #+#             */
/*   Updated: 2023/03/09 10:26:24 by alsaez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int	ft_treat_width(int width, int minus, int has_zero)
{
	int	char_count;

	char_count = 0;
	while (width - minus > 0)
	{
		if (has_zero)
			ft_putchar_fd('0', 1);
		else
			ft_putchar_fd(' ', 1);
		width -= 1;
		char_count++;
	}
	return (char_count);
}

int	ft_is_in_type_list(int c)
{
	return ((c == 'c') || (c == 's') || (c == 'p') || (c == 'd') || (c == 'i')
		|| (c == 'u') || (c == 'x') || (c == 'X') || (c == '%'));
}

int	ft_is_in_flags_list(int c)
{
	return ((c == '#') || (c == '+') || (c == '-') || (c == ' ')
		|| (c == '0') || (c == '.') || (c == '*'));
}

int	ft_treatment(int c, t_flags flags, va_list args)
{
	int	char_count;

	char_count = 0;
	if (c == 'c')
		char_count = ft_putchar(va_arg(args, int), flags);
	else if (c == 's')
		char_count = ft_treat_string(va_arg(args, char *), flags);
	else if (c == 'p')
		char_count = ft_treat_ptr(va_arg(args, unsigned long long), flags);
	else if (c == 'd' || c == 'i')
		char_count = ft_treat_int(va_arg(args, int), flags);
	else if (c == 'u')
		char_count += ft_treat_uint((unsigned int)va_arg(args, unsigned int),
				flags);
	else if (c == 'x')
		char_count += ft_treat_hexa(va_arg(args, unsigned int), 1, flags);
	else if (c == 'X')
		char_count += ft_treat_hexa(va_arg(args, unsigned int), 0, flags);
	else if (c == '%')
		char_count += ft_treat_percent(flags);
	return (char_count);
}
