/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeaugra <abeaugra@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 14:36:31 by abeaugra          #+#    #+#             */
/*   Updated: 2022/03/24 15:19:03 by abeaugra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* 	The tolower() function converts an upper-case letter to the corresponding
*	lower-case letter.  The argument must be representable as an unsigned char
*	or the value of EOF.*/

int	ft_tolower(int c)
{
	if (c >= 'A' && c <= 'Z')
		c += 32;
	return (c);
}
/*
int main ()
{
	char c = 'T';
	printf( "Result: %d\n", ft_tolower(c));
    return (0);
}
*/