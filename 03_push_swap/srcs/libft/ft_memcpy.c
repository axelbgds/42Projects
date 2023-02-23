/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeaugra <abeaugra@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 15:09:54 by abeaugra          #+#    #+#             */
/*   Updated: 2023/02/20 15:15:59 by abeaugra         ###   ########.fr       */
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
	size_t	i;

	i = -1;
	if (!src && !dst)
		return (0);
	while (++i < n)
		((char *) dst)[i] = ((char *) src)[i];
	return (dst);
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
