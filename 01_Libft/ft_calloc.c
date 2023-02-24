/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeaugra <abeaugra@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 12:05:01 by abeaugra          #+#    #+#             */
/*   Updated: 2023/02/08 15:45:30 by abeaugra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*	The calloc() function contiguously allocates enough space for count
*	objects that are size bytes of memory each and returns a pointer to the
*	allocated memory.  The allocated memory is filled with bytes of value
*	zero.*/

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*ptr;
	size_t	res;

	res = nmemb * size;
	if (nmemb == 0 || size == 0)
		return (malloc(0));
	if (res / size != nmemb || res / nmemb != size)
		return (NULL);
	ptr = malloc(res);
	if (ptr)
		ft_bzero(ptr, res);
	return (ptr);
}
