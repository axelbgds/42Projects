/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeaugra <abeaugra@student.42perp.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 15:09:54 by abeaugra          #+#    #+#             */
/*   Updated: 2023/04/03 14:42:58 by abeaugra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

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
