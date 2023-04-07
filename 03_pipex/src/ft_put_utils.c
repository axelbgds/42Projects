/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeaugra <abeaugra@student.42perp.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 14:40:46 by abeaugra          #+#    #+#             */
/*   Updated: 2023/04/07 11:34:53 by abeaugra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

/*	Écrit le caractère ’c’ sur le descripteur de
*	fichier donné.*/

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

/*	Écrit La chaîne de caractères ’s’ sur le
*	descripteur de fichier donné suivie d’un retour à
*	la ligne.*/

void	ft_putendl_fd(char *s, int fd)
{
	if (!s)
		return ;
	ft_putstr_fd(s, fd);
	write(fd, "\n", 1);
}

/*	Écrit la chaîne de caractères ’s’ sur le
*	descripteur de fichier donné.*/

void	ft_putstr_fd(char *s, int fd)
{
	int	i;

	i = 0;
	while (s[i])
	{
		write(fd, &s[i], 1);
		i++;
	}
}
