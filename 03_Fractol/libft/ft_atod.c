/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atod.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeaugra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 11:42:43 by abeaugra          #+#    #+#             */
/*   Updated: 2023/06/05 11:42:47 by abeaugra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

double	ft_atod(const char *s)
{
	int		sign;
	double	integer;
	int		i;
	double	decimal;

	while (*s == ' ' || (*s >= 9 && *s <= 13))
		s++;
	sign = 1;
	if (*s == '-' || *s == '+')
	{	
		if (*s == '-')
			sign *= -1;
		s++;
	}
	integer = 0.0;
	while (*s && (*s >= '0' && *s <= '9'))
		integer = integer * 10 + (*s++ - '0');
	decimal = 0.0;
	i = -1;
	if (*s == '.' && *s++)
	{
		while (*s >= '0' && *s <= '9')
			decimal += (pow(10, i--) * (*s++ - '0'));
	}
	return (sign * (integer + decimal));
}
