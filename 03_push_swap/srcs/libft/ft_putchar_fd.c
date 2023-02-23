/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeaugra <abeaugra@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 14:40:46 by abeaugra          #+#    #+#             */
/*   Updated: 2022/03/30 10:59:16 by abeaugra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*	Écrit le caractère ’c’ sur le descripteur de
*	fichier donné.*/

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}
