/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeaugra <abeaugra@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 15:25:04 by abeaugra          #+#    #+#             */
/*   Updated: 2022/03/23 17:24:28 by abeaugra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*The memmove() function copies len bytes
 * from string src to string dst.  The two
 * strings may overlap; the copy is always
 * done in a non-destructive manner.*/

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t	i;

	i = 0;
	if (!dst && !src)
		return (NULL);
	if (src < dst)
	{
		while (len--)
			*(unsigned char *)(dst + len) = *(unsigned char *)(src + len);
	}
	else
	{
		i = 0;
		while (len--)
		{
			*(unsigned char *)(dst + i) = *(unsigned char *)(src + i);
			i++;
		}
	}
	return (dst);
}
/*
int main () 
{
	char dest[] = "Coucou";
	const char src[] = "Je s'appel groot";
	printf("Before memmove dest = %s, src = %s\n", dest, src);
	ft_memmove(dest, src, 10);
	printf("After memmove dest = %s, src = %s\n", dest, src);
	return(0);
}*/
