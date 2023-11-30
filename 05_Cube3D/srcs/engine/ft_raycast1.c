/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_raycast1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeaugra <abeaugra@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 16:12:25 by alsaez            #+#    #+#             */
/*   Updated: 2023/10/09 21:35:50 by abeaugra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

void	raycast(t_cub *cub, int x)
{
	while (1)
	{
		if (cub->map.map[cub->cam[x].mapy][cub->cam[x].mapx] == '1')
			break ;
		if (cub->map.map[cub->cam[x].mapy][cub->cam[x].mapx] == 'D')
			break ;
		if (cub->cam[x].s_distx < cub->cam[x].s_disty)
		{
			cub->cam[x].s_distx += cub->cam[x].d_distx;
			cub->cam[x].mapx += cub->cam[x].stepx;
			cub->cam[x].side = 0;
		}
		else
		{
			cub->cam[x].s_disty += cub->cam[x].d_disty;
			cub->cam[x].mapy += cub->cam[x].stepy;
			cub->cam[x].side = 1;
		}
	}
	if (cub->cam[x].side == 0)
		cub->cam[x].w_dist = cub->cam[x].s_distx - cub->cam[x].d_distx;
	else
		cub->cam[x].w_dist = cub->cam[x].s_disty - cub->cam[x].d_disty;
	raycast2(cub, x);
}

void	raycast2(t_cub *cub, int x)
{
	cub->cam[x].line_height = (int)(HEIGHT / cub->cam[x].w_dist);
	cub->cam[x].draw_start = ((-1 * cub->cam[x].line_height) / 2)
		+ (HEIGHT / 2);
	if (cub->cam[x].draw_start < 0)
		cub->cam[x].draw_start = 0;
	cub->cam[x].draw_end = (cub->cam[x].line_height / 2) + (HEIGHT / 2);
	if (cub->cam[x].draw_end >= HEIGHT)
		cub->cam[x].draw_end = HEIGHT - 1;
	cub->map.text[0].addr = (int *)mlx_get_data_addr(cub->map.text[0].img,
			&cub->map.text[0].bpp, &cub->map.text[0].line_len,
			&cub->map.text[0].endian);
	cub->map.text[1].addr = (int *)mlx_get_data_addr(cub->map.text[1].img,
			&cub->map.text[1].bpp, &cub->map.text[1].line_len,
			&cub->map.text[1].endian);
	cub->map.text[2].addr = (int *)mlx_get_data_addr(cub->map.text[2].img,
			&cub->map.text[2].bpp, &cub->map.text[2].line_len,
			&cub->map.text[2].endian);
	cub->map.text[3].addr = (int *)mlx_get_data_addr(cub->map.text[3].img,
			&cub->map.text[3].bpp, &cub->map.text[3].line_len,
			&cub->map.text[3].endian);
	cub->map.text[20].addr = (int *)mlx_get_data_addr(cub->map.text[20].img,
			&cub->map.text[20].bpp, &cub->map.text[20].line_len,
			&cub->map.text[20].endian);
	raycast3(cub, x);
}

void	raycast3(t_cub *cub, int x)
{
	if (cub->cam[x].side == 0)
	{
		cub->cam[x].tex_num = 2 + (cub->cam[x].mapx > cub->posx);
		if (cub->map.map[cub->cam[x].mapy][cub->cam[x].mapx] == 'D')
			cub->cam[x].tex_num = 20;
		cub->cam[x].w_x = cub->posy + cub->cam[x].w_dist * cub->cam[x].raydiry;
	}
	else
	{
		cub->cam[x].tex_num = 0 + (cub->cam[x].mapy > cub->posy);
		if (cub->map.map[cub->cam[x].mapy][cub->cam[x].mapx] == 'D')
			cub->cam[x].tex_num = 20;
		cub->cam[x].w_x = cub->posx + cub->cam[x].w_dist * cub->cam[x].raydirx;
	}
	cub->cam[x].w_x -= floor(cub->cam[x].w_x);
	cub->cam[x].tex_x = cub->cam[x].w_x
		* (double)cub->map.text[cub->cam[x].tex_num].width;
	if (cub->cam[x].side == 0 && cub->cam[x].raydirx > 0)
		cub->cam[x].tex_x = cub->map.text[cub->cam[x].tex_num].width
			- cub->cam[x].tex_x - 1;
	if (cub->cam[x].side == 1 && cub->cam[x].raydiry < 0)
		cub->cam[x].tex_x = cub->map.text[cub->cam[x].tex_num].width
			- cub->cam[x].tex_x - 1;
	raycast4(cub, x);
}

void	raycast4(t_cub *cub, int x)
{
	cub->map.text[4].addr = (int *)mlx_get_data_addr(cub->map.text[4].img,
			&cub->map.text[4].bpp, &cub->map.text[4].line_len,
			&cub->map.text[4].endian);
	cub->map.text[5].addr = (int *)mlx_get_data_addr(cub->map.text[5].img,
			&cub->map.text[5].bpp, &cub->map.text[5].line_len,
			&cub->map.text[5].endian);
	cub->map.text[6].addr = (int *)mlx_get_data_addr(cub->map.text[6].img,
			&cub->map.text[6].bpp, &cub->map.text[6].line_len,
			&cub->map.text[6].endian);
	cub->map.text[7].addr = (int *)mlx_get_data_addr(cub->map.text[7].img,
			&cub->map.text[7].bpp, &cub->map.text[7].line_len,
			&cub->map.text[7].endian);
	cub->map.text[8].addr = (int *)mlx_get_data_addr(cub->map.text[8].img,
			&cub->map.text[8].bpp, &cub->map.text[8].line_len,
			&cub->map.text[8].endian);
	cub->map.text[9].addr = (int *)mlx_get_data_addr(cub->map.text[9].img,
			&cub->map.text[9].bpp, &cub->map.text[9].line_len,
			&cub->map.text[9].endian);
	cub->map.text[10].addr = (int *)mlx_get_data_addr(cub->map.text[10].img,
			&cub->map.text[10].bpp, &cub->map.text[10].line_len,
			&cub->map.text[10].endian);
	cub->map.text[11].addr = (int *)mlx_get_data_addr(cub->map.text[11].img,
			&cub->map.text[11].bpp, &cub->map.text[11].line_len,
			&cub->map.text[11].endian);
	raycast5(cub, x);
}

void	raycast5(t_cub *cub, int x)
{
	cub->map.text[12].addr = (int *)mlx_get_data_addr(cub->map.text[12].img,
			&cub->map.text[12].bpp, &cub->map.text[12].line_len,
			&cub->map.text[12].endian);
	cub->map.text[13].addr = (int *)mlx_get_data_addr(cub->map.text[17].img,
			&cub->map.text[13].bpp, &cub->map.text[13].line_len,
			&cub->map.text[13].endian);
	cub->map.text[14].addr = (int *)mlx_get_data_addr(cub->map.text[14].img,
			&cub->map.text[14].bpp, &cub->map.text[14].line_len,
			&cub->map.text[14].endian);
	cub->map.text[15].addr = (int *)mlx_get_data_addr(cub->map.text[15].img,
			&cub->map.text[15].bpp, &cub->map.text[15].line_len,
			&cub->map.text[15].endian);
	cub->map.text[16].addr = (int *)mlx_get_data_addr(cub->map.text[16].img,
			&cub->map.text[16].bpp, &cub->map.text[16].line_len,
			&cub->map.text[16].endian);
	cub->map.text[17].addr = (int *)mlx_get_data_addr(cub->map.text[17].img,
			&cub->map.text[17].bpp, &cub->map.text[17].line_len,
			&cub->map.text[17].endian);
	cub->map.text[18].addr = (int *)mlx_get_data_addr(cub->map.text[18].img,
			&cub->map.text[18].bpp, &cub->map.text[18].line_len,
			&cub->map.text[18].endian);
	cub->map.text[19].addr = (int *)mlx_get_data_addr(cub->map.text[19].img,
			&cub->map.text[19].bpp, &cub->map.text[19].line_len,
			&cub->map.text[19].endian);
	print_image(cub, x);
}
