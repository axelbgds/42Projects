/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse4.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeaugra <abeaugra@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 19:20:24 by abeaugra          #+#    #+#             */
/*   Updated: 2023/10/02 22:28:59 by abeaugra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

// check cube file
static void	is_cub_file(char *file_name, t_cub *cub)
{
	int	len;

	len = (int)ft_strlen(file_name);
	if (len < 4 || ft_strcmp(&file_name[len - 4], ".cub") != 0)
	{
		ft_printf("Error : Invalid .cub file extension\n");
		free_all(cub);
	}
}

// check xpm file
static void	is_xpm_file(char *file_name, t_cub *cub)
{
	int	len;

	len = (int)ft_strlen(file_name);
	if (len < 4 || ft_strcmp(&file_name[len - 4], ".xpm") != 0)
	{
		ft_printf("Error : Invalid xpm file extension\n");
		free_all(cub);
	}
}

// Check if texture exist in texture/path.xpm
void	check_texture(t_cub *cub)
{
	int		i;
	int		fd;
	char	*trimmed_path;

	i = -1;
	while (++i < 4)
	{
		if (cub->map.texture_paths[i])
		{
			trimmed_path = ft_strtrim(cub->map.texture_paths[i], "\n");
			free(cub->map.texture_paths[i]);
			cub->map.texture_paths[i] = ft_strdup(trimmed_path);
			free(trimmed_path);
			is_xpm_file(cub->map.texture_paths[i], cub);
			fd = open(cub->map.texture_paths[i], O_RDONLY);
			if (fd < 0)
			{
				ft_printf("Error : %s Texture not found\n",
					cub->map.texture_paths[i]);
				cub->map.text = NULL;
				free_all(cub);
			}
			close(fd);
		}
	}
}

static void	check_texture_and_free(t_cub *cub, char *line, char **ident)
{
	if ((ident[0][0] == '1' || ident[0][0] == '0')
		&& !cub->map.texture_paths[0])
	{
		ft_printf("Error : Map is before texture!\n");
		free_line_and_ident(line, ident);
		free_all(cub);
	}
	free_line_and_ident(line, ident);
}

int	read_cub_file(char *file_name, t_cub *cub)
{
	int		fd;
	char	*line;
	char	**ident;

	is_cub_file(file_name, cub);
	if (!read_cub_file_utils(cub, file_name))
		return (-1);
	fd = open(file_name, O_RDONLY);
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		ident = ft_split(line, ' ');
		check_texture_and_free(cub, line, ident);
	}
	close(fd);
	check_texture(cub);
	if (!read_cub_file2(file_name, cub))
		return (-1);
	read_cub_file3(file_name, cub);
	return (0);
}
