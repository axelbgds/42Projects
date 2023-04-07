/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeaugra <abeaugra@student.42perp.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 10:42:06 by abeaugra          #+#    #+#             */
/*   Updated: 2023/04/07 13:59:36 by abeaugra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static size_t	words_count(char *s, char c)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (*s)
	{
		if (*s != c)
			i++;
		else if (*s == c && i != 0)
		{
			j++;
			i = 0;
		}
		s++;
	}
	if (i != 0)
		j++;
	return (j);
}

static char	*word(char *s, char c)
{
	char	*buf;

	while (*s == c)
		s++;
	buf = s;
	while (*buf && *buf != c)
		buf++;
	*buf = '\0';
	return (ft_strdup(s));
}

static char	**free_arr(char **arr, char *s)
{
	size_t	i;

	i = 0;
	while (arr[i])
	{
		free(arr[i]);
		i++;
	}
	free(arr);
	free(s);
	return (NULL);
}

static char	**worker(char **arr, char *s1, char c, size_t j)
{
	size_t	i;
	char	*str;

	str = s1;
	i = 0;
	while (i < j)
	{
		if (*s1 != c)
		{
			arr[i] = word(s1, c);
			if (!arr[i])
				return (free_arr(arr, s1));
			s1 = s1 + ft_strlen(arr[i]);
			i++;
		}
		s1++;
	}
	arr[i] = NULL;
	free(str);
	return (arr);
}

char	**ft_split(char const *s, char c)
{
	char	**w_arr;
	char	*s1;
	size_t	j;

	s1 = ft_strdup(s);
	if (!s1)
		return (NULL);
	j = words_count(s1, c);
	w_arr = (char **)malloc(sizeof(char *) * (j + 1));
	if (!w_arr)
		return (NULL);
	return (worker(w_arr, s1, c, j));
}

/*words_count : compte le nombre de mots dans la chaîne s en
**utilisant le caractère c comme délimiteur.word : extrait 
**un mot de la chaîne s en se basant sur le caractère c. 
**Il retourne une nouvelle chaîne de caractères allouée 
**contenant ce mot.

**free_arr : libère la mémoire allouée pour le tableau de 
**chaînes de caractères arr et la chaîne s. 
**Retourne NULL pour faciliter l'utilisation dans 
**d'autres fonctions.

**worker : remplit le tableau arr avec les mots extraits de 
**la chaîne s1 en utilisant le caractère c comme délimiteur.
**Libère la mémoire de la chaîne originale s1.

**ft_split : fonction principale qui divise la chaîne de 
**caractères s en sous-chaînes en utilisant le caractère c.
**Crée un tableau de chaînes de caractères pour stocker 
**les mots et appelle les fonctions précédemment mentionnées 
**pour effectuer le travail
*/
