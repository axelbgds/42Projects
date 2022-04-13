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
/*
int main () {
   char str1[15];
   char str2[15];
   int ret;

   ft_memcpy(str1, "abcdef", 6);
   ft_memcpy(str2, "ABCDEF", 6);

   ret = ft_memcmp(str1, str2, 5);

   if(ret > 0) {
      printf("str2 is less than str1");
   } else if(ret < 0) {
      printf("str1 is less than str2");
   } else {
      printf("str1 is equal to str2");
   }
   
   return(0);
}
*/