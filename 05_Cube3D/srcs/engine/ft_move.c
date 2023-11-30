/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeaugra <abeaugra@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 15:10:10 by alsaez            #+#    #+#             */
/*   Updated: 2023/10/09 21:35:50 by abeaugra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

void	move(t_cub *cub)
{
	if (cub->player.advance == 1)
		move_front(cub);
	if (cub->player.retreat == 1)
		move_back(cub);
	if (cub->player.left == 1)
		move_left(cub);
	if (cub->player.right == 1)
		move_right(cub);
	if (cub->player.l_rotate == 1)
		move_cam_left(cub);
	if (cub->player.r_rotate == 1)
		move_cam_right(cub);
	if (cub->player.exit == 1)
		open_door(cub);
}

void	move_front(t_cub *cub)
{
	if (cub->map.map[(int)(cub->posy + (cub->diry / 5))][(int)(cub->posx
		+ (cub->dirx / 5))] != '1' && cub->map.map[(int)(cub->posy
		+ (cub->diry / 5))][(int)(cub->posx + (cub->dirx / 5))] != 'D')
	{
		cub->posx += cub->dirx / 10;
		cub->posy += cub->diry / 10;
	}
}

void	move_back(t_cub *cub)
{
	if (cub->map.map[(int)(cub->posy - (cub->diry / 5))][(int)(cub->posx
		- (cub->dirx / 5))] != '1' && cub->map.map[(int)(cub->posy
		- (cub->diry / 5))][(int)(cub->posx - (cub->dirx / 5))] != 'D')
	{
		cub->posx -= cub->dirx / 10;
		cub->posy -= cub->diry / 10;
	}
}

void	move_left(t_cub *cub)
{
	if (cub->map.map[(int)(cub->posy - (cub->dirx / 5))][(int)(cub->posx
		+ (cub->diry / 5))] != '1' && cub->map.map[(int)(cub->posy
		- (cub->dirx / 5))][(int)(cub->posx + (cub->diry / 5))] != 'D')
	{
		cub->posx += cub->diry / 10;
		cub->posy -= cub->dirx / 10;
	}
}

void	move_right(t_cub *cub)
{
	if (cub->map.map[(int)(cub->posy + (cub->dirx / 5))][(int)(cub->posx
		- (cub->diry / 5))] != '1' && cub->map.map[(int)(cub->posy
		+ (cub->dirx / 5))][(int)(cub->posx - (cub->diry / 5))] != 'D')
	{
		cub->posx -= cub->diry / 10;
		cub->posy += cub->dirx / 10;
	}
}
