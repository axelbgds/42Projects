/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pos_validator.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elorenze <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/06 09:31:39 by elorenze          #+#    #+#             */
/*   Updated: 2022/02/06 10:28:57 by elorenze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "structs.h"

int	count_visible_tower(t_runtime *runtime, int side, int pos)
{
	int i;
	int current_tower;
	int highest;
	int count;

	highest = 0;
	i = 0;
	count = 0;
	while (i < 4)
	{
		if (side == 0)
			current_tower = runtime->map[pos][i];
		else if (side == 1)
			current_tower = runtime->map[pos][3-i];
		else if (side == 2)
			current_tower = runtime->map[i][pos];
		else if (side == 3)
			current_tower = runtime->map[3-i][pos];
		if (current_tower > highest)
		{
			highest = current_tower;
			count++;
		}
		i++;
	}
	return (count);
}

int check_duplicate(t_runtime *runtime, int x, int y)
{
	int	p;
	int	i;

	p = runtime->map[x][y];
	i = 0;
	while (i < y)
	{
		if (runtime->map[x][i] == p)
			return (-1);
		i++;
	}
	i = 0;
	while (i < x)
	{
		if (runtime->map[i][y] == p)
			return (-1);
		i++;
	}
	return (0);
}

int	check_seek_match(t_runtime *runtime, int x, int y)
{
	if (
		count_visible_tower(runtime, 0, x) > runtime->seeking[0][x]
		|| count_visible_tower(runtime, 2, y) > runtime->seeking[2][y]
	)
		return (-1);
	if (
		y == 3
		&& (
			count_visible_tower(runtime, 0, x) != runtime->seeking[0][x]
			||   count_visible_tower(runtime, 1, x) != runtime->seeking[1][x]
		)
	)
		return (-1);
	if (
		x == 3
		&& (
			count_visible_tower(runtime, 2, y) != runtime->seeking[2][y]
			|| count_visible_tower(runtime, 3, y) != runtime->seeking[3][y]
		)
	)
		return (-1);
	return (0);
}

int	validate_pos(t_runtime *runtime, int x, int y)
{
	if (
		check_duplicate(runtime, x, y) < 0
		|| check_seek_match(runtime, x, y) < 0
	)
		return (-1);
	return (0);
}

