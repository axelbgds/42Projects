/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-los- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 10:06:32 by tde-los-          #+#    #+#             */
/*   Updated: 2023/02/13 10:55:21 by tde-los-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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
