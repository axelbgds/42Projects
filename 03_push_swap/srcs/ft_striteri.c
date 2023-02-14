/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeaugra <abeaugra@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 14:39:29 by abeaugra          #+#    #+#             */
/*   Updated: 2022/03/30 16:42:27 by abeaugra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*	Applique la fonction ’f’ à chaque caractère de la
*	chaîne de caractères transmise comme argument,
*	et en passant son index comme premier argument.
*	Chaque caractère est transmis par adresse à ’f’
*	afin d’être modifié si nécessaire.*/

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	unsigned int	i;

	if (!s || !f)
		return ;
	i = -1;
	if (s)
		while (s[++i])
			f(i, &(*(s + i)));
}
