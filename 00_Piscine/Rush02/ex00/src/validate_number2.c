/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_number2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsharma <tsharma@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/13 18:43:55 by tsharma           #+#    #+#             */
/*   Updated: 2022/02/13 22:47:20 by tsharma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "structs.h"
#include <stdio.h>

int	valid_rec(struct s_dict_entry *en, int value, int ze, int ec)
{
	(void) ze;
	if (value / 100 > 0)
	{
		if (find_number(en, value / 100, 0, ec) == 0)
			return (-2);
		else if (find_number(en, 1, 2, ec) == 0)
			return (-2);
	}
	if (value % 100 != 0)
	{
		if (find_number(en, value % 100, 0, ec) == 0)
		{
			if (find_number(en, value % 100 / 10, 1, ec) == 0)
				return (-2);
			else if (find_number(en, value % 100 % 10, 0, ec) == 0)
				return (-2);
		}
	}
	if (ze && find_number(en, 1, ze, ec) == 0)
		return (-2);
	return (0);
}
