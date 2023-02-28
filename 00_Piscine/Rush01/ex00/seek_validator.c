/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   seek_validator.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elorenze <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/05 12:52:23 by elorenze          #+#    #+#             */
/*   Updated: 2022/02/06 09:29:16 by elorenze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "structs.h"

int	validate_seek(t_runtime *runtime)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		if (
			(runtime->seeking[0][i] + runtime->seeking[1][i]) > 5
			|| (runtime->seeking[2][i] + runtime->seeking[3][i]) > 5
		)
			return (-1);
		i++;
	}
	return (0);
}
