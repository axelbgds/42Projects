/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alsaez <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 15:42:05 by alsaez            #+#    #+#             */
/*   Updated: 2023/02/07 14:38:53 by alsaez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	char_is_separator(char c, char sep)
{
	if (c == sep || c == '\0')
		return (1);
	return (0);
}

static int	count_words(char *str, char sep)
{
	int	i;
	int	words;

	words = 0;
	i = 0;
	while (str[i] != '\0')
	{
		if (char_is_separator(str[i + 1], sep) == 1
			&& char_is_separator(str[i], sep) == 0)
			words++;
		i++;
	}
	return (words);
}

static int	write_word(char *dest, char *from, char sep)
{
	int	i;

	i = 0;
	while (char_is_separator(from[i], sep) == 0)
	{
		dest[i] = from[i];
		i++;
	}
	dest[i] = '\0';
	return (0);
}

static void	*write_split(char **split, char *str, char sep, int i)
{
	int		j;
	int		word;

	word = 0;
	while (str[i] != '\0')
		if (char_is_separator(str[i], sep) == 1)
			i++;
	else
	{
		j = 0;
		while (char_is_separator(str[i + j], sep) == 0)
			j++;
		split[word] = (char *)malloc(j + 1);
		if (!split[word])
		{
			while (word > 0)
				free(split[--word]);
			free(split);
			return (NULL);
		}
		i += j + write_word(split[word], str + i, sep);
		word++;
	}
	return ((void *)1);
}

char	**ft_split(const char *s, char c)
{
	char	**res;
	char	*str;
	int		words;

	if (s == NULL)
		return (NULL);
	str = (char *)s;
	words = count_words(str, c);
	res = (char **)malloc(sizeof(char *) * (words + 1));
	if (!res)
		return (NULL);
	res[words] = 0;
	if (write_split(res, str, c, 0) == NULL)
		return (NULL);
	return (res);
}
