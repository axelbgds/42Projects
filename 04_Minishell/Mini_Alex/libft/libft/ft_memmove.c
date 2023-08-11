/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-los- <tde-los-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 10:20:11 by tde-los-          #+#    #+#             */
/*   Updated: 2023/02/08 18:12:19 by tde-los-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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
