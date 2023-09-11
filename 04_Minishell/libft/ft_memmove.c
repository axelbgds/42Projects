/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeaugra <abeaugra@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 10:20:11 by abeaugra          #+#    #+#             */
/*   Updated: 2023/08/28 14:03:07 by abeaugra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	char		*dtemp;
	const char	*stemp;
	size_t		i;

	i = 0;
	if (!dest && !src)
		return (NULL);
	dtemp = (char *)dest;
	stemp = (const char *)src;
	if (dtemp < stemp)
	{
		while (i < n)
		{
			dtemp[i] = stemp[i];
			i++;
		}
	}
	else
	{
		while (n--)
			dtemp[n] = stemp[n];
	}
	return (dest);
}
