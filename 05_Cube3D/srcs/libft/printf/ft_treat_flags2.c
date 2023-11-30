/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_treat_flags2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alsaez <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 20:49:10 by alsaez            #+#    #+#             */
/*   Updated: 2023/03/07 13:17:29 by alsaez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

static int	ft_in_put_part_int(char *str_i, t_flags flags)
{
	int	char_count;

	char_count = 0;
	if (flags.dot >= 0)
		char_count += ft_treat_width(flags.dot - 1, ft_strlen(str_i) - 1, 1);
	char_count += ft_putstrprec(str_i, ft_strlen(str_i));
	return (char_count);
}

int	ft_treat_dot_len(char *str_i, t_flags flags)
{
	int	char_count;

	char_count = 0;
	if (flags.dot > flags.width)
		flags.width = (flags.dot - ((int)ft_strlen(str_i) + 1));
	else
		char_count += ft_treat_width(flags.width, flags.dot, 0);
	char_count += ft_in_put_part_int(str_i, flags);
	return (char_count);
}

t_flags	ft_flag_hash(t_flags flags)
{
	flags.hash = 1;
	return (flags);
}

t_flags	ft_flag_space(t_flags flags)
{
	if (flags.space == 1)
		return (flags);
	flags.space = 1;
	return (flags);
}

t_flags	ft_flag_plus(t_flags flags)
{
	if (flags.minus == -1)
		return (flags);
	flags.minus = -1;
	flags.width++;
	return (flags);
}
