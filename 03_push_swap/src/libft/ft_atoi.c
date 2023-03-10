/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeaugra <abeaugra@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 09:30:54 by abeaugra          #+#    #+#             */
/*   Updated: 2023/03/10 12:55:25 by abeaugra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*	The atoi() function converts the initial portion of the string 
*	pointed to by str to int representation.*/

static int	ft_is_white_space(const char *c)
{
	if (*c == ' ' || *c == '\n' || *c == '\t'
		|| *c == '\v' || *c == '\f' || *c == '\r')
		return (1);
	else
		return (0);
}

static int	ft_is_plus_minus(const char *c)
{
	if (*c == '+' || *c == '-')
		return (1);
	else
		return (0);
}

static int	ft_is_number(const char *c)
{
	if (*c >= '0' && *c <= '9')
		return (1);
	else
		return (0);
}

int	ft_atoi(const char *str)
{
	int	sign;
	int	res;

	sign = 1;
	res = 0;
	while (ft_is_white_space(str))
		str++;
	if (ft_is_plus_minus(str))
	{
		if (*str == '-')
			sign *= -1;
		str ++;
	}
	while (ft_is_number(str))
	{
		res *= 10;
		res += (*str - '0');
		str++;
		if(res > INT_MAX || res < INT_MIN)
			return(write(2,"Error\n",6), clear_stack(0,0), 0);
	}
	return (sign *res);
}
