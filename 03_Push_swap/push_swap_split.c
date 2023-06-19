/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_split.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeaugra <abeaugra@student.42perp.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 21:28:38 by abeaugra          #+#    #+#             */
/*   Updated: 2023/06/19 21:31:31 by abeaugra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char
	*ft_strdup(const char *str)
{
	char			*string;
	register size_t	index;

	string = (char *)malloc(sizeof(char) * ft_strlen(str) + 1);
	if (string == NULL)
		return (NULL);
	index = 0;
	while (str[index] != '\0')
	{
		string[index] = str[index];
		index++;
	}
	string[index] = '\0';
	return (string);
}

char
	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*result;
	register size_t	length;

	if (s == NULL)
		return (NULL);
	length = ft_strlen((char *)s);
	if (start > length)
		return (ft_strdup(""));
	if (length - start >= len)
		result = (char *)malloc((len + 1) * sizeof(char));
	else
		result = (char *)malloc((length - start + 1) * sizeof(char));
	if (result == NULL)
		return (NULL);
	ft_strlcpy(result, (char *)&s[start], (len + 1));
	return (result);
}

size_t
	word_count(const char *s, char c)
{
	register int	index;
	register int	count;
	register int	trigger;

	index = 0;
	count = 0;
	trigger = 0;
	while (s[index] != '\0')
	{
		if (s[index] != c && trigger == 0)
		{
				trigger = 1;
				count++;
		}
		else if (s[index] == c)
				trigger = 0;
		index++;
	}
	return (count);
}

char
	*ft_strcreate(const char *s, char c, size_t counter)
{
	register size_t	len;
	register size_t	tmp;

	len = 0;
	tmp = counter;
	while (s[tmp] != c && s[tmp] != '\0')
	{
		tmp++;
		len++;
	}	
	return (ft_substr(s, counter, len));
}

char
	**ft_split(char const *s, char c)
{
	register size_t	counter;
	register size_t	iter;
	char			**res;

	if (!s)
		return (NULL);
	res = (char **)malloc((word_count(s, c) + 1) * sizeof(char *));
	if (!res)
		return (NULL);
	counter = 0;
	iter = 0;
	while (s[counter] != '\0')
	{
		while (s[counter] == c && s[counter] != '\0')
			counter++;
		if (s[counter] != '\0')
		{
			res[iter] = ft_strcreate(s, c, counter);
			iter++;
		}
		while (s[counter] != c && s[counter] != '\0')
			counter++;
	}
	res[iter] = 0;
	return (res);
}
