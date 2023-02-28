/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   escaper.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elorenze <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 10:38:58 by elorenze          #+#    #+#             */
/*   Updated: 2022/02/16 10:59:41 by elorenze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

#include "ft/ft_putstr.h"
#include "ft/ft_strcpy.h"

static inline int cpy_and_ret(char *dest, char *src)
{
	ft_strcpy(dest, src);
	return (1);
}

int	escape_char(unsigned char c, char *out)
{
	if (c == '\a')
		return cpy_and_ret(out, "\\a");
	if (c == '\b')
		return cpy_and_ret(out, "\\b");
	if (c == '\v')
		return cpy_and_ret(out, "\\v");
	if (c < ' ')
	{
		out[0] = '\\';
		out[1] = '0';
		out[2] = '0' + (c / 010);
		out[3] = '0' + (c % 010);
		out[4] = 0;
		return (1);
	}
	return 0;
}

void	escape_write(int fd, char *str)
{
	char tmp[5];

	while (str[0])
	{
		if (escape_char(str[0], tmp))
			ft_fdputstr(fd, tmp);
		else
			write(fd, str, 1);
		str++;
	}
}
