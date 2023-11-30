/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeaugra <abeaugra@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 23:37:53 by abeaugra          #+#    #+#             */
/*   Updated: 2023/10/06 14:30:25 by abeaugra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

// free line and ident
void	free_line_and_ident(char *line, char **ident)
{
	int	i;

	i = 0;
	if (line)
	{
		free(line);
		line = NULL;
	}
	if (ident)
	{
		while (ident[i])
		{
			free(ident[i]);
			i++;
		}
		free(ident);
		ident = NULL;
	}
}

void	free_split(char **ident)
{
	int	i;

	i = 0;
	if (ident)
	{
		while (ident[i])
		{
			free(ident[i]);
			i++;
		}
		free(ident);
	}
}

static void	free_map_and_text(t_cub *cub)
{
	int	i;

	if (cub == NULL)
		return ;
	if (cub->map.map)
		free_split(cub->map.map);
	i = 0;
	while (i < 4)
	{
		if (cub->map.texture_paths[i])
		{
			free(cub->map.texture_paths[i]);
			cub->map.texture_paths[i] = NULL;
		}
		i++;
	}
}

static void	free_resources(t_cub *cub)
{
	int	i;

	i = 0;
	if (cub->map.player)
	{
		while (i < 21)
		{
			if (cub->map.text[i].img != NULL)
				mlx_destroy_image(cub->mlx_ptr, cub->map.text[i].img);
			i++;
		}
		free(cub->map.text);
	}
	if (cub->mlx_ptr)
	{
		mlx_destroy_image(cub->mlx_ptr, cub->img.mlx_img);
		mlx_destroy_window(cub->mlx_ptr, cub->win_ptr);
		mlx_destroy_display(cub->mlx_ptr);
		free(cub->mlx_ptr);
	}
	if (cub->nb_spr)
		free(cub->spr_odr);
	if (cub->nb_spr)
		free(cub->spr);
}

void	free_all(t_cub *cub)
{
	free_map_and_text(cub);
	free_resources(cub);
	if (cub->map.player)
		free(cub->cam);
	exit(0);
}
