/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeaugra <abeaugra@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 15:10:10 by alsaez            #+#    #+#             */
/*   Updated: 2023/10/09 21:35:50 by abeaugra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

int	close_cross(t_cub *cub)
{
	free_all(cub);
	exit(EXIT_SUCCESS);
	return (0);
}

void	move_cam_left(t_cub *cub)
	{
	cub->phangle -= 5;
	if (cub->phangle <= 0)
		cub->phangle += 360;
	cub->dirx = -1 * -sin(((double)cub->phangle * M_PI) / 180);
	cub->diry = -1 * cos(((double)cub->phangle * M_PI) / 180);
	cub->planex = 1 * cos(((double)cub->phangle * M_PI) / 180);
	cub->planey = 1 * sin(((double)cub->phangle * M_PI) / 180);
}

void	move_cam_right(t_cub *cub)
{
	cub->phangle += 5;
	if (cub->phangle >= 360)
		cub->phangle -= 360;
	cub->dirx = -1 * (-sin(((double)cub->phangle * M_PI) / (double)180));
	cub->diry = -1 * (cos(((double)cub->phangle * M_PI) / (double)180));
	cub->planex = 1 * (cos(((double)cub->phangle * M_PI) / (double)180));
	cub->planey = 1 * (sin(((double)cub->phangle * M_PI) / (double)180));
}

void	open_door(t_cub *cub)
{
	if (cub->map.map[(int)(cub->posy)][(int)(cub->posx)] != 'd')
	{
		if (cub->map.map[(int)(cub->posy + (cub->diry * 1.5))][(int)(cub->posx
			+ (cub->dirx * 1.5))] == 'D')
			cub->map.map[(int)(cub->posy + (cub->diry * 1.5))][(int)(cub->posx
					+ (cub->dirx * 1.5))] = 'd';
		else if (cub->map.map[(int)(cub->posy + (cub->diry / 5))]
			[(int)(cub->posx + (cub->dirx / 5))] == 'D')
			cub->map.map[(int)(cub->posy + (cub->diry / 5))][(int)(cub->posx
					+ (cub->dirx / 5))] = 'd';
		else if (cub->map.map[(int)(cub->posy + (cub->diry * 1.5))]
			[(int)(cub->posx + (cub->dirx * 1.5))] == 'd')
			cub->map.map[(int)(cub->posy + (cub->diry * 1.5))][(int)(cub->posx
					+ (cub->dirx * 1.5))] = 'D';
		else if (cub->map.map[(int)(cub->posy + (cub->diry / 5))]
			[(int)(cub->posx + (cub->dirx / 5))] == 'd')
			cub->map.map[(int)(cub->posy + (cub->diry / 5))][(int)(cub->posx
					+ (cub->dirx / 5))] = 'D';
	}
	cub->player.exit = 0;
}
