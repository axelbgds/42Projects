/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeaugra <abeaugra@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 15:09:44 by abeaugra          #+#    #+#             */
/*   Updated: 2022/03/24 15:13:36 by abeaugra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <ctype.h>
#include <stdio.h>

/* The isalnum() function tests for any 
 * character for which isalpha(3) or 
 * isdigit(3) is true. The value of the 
 * argument must be representable as an
 * unsigned char or the value of EOF.*/

int	ft_isalnum(int c)
{
	return (ft_isalpha(c) || ft_isdigit(c));
}
/*
int main ()
{
	char c;
    int result;
    c = '5';
    result = isalnum(c);
    printf("When %c is passed, return value is %d\n", c, result);
}
*/
