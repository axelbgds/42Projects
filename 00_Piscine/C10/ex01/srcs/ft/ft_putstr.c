/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elorenze <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 08:55:28 by elorenze          #+#    #+#             */
/*   Updated: 2022/02/16 11:26:54 by elorenze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

#include "ft_strlen.h"

int	ft_fdputstr(int fd, char *str)
{
	return (write(fd, str, ft_strlen(str)));
}

int	ft_putstr(char *str)
{
	return ft_fdputstr(1, str);
}
