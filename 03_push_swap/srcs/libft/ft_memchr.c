/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeaugra <abeaugra@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 13:49:37 by abeaugra          #+#    #+#             */
/*   Updated: 2023/02/20 15:17:29 by abeaugra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* 	The memchr() function locates the first occurrence 
*	of c (converted to an unsigned char) in string s.*/

void	*ft_memchr(const void *s, int c, size_t n)
{
	int	i;

	i = -1;
	while (n--)
		if (((unsigned char *)s)[++i] == (unsigned char) c)
			return (((unsigned char *)s) + i);
	return (NULL);
}
/*
int main () {
   const char str[] = "Toto tata .mimi mama";
   const char ch = '.';
   char *ret;

   ret = ft_memchr(str, ch, strlen(str));

   printf("String after |%c| is - |%s|\n", ch, ret);

   return(0);
}*/
