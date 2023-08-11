/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-los- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 12:04:45 by tde-los-          #+#    #+#             */
/*   Updated: 2023/02/08 18:23:50 by tde-los-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*str;

	if (nmemb == 0 || size == 0)
		return (malloc(0));
	if (nmemb > 65535 / size)
		return (NULL);
	str = malloc(nmemb * size);
	if (str)
		ft_bzero(str, nmemb * size);
	return (str);
}
