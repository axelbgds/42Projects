/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeaugra <abeaugra@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 15:10:08 by abeaugra          #+#    #+#             */
/*   Updated: 2022/03/24 14:38:38 by abeaugra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* The isascii() function tests for an ASCII character, 
 * which is any character between
 *	0 and octal 177 inclusive. */

int	ft_isascii(int c)
{
	return (c >= 0 && c <= 127);
}
/*
int main (void)
{
    char c = '+';
    printf("%d", ft_isascii(c));
    return(0);
}*/
