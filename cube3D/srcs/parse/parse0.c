/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeaugra <abeaugra@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 19:14:48 by abeaugra          #+#    #+#             */
/*   Updated: 2023/10/02 22:26:15 by abeaugra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

void	check_door(t_cub *cub, int i, int j)
{
	if (!((cub->map.map[i - 1][j] && cub->map.map[i + 1][j]
		&& cub->map.map[i][j - 1] && cub->map.map[i][j + 1])
		&& ((cub->map.map[i][j + 1] == '1' && cub->map.map[i][j - 1] == '1')
		|| (cub->map.map[i + 1][j] == '1' && cub->map.map[i - 1][j] == '1'))))
	{
		ft_printf("Error : Door isn't a valid door\n");
		free_all(cub);
	}
}
