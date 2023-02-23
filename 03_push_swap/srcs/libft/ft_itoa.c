/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeaugra <abeaugra@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 14:37:08 by abeaugra          #+#    #+#             */
/*   Updated: 2022/03/30 16:19:15 by abeaugra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*	Alloue (avec malloc(3)) et retourne une chaîne
*	de caractères représentant l’entier ’n’ reçu en
*	argument. Les nombres négatifs doivent être gérés.*/

static int	mem_c(long n)
{
	int	i;

	i = 0;
	if (n < 0)
	{
		i++;
		n = -n;
	}
	while (n >= 10 && ++i)
		n /= 10;
	return (i + 1);
}

char	*ft_itoa(int n)
{
	char	*nx;
	int		i;
	long	nn;

	nn = n;
	i = mem_c(nn);
	nx = malloc((i + 1) * sizeof(char));
	if (!nx)
		return (0);
	nx[i--] = '\0';
	if (nn < 0)
		nn = -nn;
	while (i >= 0)
	{
		nx[i--] = (nn % 10) + 48;
		nn /= 10;
	}
	if (n < 0)
		nx[0] = '-';
	return (nx);
}
