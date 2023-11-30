/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeaugra <abeaugra@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 20:57:54 by abeaugra          #+#    #+#             */
/*   Updated: 2023/10/02 22:32:48 by abeaugra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

// Stocke le chemin de la texture à partir du fichier .cub dans texture_paths
void	store_texture_path(char *identifier, char *path, t_cub *cub)
{
	if (ft_strcmp(identifier, D_N) == 0 && !cub->map.texture_paths[0])
		cub->map.texture_paths[0] = ft_strdup(path);
	else if (ft_strcmp(identifier, D_S) == 0 && !cub->map.texture_paths[1])
		cub->map.texture_paths[1] = ft_strdup(path);
	else if (ft_strcmp(identifier, D_W) == 0 && !cub->map.texture_paths[2])
		cub->map.texture_paths[2] = ft_strdup(path);
	else if (ft_strcmp(identifier, D_E) == 0 && !cub->map.texture_paths[3])
		cub->map.texture_paths[3] = ft_strdup(path);
	else
	{
		ft_printf("Error : Too many textures !\n");
		exit(0);
	}
}

static int	ft_check_fd(int fd)
{
	if (fd < 0)
	{
		ft_printf("Error : Cannot open file\n");
		return (0);
	}
	return (1);
}

int	read_cub_file_utils(t_cub *cub, char *file_name)
{
	int		fd;
	char	*line;
	char	**ident;

	fd = open(file_name, O_RDONLY);
	if (!ft_check_fd(fd))
		return (0);
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		ident = ft_split(line, ' ');
		if ((ident[0][0] == '1' || ident[0][0] == '0'))
		{
			free_line_and_ident(line, ident);
			break ;
		}
		if (ft_strcmp(ident[0], D_N) == 0 || ft_strcmp(ident[0], D_S) == 0
			|| ft_strcmp(ident[0], D_W) == 0 || ft_strcmp(ident[0], D_E) == 0)
			store_texture_path(ident[0], ident[1], cub);
		free_line_and_ident(line, ident);
	}
	close(fd);
	return (1);
}
