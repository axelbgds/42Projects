/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeaugra <abeaugra@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 13:53:54 by abeaugra          #+#    #+#             */
/*   Updated: 2023/02/16 12:11:29 by abeaugra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

/* 	Alloue (avec malloc(3)) et retourne une copie de
*	la chaîne ’s1’, sans les caractères spécifiés
*	dans ’set’ au début et à la fin de la chaîne de
*	caractères. */

static int	ft_check(char const c, char const *set)
{
	int	i;

	i = 0;
	while (set[i])
		if (set[i++] == c)
			return (1);
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*res;
	int		start;
	int		end;
	int		i;

	if (!s1)
		return (NULL);
	start = 0;
	end = ft_strlen(s1) -1;
	i = 0;
	while (s1[start] && ft_check(s1[start], set))
		start++;
	if (!(s1[start]))
		return (ft_strdup(""));
	while (ft_check(s1[end], set) && end >= 0)
		end--;
	if (start > end || end == 0)
		return (ft_strdup(""));
	res = malloc(end - start + 2);
	if (!res)
		return (NULL);
	while (start <= end)
		res[i++] = (char) s1[start++];
	res[i] = '\0';
	return (res);
}
/*
#include <stdio.h>
int main (void)
{
	printf("%s\n",ft_strtrim("lorem ipsum dolor sit am", "dolorm"));
	return(0);
}*/
