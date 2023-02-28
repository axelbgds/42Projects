/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elorenze <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/27 10:04:39 by elorenze          #+#    #+#             */
/*   Updated: 2022/01/27 15:32:31 by elorenze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putnbr(int nb)
{
	int	divisor;
	char	buff;

	divisor = 1;
	if (nb < 0)
	{
		write(1, "-", 1);
		nb *= -1;
	}
	while ((nb / (divisor * 10)) > 0)
	{
		divisor *= 10;
	}
	while (divisor > 0)
	{
		buff = ('0' + ((nb / divisor) % 10));
		write(1, &buff, 1);
		divisor /= 10;
	}
}
