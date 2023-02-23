/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeaugra <abeaugra@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 15:09:54 by abeaugra          #+#    #+#             */
/*   Updated: 2022/03/23 16:14:58 by abeaugra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*	The memcpy() function copies n bytes from memory
*   area src to memory area dst.  If dst and src
*   overlap, behavior is undefined.  Applications in
*   which dst and src might overlap should use
*   memmove(3) instead.
*/

void	*ft_memcpy(void *dst, const void *src, size_t n)
{	
	void	*original_dst;

	if (!dst && !src)
		return (NULL);
	original_dst = dst;
	while (n--)
		*((char *)dst++) = *((char *)src++);
	return (original_dst);
}
/*
int main (void)
{
	const char src[50] = "toto point";
	char dest[50];
	strcpy(dest,"Heloooo!!");
	printf("Before memcpy dest = %s\n", dest);
	ft_memcpy(dest, src, strlen(src)+1);
	printf("After memcpy dest = %s\n", dest);	
}*/
