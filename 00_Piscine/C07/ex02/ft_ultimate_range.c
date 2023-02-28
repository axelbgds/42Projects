/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elorenze <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 07:32:04 by elorenze          #+#    #+#             */
/*   Updated: 2022/02/10 10:11:12 by elorenze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

/* si min ext negatif, alors on le met a 0 et on augmente de (-min) max */
int	get_size(int min, int max)
{
	if (min < 0)
	{
		max -= min;
		min = 0;
	}
	return (max - min);
}

int	*ft_range(int min, int max)
{
	int		*ret;
	int		i;

	i = min;
	if (min >= max)
		return (0);
	ret = malloc(get_size(min, max) * sizeof(int));
	if (ret == 0)
		return (0);
	while (i < max)
	{
		ret[i - min] = i;
		i++;
	}
	return (ret);
}

int	ft_ultimate_range(int **range, int min, int max)
{
	if (min >= max)
	{
		range[0] = 0;
		return (0);
	}
		range[0] = ft_range(min, max);
	if (range[0] == 0)
		return (-1);
	else
		return (get_size(min, max));
}
