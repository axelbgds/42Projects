/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeaugra <abeaugra@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 14:36:25 by abeaugra          #+#    #+#             */
/*   Updated: 2023/02/15 12:37:21 by abeaugra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*	The strstr() function locates the first occurrence of the null-terminated 
*	string needle in the null-terminated string haystack.*/

char	*ft_strnstr(const char *s1, const char *s2, size_t len)
{
	size_t	i;

	if (!s2[0])
		return ((char *)s1);
	if (!len)
		return (NULL);
	i = 0;
	while (s1[i] && i < len)
	{
		if (ft_strncmp(s2, s1 + i, ft_strlen(s2)) == 0
			&& i + ft_strlen(s2) <= len)
			return ((char *)s1 + i);
		i++;
	}
	return (NULL);
}

/*
int 	main(int ac, char **av)
{
	char *s1 = av[1];
	char *s2 = av[2];

	if (ac == 3)
	{
		s1 = ft_strnstr(s1, s2, 3);
		printf("%s\n", s2);
	}
	return (0);
}
*/
