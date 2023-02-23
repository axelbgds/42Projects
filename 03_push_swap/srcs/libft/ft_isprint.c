/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeaugra <abeaugra@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 15:10:14 by abeaugra          #+#    #+#             */
/*   Updated: 2022/03/24 14:38:32 by abeaugra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* The isprint() function tests for any printing 
 * character, including space (` ').  The value 
 * of the argument must be representable as an 
 * unsigned char or the value of EOF. */

int	ft_isprint(int c)
{
	return (c >= 32 && c <= 126);
}
/*
int main (void)
{
	char c = '+';
	printf("%d\n", ft_isprint(c));
	return (0);
}*/
