/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_char.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alsaez <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 17:38:55 by alsaez            #+#    #+#             */
/*   Updated: 2023/03/07 12:23:57 by alsaez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int	ft_putchar(int c, t_flags flags)
{
	int	i;

	i = 0;
	if (flags.minus == 1)
	{
		ft_putchar_fd(c, 1);
		i++;
		i += ft_treat_width(flags.width, flags.minus, flags.zero);
	}
	else
	{
		i = ft_treat_width((flags.width - 1), flags.minus, flags.zero);
		ft_putchar_fd(c, 1);
		i++;
	}
	return (i);
}
