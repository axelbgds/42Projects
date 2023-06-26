/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeaugra <abeaugra@student.42perp.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/22 11:20:44 by abeaugra          #+#    #+#             */
/*   Updated: 2023/06/22 11:24:18 by abeaugra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dst_size)
{
	size_t	leng_dst;
	size_t	leng_src;
	size_t	i;
	size_t	limit;

	leng_dst = ft_strlen(dst);
	leng_src = ft_strlen((const char *)src);
	if (dst_size <= leng_dst)
		return (dst_size + leng_src);
	i = 0;
	limit = leng_dst;
	while (src[i] && i < (dst_size - leng_dst - 1))
		dst[limit++] = src[i++];
	dst[limit] = '\0';
	return (leng_dst + leng_src);
}
