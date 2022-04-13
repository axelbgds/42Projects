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

static size_t	ft_abs(long int n)
{
	if (n < 0)
		return (-n);
	return (n);
}

static size_t	get_len(int n)
{
	size_t	len;

	len = 0;
	if (n <= 0)
		len++;
	while (n)
	{
		len ++;
		n = n / 10;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	size_t	len;
	char	*result;

	len = get_len(n);
	result = malloc(sizeof(*result) * (len + 1));
	if (!result)
		return (NULL);
	result[len] = '\0';
	if (n < 0)
		result[0] = '-';
	else if (n == 0)
		result [0] = '0';
	while (n)
	{
		len--;
		result[len] = ft_abs(n % 10) + '0';
		n = n / 10;
	}
	return (result);
}
