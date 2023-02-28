/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elorenze <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 07:06:55 by elorenze          #+#    #+#             */
/*   Updated: 2022/02/01 07:19:07 by elorenze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	print_hex_char(unsigned char c)
{
	char tmp[3] = "\\";
	
	tmp[1] = "0123456789abcdef"[c/0x10];
	tmp[2] = "0123456789abcdef"[c%0x10];

	write(1, tmp, 3);
}

void	ft_putstr_non_printable(char *str)
{
	while (str[0])
	{
		if (str[0] >= ' ' && str[0] <= '~')
			write(1, str, 1);
		else
			print_hex_char(str[0]);
		str++;
	}	
}
