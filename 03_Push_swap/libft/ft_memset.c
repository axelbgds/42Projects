/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeaugra <abeaugra@student.42perp.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/22 11:20:44 by abeaugra          #+#    #+#             */
/*   Updated: 2023/06/22 11:23:40 by abeaugra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	size_t			i;
	char			*tmp;
	unsigned char	tmpc;

	i = 0;
	tmp = (char *)b;
	tmpc = (unsigned char)c;
	while (i < len)
	{
		tmp[i] = tmpc;
		i++;
	}
	return (b);
}
