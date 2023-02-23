/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeaugra <abeaugra@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 14:11:46 by abeaugra          #+#    #+#             */
/*   Updated: 2022/03/28 12:26:46 by abeaugra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* 	The toupper() function converts a lower-case letter
*	to the corresponding upper-case letter.
*	The argument must be representable as an unsigned 
*	char or the value of EOF.*/

int	ft_toupper(int c)
{
	if (c >= 'a' && c <= 'z')
		return (c - 0x20);
	return (c);
}
/*
int main() 
{
    char c = 'a';
	printf( "Result: %d\n", ft_toupper(c));
    return (0);
}
*/