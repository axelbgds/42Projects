/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elorenze <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/05 13:56:32 by elorenze          #+#    #+#             */
/*   Updated: 2022/02/06 10:30:14 by elorenze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pos_validator.h"
#include "structs.h"

int	iterate_numbers(t_runtime *runtime, int x, int y)
{
	int	*col;
	int	ret;

	col = runtime->map[x];
	col[y] = 0;
	while (col[y] < 4)
	{
		col[y]++;
		ret = validate_pos(runtime, x, y);
		if (ret < 0)
			continue;
		else
		{
			if (y == 3 && x == 3)
				return (1);
			if (y == 3)
				ret = iterate_numbers(runtime, x+1, 0);
			else
				ret = iterate_numbers(runtime, x, y+1);
			if (ret == 1)
				return (1);
		}
	}
	col[y] = 0;
	return (-1);
}

int	fill_map(t_runtime *runtime)
{
	return iterate_numbers(runtime, 0, 0);
}
