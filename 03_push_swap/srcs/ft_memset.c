/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeaugra <abeaugra@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 15:09:48 by abeaugra          #+#    #+#             */
/*   Updated: 2022/03/30 17:04:12 by abeaugra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*The memset() function writes len bytes of
 * value c (converted to an unsigned char) to
 * the string b.*/

void	*ft_memset(void *b, int c, size_t len)
{
	size_t	i;

	i = 0;
	while (len--)
	{
		*(unsigned char *)(b + i) = (unsigned char)c;
		i++;
	}
	return (b);
}

/*
int main() {
	char str[50];
   	strcpy(str,"This is string.h library function");
	puts(str);
	ft_memset(str,'$',7);
	puts(str);
    return (0);
}*/
