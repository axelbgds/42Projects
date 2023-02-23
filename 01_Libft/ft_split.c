/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeaugra <abeaugra@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 13:46:56 by abeaugra          #+#    #+#             */
/*   Updated: 2022/03/30 15:56:10 by abeaugra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	count_words(char const *s, char c)
{
	size_t	count;

	count = 0;
	while (*s)
	{
		while (*s == c)
			s++;
		if (*s != c && *s)
			count++;
		while (*s != c && *s)
			s++;
	}
	return (count);
}

char	*word_dup(const char *s, char c)
{
	size_t	len;
	char	*dup;
	size_t	i;

	len = 0;
	while (s[len] && s[len] != c)
		len ++;
	dup = malloc (sizeof(*dup) *(len + 1));
	if (!dup)
		return (NULL);
	i = 0;
	while (s[i] && i < len)
	{
		dup[i] = s[i];
		i++;
	}
	dup[i] = '\0';
	return (dup);
}

char	**ft_split(char const *s, char c)
{
	size_t	size;
	char	**tab;
	size_t	i;

	if (!s)
		return (NULL);
	size = count_words(s, c);
	tab = malloc(sizeof(*tab) * (size + 1));
	if (!tab)
		return (NULL);
	i = 0;
	while (*s)
	{
		while (*s && *s == c)
			s++;
		if (*s && *s != c)
		{
			tab[i++] = word_dup(s, c);
			while (*s && *s != c)
				s++;
		}
	}
	tab [i] = NULL;
	return (tab);
}
/*
int main ()
{	
	char **tab;
	int i;
	char *str;
	
	str = "Toto et tata fond dodo";
	tab = ft_split(str, ' ');
	i = 0;
	while (tab[i++])
		printf("%s\n", tab[i - 1]);
	return(0);
}*/