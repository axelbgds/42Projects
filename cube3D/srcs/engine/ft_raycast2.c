/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_raycast2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeaugra <abeaugra@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 19:14:48 by abeaugra          #+#    #+#             */
/*   Updated: 2023/10/09 21:12:13 by abeaugra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

void	print_image(t_cub *cub, int x)
{
	int	i;

	cub->cam[x].hit = 1.0 * cub->map.text[cub->cam[x].tex_num].height
		/ cub->cam[x].line_height;
	cub->cam[x].tex_pos = (cub->cam[x].draw_start - (HEIGHT / 2)
			+ (cub->cam[x].line_height / 2)) * cub->cam[x].hit;
	i = 0;
	while (i < HEIGHT)
	{
		if (i < cub->cam[x].draw_start)
			pxl_to_img(cub, x, i, cub->map.ceiling);
		else if (i > cub->cam[x].draw_end)
			pxl_to_img(cub, x, i, cub->map.floor);
		else
		{
			cub->cam[x].tex_y = (int)cub->cam[x].tex_pos
				& (cub->map.text[cub->cam[x].tex_num].height - 1);
			cub->cam[x].tex_pos += cub->cam[x].hit;
			pxl_to_img(cub, x, i,
				cub->map.text[cub->cam[x].tex_num].addr[((cub->cam[x].tex_y
						* cub->map.text[cub->cam[x].tex_num].height))
				+ cub->cam[x].tex_x]);
		}
		i++;
	}
}
