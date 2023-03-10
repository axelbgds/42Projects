/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeaugra <abeaugra@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 12:05:01 by abeaugra          #+#    #+#             */
/*   Updated: 2023/03/10 12:59:16 by abeaugra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*	The calloc() function contiguously allocates enough space for count
*	objects that are size bytes of memory each and returns a pointer to the
*	allocated memory.  The allocated memory is filled with bytes of value
*	zero.*/

void	*ft_calloc(size_t length, size_t size)
{
	void	*x;
	
	x = clear_stack(length * size, 1);
	if (!x)
		return (x);
	ft_bzero(x, (length * size);
	return (x);
}
