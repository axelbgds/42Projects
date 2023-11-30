/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeaugra <abeaugra@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 15:41:42 by alsaez            #+#    #+#             */
/*   Updated: 2023/10/09 21:25:00 by abeaugra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *s1, const char *s2, size_t n)
{
	size_t	i;
	size_t	j;

	i = 0;
	if ((!s1 || !s2) && !n)
		return (0);
	if (!ft_strlen(s2))
		return ((char *)s1);
	while (i < n && s1[i] != '\0')
	{
		j = 0;
		while ((i + j) < n && s1[i + j] == s2[j] && s2[j] != '\0')
		{
			j++;
			if (s2[j] == '\0')
				return ((char *)s1 + i);
		}
		i++;
	}
	return (NULL);
}
