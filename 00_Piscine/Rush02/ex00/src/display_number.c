/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_number.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsharma <tsharma@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/12 13:03:00 by tsharma           #+#    #+#             */
/*   Updated: 2022/02/13 21:28:16 by tsharma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "structs.h"
#include "bypass.h"

int	put_space(char *number)
{
	while (number[0] == '0')
		number++;
	return (number[0] != 0);
}

int	first_set(char *number, struct s_dictionary dict)
{
	int	value;
	int	len;
	int	j;

	value = 0;
	j = 0;
	len = ft_strlen(number);
	while (j < (len % 3))
	{
		value = (10 * value) + (number[j] - '0');
		j++;
	}
	if (len % 3 != 0)
		print_value(value, len - j, dict, put_space(number + j));
	return (0);
}

int	second_set(char *number, struct s_dictionary dict)
{
	int	i;
	int	value;
	int	len;
	int	j;

	len = ft_strlen(number);
	i = len % 3;
	value = 0;
	while (i < len)
	{
		j = 0;
		value = 0;
		while (j < 3 && i + j < len)
		{
			value = (10 * value) + (number[i + j] - '0');
			j++;
		}
		print_value(value, len - (i + j), dict, put_space(number + i + j));
		if (put_space(number + i + j) == 0)
			break ;
		i += 3;
	}
	return (0);
}

int	display_number(struct s_dict_entry *en, int entryc, char *number)
{
	struct s_dictionary	dictionary;

	dictionary.en = en;
	dictionary.enc = entryc;
	while (1)
	{
		if (number[0] == '0')
			number++;
		else
			break ;
	}
	if (ft_strlen(number) == 0)
		ft_putstr(find_number(en, 0, 0, entryc), 0);
	else
	{
		first_set(number, dictionary);
		if (put_space(number + (ft_strlen(number) % 3)))
			second_set(number, dictionary);
	}
	write(1, "\n", 1);
	return (0);
}
