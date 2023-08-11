/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-los- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 16:25:21 by tde-los-          #+#    #+#             */
/*   Updated: 2023/02/06 10:57:16 by tde-los-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	const char	*temp;
	size_t		i;

	i = 0;
	temp = (const char *)s;
	while (i < n)
	{
		if (temp[i] == (char)c)
			return ((void *)(temp + i));
		i++;
	}
	return (NULL);
}
