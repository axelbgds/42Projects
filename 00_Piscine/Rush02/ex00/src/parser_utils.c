/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elorenze <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/12 17:10:53 by elorenze          #+#    #+#             */
/*   Updated: 2022/02/13 11:01:58 by elorenze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "structs.h"

#include <stdio.h>

int	parser_intlen(char *str)
{
	int	i;
	int	j;

	i = 0;
	while (1)
	{
		while ((str[i] >= '1' && str[i] <= '9') || (i == 0 && str[i] == '0'))
			i++;
		j = 0;
		while (str[i + j] == '0')
			j++;
		if (str[i + j] >= '1' && str[i + j] <= '9')
			i += j;
		else
			break ;
	}
	return (i);
}

int	parser_atoi(char *str, unsigned int n)
{
	int	ret;
	int	mult;

	if (n == 0)
		return (-1);
	str += n - 1;
	ret = 0;
	mult = 1;
	while (n)
	{
		ret += (str[0] - '0') * mult;
		mult *= 10;
		if (ret < 0)
			return (-1);
		str--;
		n--;
	}
	return (ret);
}

unsigned int	parser_wordlen(char *str)
{
	unsigned int	size;

	size = 0;
	while (str[0])
	{
		if (str[0] >= ' ' && str[0] <= '~')
			size++;
		else if (str[-1] >= ' ' && str[-1] <= '~')
			size++;
		str++;
	}
	return (size);
}

void	parser_word_copy(char *dest, char *src)
{
	while (src[0])
	{
		if (src[0] >= ' ' && src[0] <= '~')
			dest[0] = src[0];
		else if (src[-1] >= ' ' && src[-1] <= '~')
			dest[0] = ' ';
		else
		{
			src++;
			continue ;
		}
		src++;
		dest++;
	}
	dest[0] = '\0';
}
