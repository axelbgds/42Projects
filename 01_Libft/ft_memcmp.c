/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeaugra <abeaugra@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 14:36:12 by abeaugra          #+#    #+#             */
/*   Updated: 2022/03/28 08:47:59 by abeaugra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*	The memcmp() function compares byte string s1 against byte string s2.
*     Both strings are assumed to be n bytes long.*/

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*array1;
	unsigned char	*array2;

	if (n == 0)
		return (0);
	array1 = (unsigned char *) s1;
	array2 = (unsigned char *) s2;
	while ((*array1 == *array2) && n - 1 > 0)
	{
		array1++;
		array2++;
		n--;
	}
	return (*array1 - *array2);
}
