/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeaugra <abeaugra@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 14:36:25 by abeaugra          #+#    #+#             */
/*   Updated: 2022/03/30 09:18:25 by abeaugra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*	The strstr() function locates the first occurrence of the null-terminated 
*	string needle in the null-terminated string haystack.*/

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;
	int		check;

	if (ft_strncmp(needle, "", ft_strlen(needle)) == 0)
		return ((char *) haystack);
	i = 0;
	while (haystack[i] && i < len)
	{
		j = 0;
		check = 1;
		if (haystack[i] == needle[j])
		{
			while (needle[j])
			{
				if (needle[j] != haystack[i + j] || i + j >= len)
					check = 0;
				j++;
			}
			if (check == 1)
				return ((char *) haystack + i);
		}
		i++;
	}
	return (NULL);
}
