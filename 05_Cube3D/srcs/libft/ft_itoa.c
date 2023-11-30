/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alsaez <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 17:33:36 by alsaez            #+#    #+#             */
/*   Updated: 2023/02/07 13:49:57 by alsaez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_size(int n)
{
	int	size;

	size = 0;
	if (n <= 0)
		size++;
	while (n != 0)
	{
		n = n / 10;
		size++;
	}
	return (size);
}

char	*ft_itoa(int n)
{
	char	*str;
	int		nlen;
	long	nbr;

	nbr = n;
	nlen = ft_size(nbr);
	str = (char *)malloc((nlen + 1) * sizeof(char));
	if (str == NULL)
		return (NULL);
	str[nlen] = '\0';
	if (nbr < 0)
	{
		str[0] = '-';
		nbr = nbr * -1;
	}
	if (nbr == 0)
		str[0] = '0';
	while (nbr > 0)
	{
		str[nlen - 1] = ((nbr % 10) + '0');
		nbr = nbr / 10;
		nlen--;
	}
	return (str);
}
