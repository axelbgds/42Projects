/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeaugra <abeaugra@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 18:09:54 by abeaugra          #+#    #+#             */
/*   Updated: 2023/08/31 11:27:09 by abeaugra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

static char	*ft_strcpy(char *dest, const char *src, size_t start, size_t end)
{
	size_t	i;

	i = 0;
	while (start < end)
	{
		dest[i] = src[start];
		i++;
		start++;
	}
	dest[i] = '\0';
	return (dest);
}

static int	ft_removeset(char c, char const *set)
{
	size_t	i;

	i = 0;
	while (set[i])
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t		i;
	size_t		k;
	size_t		count;
	char		*str;

	i = 0;
	count = 0;
	if (s1 == NULL || set == NULL)
		return (NULL);
	k = ft_strlen(s1);
	while (ft_removeset(s1[i], set) == 1)
		i++;
	if (i != ft_strlen(s1))
	{
		while (k > 0 && ft_removeset(s1[k - 1], set) == 1)
		{
			count++;
			k--;
		}
	}
	str = (char *)malloc(sizeof(char) * (ft_strlen(s1) - (i + count) + 1));
	if (!str)
		return (NULL);
	str = ft_strcpy(str, s1, i, k);
	return (str);
}
