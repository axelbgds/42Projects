/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeaugra <abeaugra@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 12:05:01 by abeaugra          #+#    #+#             */
/*   Updated: 2023/02/20 15:19:05 by abeaugra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*	The calloc() function contiguously allocates enough space for count
*	objects that are size bytes of memory each and returns a pointer to the
*	allocated memory.  The allocated memory is filled with bytes of value
*	zero.*/

void	*ft_calloc(size_t n, size_t size)
{
	void	*array;

	if (!n || !size)
		ft_calloc(1, 1);
	if (n * size / n != size)
		return (0);
	array = malloc(n * size);
	if (array)
		ft_bzero(array, n * size);
	return (array);
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
