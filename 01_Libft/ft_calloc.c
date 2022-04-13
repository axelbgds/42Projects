/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeaugra <abeaugra@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 12:05:01 by abeaugra          #+#    #+#             */
/*   Updated: 2022/03/29 16:06:09 by abeaugra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*	The calloc() function contiguously allocates enough space for count
*	objects that are size bytes of memory each and returns a pointer to the
*	allocated memory.  The allocated memory is filled with bytes of value
*	zero.*/

void	*ft_calloc(size_t count, size_t size)
{
	void			*res;
	unsigned char	*char_res;

	res = malloc(count * size);
	if (!(res))
		return (NULL);
	char_res = (unsigned char *)res;
	ft_bzero(char_res, (count * size));
	return (res);
}
/*
int	main(void)
{
	printf("====ft_calloc====\n");
	printf("%p\n", ft_calloc(5, 1));
	printf("%ld\n", sizeof(ft_calloc(5, 1)));
	
	printf("====calloc====\n");
	printf("%p\n", calloc(5, 1));
	printf("%ld\n", sizeof(calloc(5, 1)));
	return (0);
}*/