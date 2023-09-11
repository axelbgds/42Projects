/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_neosplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeaugra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 14:46:13 by abeaugra          #+#    #+#             */
/*   Updated: 2023/08/31 14:46:51 by abeaugra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/mini.h"

int	check_quote(char *str)
{
	while (*str)
	{
		if (*str == 34)
		{
			str++;
			while (*str && *str != 34)
				str++;
			if (!*str)
				return (0);
		}
		if (*str == 39)
		{
			str++;
			while (*str && *str != 39)
				str++;
			if (!*str)
				return (0);
		}
		str++;
	}
	return (1);
}

static int	count_words(const char *s, char c, int i, int trigger)
{
	char	d;

	while (*s)
	{
		if ((*s != c && trigger == 0) || *s == 34 || *s == 39 || *s == 7)
		{
			if (trigger == 0)
				i++;
			if (*s == 34 || *s == 39 || *s == 7)
			{
				d = *s;
				s++;
				while (*s != d)
					s++;
				s++;
				if (!*s)
					return (i);
			}
			trigger = 1;
		}
		if (*s && *s == c)
			trigger = 0;
		s++;
	}
	return (i);
}

static char	*word_dup(const char *str, int start, int finish)
{
	char	*word;
	int		i;

	i = 0;
	word = malloc((finish - start + 1) * sizeof(char));
	while (start < finish)
		word[i++] = str[start++];
	word[i] = '\0';
	start = -1;
	return (word);
}

char	**ft_neosplit(char *str, char c, int i, int j)
{
	int		index;
	char	d;
	char	**split;

	split = malloc(((count_words(str, c, 0, 0) + 1) * sizeof(char *)));
	index = -1;
	while (j < (count_words(str, c, 0, 0)))
	{
		if (str[i] != c && index < 0)
			index = i;
		if (str[i] == 34 || str[i] == 39 || str[i] == 7)
		{
			d = str[i++];
			while (str[i] != d && str[i] != '\0')
				i++;
		}
		else if ((str[i] == c || (size_t)i == ft_strlen(str)) && index >= 0)
		{
			split[j++] = word_dup(str, index, i);
			index = -1;
		}
		i++;
	}
	split[j] = 0;
	return (split);
}
