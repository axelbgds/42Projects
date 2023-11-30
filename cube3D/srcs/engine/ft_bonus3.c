/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bonus3.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeaugra <abeaugra@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 17:43:48 by alsaez            #+#    #+#             */
/*   Updated: 2023/10/09 21:35:50 by abeaugra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

static void	animate_sprite_utils(int i, t_cub *cub)
{
	if (cub->spr[cub->spr_odr[i]].draw_endy >= HEIGHT)
		cub->spr[cub->spr_odr[i]].draw_endy = HEIGHT - 1;
	cub->spr[cub->spr_odr[i]].spr_wth = abs((int)(HEIGHT
				/ cub->spr[cub->spr_odr[i]].transy));
	cub->spr[cub->spr_odr[i]].draw_startx = -cub->spr[cub->spr_odr[i]].spr_wth
		/ 2 + cub->spr[cub->spr_odr[i]].spr_screenx;
	if (cub->spr[cub->spr_odr[i]].draw_startx < 0)
		cub->spr[cub->spr_odr[i]].draw_startx = 0;
	cub->spr[cub->spr_odr[i]].draw_endx = cub->spr[cub->spr_odr[i]].spr_wth
		/ 2 + cub->spr[cub->spr_odr[i]].spr_screenx;
	if (cub->spr[cub->spr_odr[i]].draw_endx >= WIDTH)
		cub->spr[cub->spr_odr[i]].draw_endx = WIDTH - 1;
}

static void	animate_sprite(int i, t_cub *cub)
{
	cub->spr[cub->spr_odr[i]].spritex = cub->spr[cub->spr_odr[i]].x
		- cub->posx;
	cub->spr[cub->spr_odr[i]].spritey = cub->spr[cub->spr_odr[i]].y
		- cub->posy;
	cub->spr[cub->spr_odr[i]].invert = 1.0 / (cub->planex * cub->diry
			- cub->dirx * cub->planey);
	cub->spr[cub->spr_odr[i]].transx = cub->spr[cub->spr_odr[i]].invert
		*(cub->diry * cub->spr[cub->spr_odr[i]].spritex - cub->dirx
			*cub->spr[cub->spr_odr[i]].spritey);
	cub->spr[cub->spr_odr[i]].transy = cub->spr[cub->spr_odr[i]].invert
		*((cub->planey * -1) * cub->spr[cub->spr_odr[i]].spritex
			+ cub->planex * cub->spr[cub->spr_odr[i]].spritey);
	cub->spr[cub->spr_odr[i]].spr_screenx = (int)((WIDTH / 2)
			*(1 + cub->spr[cub->spr_odr[i]].transx
				/ cub->spr[cub->spr_odr[i]].transy));
	cub->spr[cub->spr_odr[i]].spr_hgt = abs((int)(HEIGHT
				/ cub->spr[cub->spr_odr[i]].transy));
	cub->spr[cub->spr_odr[i]].draw_starty = -cub->spr[cub->spr_odr[i]].spr_hgt
		/ 2 + HEIGHT / 2;
	if (cub->spr[cub->spr_odr[i]].draw_starty < 0)
		cub->spr[cub->spr_odr[i]].draw_starty = 0;
	cub->spr[cub->spr_odr[i]].draw_endy = cub->spr[cub->spr_odr[i]].spr_hgt / 2
		+ HEIGHT / 2;
	animate_sprite_utils(i, cub);
}

static void	sprite_utilis(int i, int j, t_cub *cub)
{
	cub->spr[cub->spr_odr[i]].tex_x = (int)(256 * (j
				- (-cub->spr[cub->spr_odr[i]].spr_wth / 2
					+ cub->spr[cub->spr_odr[i]].spr_screenx))
			*cub->map.text[cub->spr[cub->spr_odr[i]].tex].width
			/ cub->spr[cub->spr_odr[i]].spr_wth) / 256;
}

static void	sprite_utils(int i, int j, t_cub *cub)
{
	int	k;
	int	color;

	sprite_utilis(i, j, cub);
	if (cub->spr[cub->spr_odr[i]].transy > 0 && j > 0 && j < WIDTH
		&& cub->spr[cub->spr_odr[i]].transy < cub->cam[j].w_dist)
	{
		k = cub->spr[cub->spr_odr[i]].draw_starty;
		while (k < cub->spr[cub->spr_odr[i]].draw_endy)
		{
			cub->spr[cub->spr_odr[i]].tex_y = ((((k * 256 - HEIGHT * 128)
							+ cub->spr[cub->spr_odr[i]].spr_hgt * 128)
						*cub->map.text[cub->spr[cub->spr_odr[i]].tex].height)
					/ cub->spr[cub->spr_odr[i]].spr_hgt) / 256;
			color = cub->map.text[cub->spr[cub->spr_odr[i]].tex].addr[
				((cub->spr[cub->spr_odr[i]].tex_y * cub->map.text[
						cub->spr[cub->spr_odr[i]].tex].height))
				+ cub->spr[cub->spr_odr[i]].tex_x];
			if ((color & 0x0FFFFFF) != 0)
				pxl_to_img(cub, j, k, color);
			k++;
		}
	}
}

void	sprite(t_cub *cub)
{
	int	i;
	int	j;

	i = -1;
	while (++i < cub->nb_spr)
	{
		cub->spr_odr[i] = i;
		cub->spr[i].dist = (((cub->posx - cub->spr[i].x)
					*(cub->posx - cub->spr[i].x)) + ((cub->posy - cub->spr[i].y)
					*(cub->posy - cub->spr[i].y)));
	}
	ft_sort_sprite(cub);
	i = 0;
	while (i < cub->nb_spr)
	{
		animate_sprite(i, cub);
		j = cub->spr[cub->spr_odr[i]].draw_startx;
		while (j < cub->spr[cub->spr_odr[i]].draw_endx)
		{
			sprite_utils(i, j, cub);
			j++;
		}
		i++;
	}
}
