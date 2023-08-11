/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-los- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 11:01:59 by tde-los-          #+#    #+#             */
/*   Updated: 2023/02/06 12:08:02 by tde-los-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t				i;
	const unsigned char	*temps1;
	const unsigned char	*temps2;

	temps1 = (const unsigned char *)s1;
	temps2 = (const unsigned char *)s2;
	i = 0;
	while (i < n && temps1[i] == temps2[i])
		i++;
	if (i == n)
		return (0);
	return ((int)(temps1[i] - temps2[i]));
}
