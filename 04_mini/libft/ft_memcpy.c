/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeaugra <abeaugra@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 10:06:32 by abeaugra          #+#    #+#             */
/*   Updated: 2023/08/28 14:03:07 by abeaugra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	char		*dtemp;
	const char	*stemp;

	if (!src && !dest)
		return (NULL);
	dtemp = (char *)dest;
	stemp = (char *)src;
	while (n--)
		*dtemp++ = *stemp++;
	return (dest);
}
