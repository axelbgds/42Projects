/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_number.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsharma <tsharma@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/12 11:52:22 by tsharma           #+#    #+#             */
/*   Updated: 2022/02/13 23:11:58 by tsharma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "structs.h"
#include <stdio.h>

int	validate(int value, int ze, struct s_dict_entry *en, int ec)
{
	char	*valid;

	if (find_number(en, value, 0, ec) == 0)
		return (valid_rec(en, value, ze, ec));
	else
	{
		valid = find_number(en, value, 0, ec);
		if (valid == 0)
			return (-2);
		if (ze > 0 && find_number(en, 1, ze, ec) == 0)
			return (-2);
		return (0);
	}
}

int	first_set_v(char *number, struct s_dict_entry *en, int entryc)
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
	{
		if (validate(value, len - j, en, entryc) == 0)
			return (0);
		else
			return (-2);
	}
	return (0);
}

int	second_set_v(char *number, struct s_dict_entry *en, int entryc)
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
		if (validate(value, len - j, en, entryc) == -2)
			return (-2);
		i += 3;
	}
	return (0);
}

int	pre_run(char *number)
{
	int	i;

	i = 0;
	while (number[i] != '\0')
	{
		if (!(number[i] > 47 && number[i] < 58))
			return (-1);
		i++;
	}
	return (0);
}

int	validate_number(struct s_dict_entry *entries, int entryc, char *number)
{
	int	i;

	i = pre_run(number);
	if (i == 0)
	{
		i = first_set_v(number, entries, entryc);
		if (i == 0)
		{
			return (0);
			i = second_set_v(number, entries, entryc);
		}
	}
	return (i);
}
