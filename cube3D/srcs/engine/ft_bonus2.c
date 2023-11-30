/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bonus2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeaugra <abeaugra@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 17:35:13 by alsaez            #+#    #+#             */
/*   Updated: 2023/10/09 21:35:50 by abeaugra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

void	draw_wall(t_cub *cub, int i, int j, int min)
{
	int	x;
	int	y;

	y = 0;
	while (y < (int)(((HEIGHT / 7) / (cub->map.map_height))))
	{
		x = 0;
		while (x <= (int)(((WIDTH / 7) / (cub->map.map_width - min))))
		{
			pxl_to_img(cub, ((int)((WIDTH / 7) / (cub->map.map_width - min))
					*j) + x + 10,
				(int)((HEIGHT / 7) / (cub->map.map_height)) *i
				+ 10 + y, rgba_to_int(10, 160, 10, 1));
			x++;
		}
		y++;
	}
}

void	check_sprite(t_cub *cub)
{
	int			i;
	static int	j = 0;

	i = 0;
	j++;
	if (j == 12)
		j = 0;
	while (i < cub->nb_spr)
	{
		cub->spr[i].dist = (((cub->posx - cub->spr[i].x)
					*(cub->posx - cub->spr[i].x)) + ((cub->posy - cub->spr[i].y)
					*(cub->posy - cub->spr[i].y)));
		cub->spr[i].tex = 4 + j;
		i++;
	}
}

void	ft_sort_sprite(t_cub *cub)
{
	int	i;
	int	j;
	int	count;

	i = 0;
	count = 0;
	while (i < cub->nb_spr)
	{
		j = 0;
		count = 0;
		while (j < cub->nb_spr)
		{
			if (cub->spr[j].dist > cub->spr[i].dist)
				count++;
			j++;
		}
		cub->spr_odr[count] = i;
		i++;
	}
}
