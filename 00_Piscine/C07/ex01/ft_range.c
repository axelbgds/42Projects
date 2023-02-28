/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elorenze <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 07:08:28 by elorenze          #+#    #+#             */
/*   Updated: 2022/02/10 10:08:26 by elorenze         ###   ########.fr       */
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
