/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_treat_min_int.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alsaez <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 15:02:19 by alsaez            #+#    #+#             */
/*   Updated: 2023/03/07 15:02:34 by alsaez           ###   ########.fr       */
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

static int	ft_put_part_int(char *str_i, t_flags flags)
{
	int	char_count;

	char_count = 0;
	if (flags.minus == 1 || flags.minus == -1)
		char_count += ft_in_put_part_int(str_i, flags);
	if (flags.dot >= 0 && (size_t)flags.dot < ft_strlen(str_i))
		flags.dot = ft_strlen(str_i);
	if (flags.dot >= 0)
	{
		flags.width -= flags.dot;
		char_count += ft_treat_width(flags.width, 0, 0);
	}
	else
		char_count += ft_treat_width(flags.width, ft_strlen(str_i), flags.zero);
	if (flags.minus == 0)
		char_count += ft_in_put_part_int(str_i, flags);
	return (char_count);
}

static int	ft_treat_min_int2(t_flags flags, char *str_i)
{
	int		char_count;

	char_count = 0;
	if (flags.zero == 1 && flags.dot > 0 && flags.dot < flags.width)
	{
		char_count += ft_treat_width((flags.width
					- (int)ft_strlen(str_i)), 1, 0);
		ft_putstrprec("-", 1);
		char_count++;
		flags.width -= ((int)ft_strlen(str_i) + 1);
		char_count += ft_put_part_int(str_i, flags);
		free(str_i);
		return (char_count);
	}
	ft_putstrprec("-", 1);
	char_count++;
	flags.width -= char_count;
	char_count += ft_put_part_int(str_i, flags);
	free(str_i);
	return (char_count);
}

int	ft_treat_min_int(int i, t_flags flags)
{
	char	*str_i;
	int		len;
	int		char_count;

	len = 0;
	char_count = 0;
	len = (i + 1) * -1;
	str_i = ft_itoa(len);
	len = (int)ft_strlen(str_i);
	str_i[len - 1] = '8';
	if (flags.minus == 1 || flags.zero == 1 || flags.dot >= flags.width)
	{
		char_count += ft_treat_min_int2(flags, str_i);
		return (char_count);
	}
	char_count += ft_treat_width(flags.width - 1, ft_strlen(str_i), flags.zero);
	ft_putstrprec("-", 1);
	char_count++;
	flags.width -= char_count;
	char_count += ft_put_part_int(str_i, flags);
	free(str_i);
	return (char_count);
}
