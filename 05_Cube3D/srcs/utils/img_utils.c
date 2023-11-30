/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeaugra <abeaugra@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 15:13:05 by alsaez            #+#    #+#             */
/*   Updated: 2023/09/14 23:38:33 by abeaugra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

void	pxl_to_img(t_cub *cub, int x, int y, unsigned int color)
{
	char	*pixel;
	int		i;

	i = cub->img.bpp - 8;
	pixel = cub->img.addr
		+ (y * cub->img.line_len + x * (cub->img.bpp / 8));
	while (i >= 0)
	{
		if (cub->img.endian != 0)
			*pixel++ = (color >> i) & 0xFF;
		else
			*pixel++ = (color >> (cub->img.bpp - 8 - i)) & 0xFF;
		i -= 8;
	}
}

int	rgba_to_int(int r, int g, int b, int a)
{
	return ((a << 24) + (r << 16) + (g << 8) + b);
}

void	draw_square(t_cub *cub, int min)
{
	int	i;
	int	j;

	i = 0;
	while (i < (int)((HEIGHT / 7) / cub->map.map_height) * cub->map.map_height)
	{
		j = 0;
		while (j <= (int)((WIDTH / 7) / cub->map.map_width)
				*(cub->map.map_width + min))
		{
			if (j % 2 == 0)
				j++;
			else
			{
				pxl_to_img(cub, (10 + j), (10 + i), rgba_to_int(10, 10, 10, 1));
				j++;
			}
		}
		i++;
	}
}
