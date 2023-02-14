/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeaugra <abeaugra@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 14:38:06 by abeaugra          #+#    #+#             */
/*   Updated: 2022/03/30 15:55:27 by abeaugra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*	Applique la fonction ’f’ à chaque caractère de la
*	chaîne de caractères passée en argument pour créer
*	une nouvelle chaîne de caractères (avec malloc(3))
*	résultant des applications successives de ’f’.*/

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	int		i;
	char	*res;

	if (!s || !f)
		return (NULL);
	res = malloc(ft_strlen(s) + 1);
	if (!res)
		return (NULL);
	i = -1;
	while (s[++i])
		res[i] = f(i, s[i]);
	res[i] = '\0';
	return (res);
}
