/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeaugra <abeaugra@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 14:56:31 by abeaugra          #+#    #+#             */
/*   Updated: 2023/03/14 13:15:05 by abeaugra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*	Écrit la chaîne de caractères ’s’ sur le
*	descripteur de fichier donné.*/

void	ft_putstr(char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		write(1, &s[i], 1);
		i++;
	}
}
/*
int main(void)
{
	char *str;
	str = "je m'appelle Axel";
	ft_putstr(str);
}*/
