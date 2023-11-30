/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bonus.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeaugra <abeaugra@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 10:33:33 by alsaez            #+#    #+#             */
/*   Updated: 2023/10/06 14:44:06 by abeaugra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

static void	init_door(t_cub *cub)
{
	cub->map.text[20].img = mlx_xpm_file_to_image(cub->mlx_ptr,
			"./textures/door.xpm", &cub->map.text[20].width,
			&cub->map.text[20].height);
}

static void	init_mob2(t_cub *cub)
{
	cub->map.text[12].img = mlx_xpm_file_to_image(cub->mlx_ptr,
			"./textures/zizi_copter9.xpm", &cub->map.text[12].width,
			&cub->map.text[12].height);
	cub->map.text[13].img = mlx_xpm_file_to_image(cub->mlx_ptr,
			"./textures/zizi_copter10.xpm", &cub->map.text[13].width,
			&cub->map.text[13].height);
	cub->map.text[14].img = mlx_xpm_file_to_image(cub->mlx_ptr,
			"./textures/zizi_copter11.xpm", &cub->map.text[14].width,
			&cub->map.text[14].height);
	cub->map.text[15].img = mlx_xpm_file_to_image(cub->mlx_ptr,
			"./textures/zizi_copter12.xpm", &cub->map.text[15].width,
			&cub->map.text[15].height);
	cub->map.text[16].img = mlx_xpm_file_to_image(cub->mlx_ptr,
			"./textures/zizi_copter13.xpm", &cub->map.text[16].width,
			&cub->map.text[16].height);
	cub->map.text[17].img = mlx_xpm_file_to_image(cub->mlx_ptr,
			"./textures/zizi_copter14.xpm", &cub->map.text[17].width,
			&cub->map.text[17].height);
	cub->map.text[18].img = mlx_xpm_file_to_image(cub->mlx_ptr,
			"./textures/zizi_copter15.xpm", &cub->map.text[18].width,
			&cub->map.text[18].height);
	cub->map.text[19].img = mlx_xpm_file_to_image(cub->mlx_ptr,
			"./textures/zizi_copter0.xpm", &cub->map.text[19].width,
			&cub->map.text[19].height);
	init_door(cub);
}

void	init_mob(t_cub *cub)
{
	cub->map.text[4].img = mlx_xpm_file_to_image(cub->mlx_ptr,
			"./textures/zizi_copter1.xpm", &cub->map.text[4].width,
			&cub->map.text[4].height);
	cub->map.text[5].img = mlx_xpm_file_to_image(cub->mlx_ptr,
			"./textures/zizi_copter2.xpm", &cub->map.text[5].width,
			&cub->map.text[5].height);
	cub->map.text[6].img = mlx_xpm_file_to_image(cub->mlx_ptr,
			"./textures/zizi_copter3.xpm", &cub->map.text[6].width,
			&cub->map.text[6].height);
	cub->map.text[7].img = mlx_xpm_file_to_image(cub->mlx_ptr,
			"./textures/zizi_copter4.xpm", &cub->map.text[7].width,
			&cub->map.text[7].height);
	cub->map.text[8].img = mlx_xpm_file_to_image(cub->mlx_ptr,
			"./textures/zizi_copter5.xpm", &cub->map.text[8].width,
			&cub->map.text[8].height);
	cub->map.text[9].img = mlx_xpm_file_to_image(cub->mlx_ptr,
			"./textures/zizi_copter6.xpm", &cub->map.text[9].width,
			&cub->map.text[9].height);
	cub->map.text[10].img = mlx_xpm_file_to_image(cub->mlx_ptr,
			"./textures/zizi_copter7.xpm", &cub->map.text[10].width,
			&cub->map.text[10].height);
	cub->map.text[11].img = mlx_xpm_file_to_image(cub->mlx_ptr,
			"./textures/zizi_copter8.xpm", &cub->map.text[11].width,
			&cub->map.text[11].height);
	init_mob2(cub);
}

static void	parse_sprite_utils(int count, t_cub *cub)
{
	int	i;
	int	j;

	if (cub->nb_spr > 0)
	{
		cub->spr = malloc(sizeof(t_spr) * (cub->nb_spr + 1));
		cub->spr_odr = malloc(sizeof(int *) * cub->nb_spr);
	}
	i = 0;
	while (cub->map.map[i] != NULL)
	{
		j = 0;
		while (cub->map.map[i][j])
		{
			if (cub->map.map[i][j] == 'Z')
			{
				cub->spr[count].x = j + 0.5;
				cub->spr[count].y = i + 0.5;
				cub->spr[count].tex = 4;
				count++;
			}
			j++;
		}
		i++;
	}
}

void	parse_sprite(t_cub *cub)
{
	int	i;
	int	j;
	int	count;

	j = 0;
	i = 0;
	count = 0;
	while (cub->map.map[i] != NULL)
	{
		j = 0;
		while (cub->map.map[i][j])
		{
			if (cub->map.map[i][j] == 'Z')
			{
				cub->nb_spr++;
			}
			j++;
		}
		i++;
	}
	parse_sprite_utils(count, cub);
}
