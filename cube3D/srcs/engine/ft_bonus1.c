/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bonus1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeaugra <abeaugra@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 15:11:04 by abeaugra          #+#    #+#             */
/*   Updated: 2023/10/09 21:35:50 by abeaugra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

void	draw_dir(t_cub *cub, int min)
{
	int	i;
	int	j;

	j = 0;
	i = 0;
	while (i < (int)((WIDTH / 7) / (cub->map.map_width)) *3)
	{
		pxl_to_img(cub, (int)(((WIDTH / 7) / (cub->map.map_width - min)))
			*(int)((cub->posx) - min) + i * cub->dirx + 10
			+ (int)(((WIDTH / 7) / cub->map.map_width) / 2),
			(int)(((HEIGHT / 7) / cub->map.map_height))
			*(int)(cub->posy) + j * cub->diry + 10 + (int)(((HEIGHT / 7)
					/ cub->map.map_height) / 2), cub->map.inv_ceilling);
		pxl_to_img(cub, (int)(((WIDTH / 7) / (cub->map.map_width - min)))
			*(int)((cub->posx) - min) + i * cub->dirx + 9
			+ (int)(((WIDTH / 7) / cub->map.map_width) / 2),
			(int)(((HEIGHT / 7) / cub->map.map_height))
			*(int)(cub->posy) + j * cub->diry + 9 + (int)(((HEIGHT / 7)
					/ cub->map.map_height) / 2), cub->map.inv_ceilling);
		i++;
		j++;
	}
}

void	draw_player(t_cub *cub, int min)
{
	int	i;
	int	j;

	j = 0;
	if (cub->map.map[(int)cub->posy][(int)cub->posx] != '1')
	{
		while (j < (int)(((HEIGHT / 7) / cub->map.map_height)))
		{
			i = 0;
			while (i < (int)(((WIDTH / 7) / (cub->map.map_width - min))))
			{
				pxl_to_img(cub, (int)((WIDTH / 7) / (cub->map.map_width - min))
					*(int)((cub->posx) - min) + i + 10,
					(int)(((HEIGHT / 7) / cub->map.map_height))
					*(int)(cub->posy) + j + 10, cub->map.inv_ceilling);
				i++;
			}
			j++;
		}
	}
}

void	draw_map(t_cub *cub, int i, int j, int min)
{
	int	x;
	int	y;

	y = 0;
	if ((j + min) < cub->map.map_width && cub->map.map[i][j + min] == '1')
	{
		while (y < (int)(((HEIGHT / 7) / (cub->map.map_height))))
		{
			x = 0;
			while (x <= (int)(((WIDTH / 7) / (cub->map.map_width - min))))
			{
				pxl_to_img(cub, ((int)((WIDTH / 7) / (cub->map.map_width - min))
						*j) + x + 10,
					(int)((HEIGHT / 7) / (cub->map.map_height)) *i
					+ 10 + y, rgba_to_int(160, 0, 0, 1));
				x++;
			}
			y++;
		}
	}
	else if ((j + min) < cub->map.map_width && (cub->map.map[i][j + min] == 'D'
		|| cub->map.map[i][j + min] == 'd'))
		draw_wall(cub, i, j, min);
}

static int	mini_map_parse(int min, t_cub *cub)
{
	int	i;
	int	j;
	int	tmp;

	i = 0;
	min = 2147483647;
	tmp = 0;
	while (cub->map.map[i] != NULL)
	{
		j = 0;
		tmp = 0;
		while (cub->map.map[i][j] && (cub->map.map[i][j] == ' '
			|| cub->map.map[i][j] == '\t'))
		{
			tmp++;
			j++;
		}
		if (tmp < min)
			min = tmp;
		i++;
	}
	return (min);
}

void	mini_map(t_cub *cub)
{
	int	i;
	int	j;
	int	min;

	i = 0;
	min = 0;
	min = mini_map_parse(min, cub);
	draw_square(cub, min);
	while (cub->map.map[i] != NULL)
	{
		j = 0;
		while (cub->map.map[i][j])
		{
			draw_map(cub, i, j, min);
			j++;
		}
		i++;
	}
	draw_player(cub, min);
	draw_dir(cub, min);
}
