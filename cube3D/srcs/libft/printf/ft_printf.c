/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alsaez <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 11:31:07 by alsaez            #+#    #+#             */
/*   Updated: 2023/03/07 13:14:52 by alsaez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

t_flags	ft_init_flags(void)
{
	t_flags		flags;

	flags.space = 0;
	flags.dot = -1;
	flags.minus = 0;
	flags.hash = 0;
	flags.star = 0;
	flags.type = 0;
	flags.width = 0;
	flags.zero = 0;
	return (flags);
}

static t_flags	ft_flag_parse2(const char *str, int i,
	t_flags *flags, va_list args)
{
	if (str[i] == '-')
		*flags = ft_flag_minus(*flags);
	if (str[i] == '*')
		*flags = ft_flag_width(args, *flags);
	if (str[i] == ' ')
		*flags = ft_flag_space(*flags);
	if (str[i] == '#')
		*flags = ft_flag_hash(*flags);
	if (str[i] == '+')
		*flags = ft_flag_plus(*flags);
	return (*flags);
}

int	ft_flag_parse(const char *str, int i, t_flags *flags, va_list args)
{
	while (str[i])
	{
		if (!ft_isdigit(str[i]) && !ft_is_in_type_list(str[i])
			&& !ft_is_in_flags_list(str[i]))
			break ;
		if (str[i] == '0' && flags->width == 0 && flags->minus == 0)
			flags->zero = 1;
		if (str[i] == '.')
			i = ft_flag_dot(str, i, flags, args);
		if (ft_is_in_flags_list(str[i]) && (str[i] != '.' && str[i] != '0'))
			*flags = ft_flag_parse2(str, i, flags, args);
		if (ft_isdigit(str[i]))
			*flags = ft_flag_digit(str[i], *flags);
		if (ft_is_in_type_list(str[i]))
		{
			flags->type = str[i];
			break ;
		}
		i++;
	}
	return (i);
}

int	ft_treat_str(const char *str, va_list args)
{
	int			i;
	t_flags		flags;
	int			char_count;

	i = 0;
	char_count = 0;
	while (1)
	{
		flags = ft_init_flags();
		if (!str[i])
			break ;
		else if (str[i] == '%' && str[i + 1])
		{
			i = ft_flag_parse(str, ++i, &flags, args);
			if (ft_is_in_type_list(str[i]))
				char_count += ft_treatment((char)flags.type, flags, args);
			else if (str[i])
				char_count += ft_putchar(str[i], flags);
		}
		else if (str[i] != '%')
			char_count += ft_putchar(str[i], flags);
		i++;
	}
	return (char_count);
}

int	ft_printf(const char *input, ...)
{
	const char	*str;
	va_list		args;
	int			char_count;

	str = ft_strdup(input);
	char_count = 0;
	va_start(args, input);
	char_count += ft_treat_str(str, args);
	va_end(args);
	free((char *)str);
	return (char_count);
}
/*
int	main(void)
{
	int		i;
	unsigned int		j;
	char	*s;
	char	c;

	c = '%';
	s = 0;
	i = 100;
	j = 3300000000;
	ft_printf("Start %% %010d %-.20i %p %c End \n", i, j, s, c);
	printf("Start %% %010d %-.20i %p %c End \n", i, j, s, c);
	ft_putnbr_fd(ft_printf("%10.5i\n", -216), 1);
        ft_putchar_fd('\n', 1);
        ft_putnbr_fd(printf("%10.5i\n", -216), 1);
        ft_putchar_fd('\n', 1);
        ft_putnbr_fd(ft_printf("%08.3i\n", -8473), 1);
        ft_putchar_fd('\n', 1);
        ft_putnbr_fd(printf("%08.3i\n", -8473), 1);
        ft_putchar_fd('\n', 1);
        ft_putnbr_fd(ft_printf("%15.4d\n", -42), 1);
        ft_putchar_fd('\n', 1);
        ft_putnbr_fd(printf("%15.4d\n", -42), 1);*/
	/*  ft_putchar_fd('\n', 1);
        ft_putnbr_fd(ft_printf("%20.5d\n", -1024), 1);
        ft_putchar_fd('\n', 1);
        ft_putnbr_fd(printf("%20.5d\n", -1024), 1);
        ft_putchar_fd('\n', 1);
        ft_putnbr_fd(ft_printf("s%010ue\n", j), 1);
        ft_putchar_fd('\n', 1);
        ft_putnbr_fd(printf("s%010ue\n", j), 1);
        ft_putchar_fd('\n', 1);
        ft_putnbr_fd(ft_printf("s%010xe\n", j), 1);
		ft_putchar_fd('\n', 1);
		ft_putnbr_fd(printf("s%010xe\n", j), 1);
        ft_putchar_fd('\n', 1);
        ft_putnbr_fd(ft_printf("%s World %-10.5i.\n", s, i), 1);
        ft_putchar_fd('\n', 1);
        ft_putnbr_fd(printf("%s World %-10.5i.\n", s, i), 1);
		ft_putchar_fd('\n', 1);
	return (0);
}*/