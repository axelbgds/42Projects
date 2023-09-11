/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeaugra <abeaugra@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 12:15:31 by abeaugra          #+#    #+#             */
/*   Updated: 2023/08/28 14:03:07 by abeaugra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

static int	ft_countword(char const *s, char c)
{
	int	i;
	int	count;
	int	inword;

	i = 0;
	count = 0;
	inword = 0;
	while (s[i] != '\0')
	{
		if (s[i] == c)
			inword = 0;
		else if (inword == 0)
		{
			inword = 1;
			count++;
		}
		i++;
	}
	return (count);
}

static int	ft_wordlen(char const *s, char c)
{
	int	i;

	i = 0;
	while (s[i] != '\0' && s[i] != c)
		i++;
	return (i);
}

static char	**ft_strtab(char const *s, char c, char **tab, int count)
{
	int	i;
	int	j;
	int	len;

	i = 0;
	while (i < count)
	{
		while (*s == c)
			s++;
		len = ft_wordlen(s, c);
		tab[i] = (char *)malloc(sizeof(**tab) * (len + 1));
		if (tab[i] == NULL)
			return (NULL);
		j = 0;
		while (j < len)
		{
			tab[i][j] = *s;
			j++;
			s++;
		}
		tab[i][j] = '\0';
		i++;
	}
	tab[i] = 0;
	return (tab);
}

char	**ft_split(char const *s, char c)
{
	char	**tab;
	int		wordcount;

	if (s == NULL)
		return (NULL);
	wordcount = ft_countword(s, c);
	tab = (char **)malloc(sizeof(char *) * (wordcount + 1));
	if (tab == NULL)
		return (NULL);
	tab = ft_strtab(s, c, tab, wordcount);
	return (tab);
}
