/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_number2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsharma <tsharma@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/12 20:44:50 by tsharma           #+#    #+#             */
/*   Updated: 2022/02/13 21:03:51 by tsharma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

#include "structs.h"
#include "ft_strlen.h"

char	*find_number(struct s_dict_entry *en, int num, int zero, int entryc)
{
	int	i;

	i = 0;
	while (i < entryc)
	{
		if (en[i].num == num && en[i].zero == zero)
			return (en[i].word);
		i++;
	}
	return (0);
}

void	ft_putstr(char *str, int print_space)
{
	int	i;

	i = 0;
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
	if (print_space)
		write(1, " ", 1);
}

void	print_num_rec(
		struct s_dictionary dict,
		int value,
		int ze,
		int put_space)
{
	int	flag;

	if (value / 100 > 0)
	{
		ft_putstr(find_number(dict.en, value / 100, 0, dict.enc), 1);
		flag = (ze || (value % 100 != 0));
		ft_putstr(find_number(dict.en, 1, 2, dict.enc), flag);
	}
	if (value % 100 != 0)
	{
		if (find_number(dict.en, value % 100, 0, dict.enc) != 0)
			ft_putstr(find_number(dict.en, value % 100, 0, dict.enc),
				ze);
		else
		{
			ft_putstr(find_number(dict.en, value % 100 / 10, 1, dict.enc),
				(value % 10) || ze);
			if (value % 100 % 10 != 0)
				ft_putstr(find_number(dict.en, value % 100 % 10, 0, dict.enc),
					ze);
		}
	}
	if (ze)
		ft_putstr(find_number(dict.en, 1, ze, dict.enc), ze && put_space);
}

void	print_value(int value, int ze, struct s_dictionary dict, int put_space)
{
	if (find_number(dict.en, value, 0, dict.enc) == 0)
		print_num_rec(dict, value, ze, put_space);
	else
	{
		if (value != 0)
		{
			ft_putstr(find_number(dict.en, value, 0, dict.enc), ze);
			if (ze > 0)
				ft_putstr(find_number(dict.en, 1, ze, dict.enc), 0);
			if (put_space)
				ft_putstr(" ", 0);
		}
	}
}
