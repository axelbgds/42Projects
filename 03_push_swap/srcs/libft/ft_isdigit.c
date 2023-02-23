/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeaugra <abeaugra@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 15:09:38 by abeaugra          #+#    #+#             */
/*   Updated: 2022/03/24 14:38:35 by abeaugra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* The isnumber() function behaves similarly 
 * to isdigit(), but may recognize additional
 * characters, depending on the current locale setting.
 * The value of the argument must be representable as 
 * an unsigned char or the value of
 * EOF.*/

int	ft_isdigit(int c)
{
	return ((c >= '0' && c <= '9'));
}
/*
int main (void)
{
   char p = '3';
   printf("%d\n", ft_isdigit(p));
   return (0);
}*/
