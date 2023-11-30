/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_raycast0.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeaugra <abeaugra@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 14:12:14 by alsaez            #+#    #+#             */
/*   Updated: 2023/10/09 21:35:50 by abeaugra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

void	init_game(t_cub *data)
{
	int	x;
	int	y;

	y = 0;
	while (data->map.map[y])
	{
		x = 0;
		while (data->map.map[y][x])
		{
			if (data->map.map[y][x] == 'N' || data->map.map[y][x] == 'S' ||
					data->map.map[y][x] == 'E' || data->map.map[y][x] == 'W')
				break ;
			x++;
		}
		if (data->map.map[y][x] == 'N' || data->map.map[y][x] == 'S' ||
				data->map.map[y][x] == 'E' || data->map.map[y][x] == 'W')
			break ;
		y++;
	}
	if (!data->map.map[y])
	{
		ft_printf("Error\nPlayer not found\n");
		free_all(data);
	}
	init_textur(data, x, y);
}

void	init_textur(t_cub *cub, int x, int y)
{
	cub->map.player = cub->map.map[y][x];
	cub->posx = x + 0.5;
	cub->posy = y + 0.5;
	cub->phangle = 0 + ((90 * (cub->map.player == 'E'))
			+ (180 * (cub->map.player == 'S'))
			+ (270 * (cub->map.player == 'W')));
	cub->pvangle = 0;
	cub->dirx = (double)(0 + ((cub->map.player == 'W') * -1)
			+ ((cub->map.player == 'E')));
	cub->diry = (double)(0 + ((cub->map.player == 'N') * -1)
			+ ((cub->map.player == 'S')));
	cub->planex = (double)(0 + ((cub->map.player == 'S') * -1)
			+ ((cub->map.player == 'N')));
	cub->planey = (double)(0 + ((cub->map.player == 'E'))
			+ ((cub->map.player == 'W') * -1));
	cub->map.text = malloc(sizeof(t_tex) * 21);
	init_mob(cub);
	init_texture(cub);
}

void	init_texture(t_cub *cub)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		cub->map.text[i].img = mlx_xpm_file_to_image(cub->mlx_ptr,
				cub->map.texture_paths[i], &cub->map.text[i].width,
				&cub->map.text[i].height);
		if (!cub->map.text[i].img)
		{
			ft_printf("Error: Texture not found\n");
			free_all(cub);
		}
		i++;
	}
}

void	calcul_camera(t_cub *cub, int x)
{
	cub->cam[x].camerax = (((double)x * 2) / (double)WIDTH) - 1;
	cub->cam[x].raydiry = cub->diry + (cub->planey * cub->cam[x].camerax);
	cub->cam[x].raydirx = cub->dirx + (cub->planex * cub->cam[x].camerax);
	if (cub->cam[x].raydirx == 0)
		cub->cam[x].d_distx = 50;
	else
		cub->cam[x].d_distx = (1 / cub->cam[x].raydirx)
			* (1 - (2 * (1 / cub->cam[x].raydirx < 0)));
	if (cub->cam[x].raydiry == 0)
		cub->cam[x].d_disty = 50;
	else
		cub->cam[x].d_disty = (1 / cub->cam[x].raydiry)
			* (1 - (2 * (1 / cub->cam[x].raydiry < 0)));
	cub->cam[x].mapx = (int)cub->posx;
	cub->cam[x].mapy = (int)cub->posy;
	camera(cub, x);
}

void	camera(t_cub *cub, int x)
{
	if (cub->cam[x].raydirx < 0)
	{
		cub->cam[x].stepx = -1;
		cub->cam[x].s_distx = (cub->posx - (double)cub->cam[x].mapx)
			* cub->cam[x].d_distx;
	}
	else
	{
		cub->cam[x].stepx = 1;
		cub->cam[x].s_distx = ((double)cub->cam[x].mapx + 1.0 - cub->posx)
			* cub->cam[x].d_distx;
	}
	if (cub->cam[x].raydiry < 0)
	{
		cub->cam[x].stepy = -1;
		cub->cam[x].s_disty = (cub->posy - (double)cub->cam[x].mapy)
			* cub->cam[x].d_disty;
	}
	else
	{
		cub->cam[x].stepy = 1;
		cub->cam[x].s_disty = ((double)cub->cam[x].mapy + 1.0 - cub->posy)
			* cub->cam[x].d_disty;
	}
	raycast(cub, x);
}
