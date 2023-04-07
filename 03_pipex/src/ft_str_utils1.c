/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_utils1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeaugra <abeaugra@student.42perp.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 11:44:29 by abeaugra          #+#    #+#             */
/*   Updated: 2023/04/07 14:00:00 by abeaugra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

/*	The strdup() function allocates sufficient memory for a copy of the
*	string s1, does the copy, and returns a pointer to it.  The pointer may
*	subsequently be used as an argument to the function free(3).*/

char	*ft_strdup(const char *s1)
{
	char	*result;
	int		index;

	index = 0;
	while (s1[index])
		index++;
	result = malloc(sizeof(*result) * (index + 1));
	if (!result)
		return (NULL);
	index = 0;
	while (s1[index])
	{
		result[index] = s1[index];
		index++;
	}
	result[index] = '\0';
	return (result);
}

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

/*	Alloue (avec malloc(3)) et retourne une nouvelle
*	chaîne, résultat de la concaténation de s1 et s2.*/

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	s1size;
	size_t	s2size;
	char	*ret;

	if (s1 == NULL && s2 == NULL)
		return (NULL);
	s1size = ft_strlen(s1);
	s2size = ft_strlen(s2);
	ret = malloc(s1size + s2size + 1);
	if (ret == NULL)
		return (NULL);
	ft_memcpy(ret, s1, s1size);
	ft_memcpy(ret + s1size, s2, s2size);
	ret[s1size + s2size] = 0;
	return (ret);
}

/*The strlcpy() and strlcat() functions copy and con-
 * catenate strings with the same input parameters and
 * output result as snprintf(3).  They are designed to
 * be safer, more consistent, and less error prone
 * replacements for the easily misused functions
 * strncpy(3) and strncat(3).*/

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	cur;

	if (size == 0)
		return (ft_strlen(src));
	cur = 0;
	while (src[cur] && cur < (size - 1))
	{
		dst[cur] = src[cur];
		cur++;
	}
	dst[cur] = 0;
	return (ft_strlen(src));
}

/*	The strncmp() function compares not more than n characters.  Because
*	strncmp() is designed for comparing strings rather than binary data,
*	characters that appear after a `\0' character are not compared.*/

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	if (n == 0)
		return (0);
	while (s1[i] && s2[i] && (unsigned char)s1[i] == (unsigned char)s2[i]
		&& i < (n - 1))
		i++;
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}
