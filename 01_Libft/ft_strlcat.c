/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeaugra <abeaugra@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 15:10:04 by abeaugra          #+#    #+#             */
/*   Updated: 2022/03/25 16:27:17 by abeaugra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* 	strlcat() appends string src to the end of dst.
* 	It will append at most dstsize - strlen(dst) - 1 characters.
*	It will then NUL-terminate, unless dstsize is 0 or the original
*	dst string was longer than dstsize (in practice this should 
*	not happen as it means that either dstsize is incorrect or that 
*	dst is not a proper string).
*	If the src and dst strings overlap, the behavior is undefined.*/

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	dstlen;
	size_t	srclen;

	dstlen = ft_strlen(dst);
	srclen = ft_strlen(src);
	if (size < dstlen)
		return (size + srclen);
	i = 0;
	while (src[i] && (dstlen + i + 1) < size)
	{
		dst[dstlen + i] = src[i];
		i++;
	}
	dst[dstlen + i] = '\0';
	return (dstlen + srclen);
}
/*
int main()
{
	char dst[100] = "1234";
	char src[100] = "ABCD";
	printf("%zu\n",ft_strlcat(dst, src, 7));
	printf("%zu\n",ft_strlcat(dst, src, 2));
	return(0);
}*/