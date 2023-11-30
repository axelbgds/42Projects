/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeaugra <abeaugra@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 19:14:03 by abeaugra          #+#    #+#             */
/*   Updated: 2023/10/02 22:40:23 by abeaugra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

static void	read_cub_file2_utilis(char **ident, t_cub *cub)
{
	char	*line;
	char	**ident2;

	if (ft_strcmp(ident[0], SUF_CEIL) == 0)
	{
		line = ft_strdup(ident[1]);
		ident2 = ft_split(line, ',');
		check_colors(ident2);
		cub->map.inv_ceilling = rgba_to_int(255 - ft_atoi(ident2[0]),
				255 - ft_atoi(ident2[1]), 255 - ft_atoi(ident2[2]), 1);
		cub->map.ceiling = rgba_to_int(ft_atoi(ident2[0]), ft_atoi(ident2[1]),
				ft_atoi(ident2[2]), 1);
	}
	else if (ft_strcmp(ident[0], SUF_FLOOR) == 0)
	{
		line = ft_strdup(ident[1]);
		ident2 = ft_split(line, ',');
		check_colors(ident2);
		cub->map.floor = rgba_to_int(ft_atoi(ident2[0]), ft_atoi(ident2[1]),
				ft_atoi(ident2[2]), 1);
	}
	free_line_and_ident(line, ident2);
}

static int	read_cub_file2_utils(int fd, char *line, char **ident, t_cub *cub)
{
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		ident = ft_split(line, ' ');
		if (ft_strcmp(ident[0], SUF_CEIL) == 0
			|| ft_strcmp(ident[0], SUF_FLOOR) == 0)
			read_cub_file2_utilis(ident, cub);
		if ((ident[0][0] == '1' || ident[0][0] == '0')
				&& (cub->map.floor == -1 || cub->map.ceiling == -1))
		{
			free_line_and_ident(line, ident);
			return (0);
		}
		free_line_and_ident(line, ident);
	}
	return (1);
}

void	check_colors(char **ident)
{
	if (!ident[0] || !ident[1] || !ident[2]
		|| (int)ft_strlen(ident[0]) < 1 || (int)ft_strlen(ident[1]) < 1
		|| (int)ft_strlen(ident[2]) < 2)
	{
		ft_printf("Error : Missing color\n");
		exit(0);
	}
	if (ident[3])
	{
		ft_printf("Error : Too many colors\n");
		exit(0);
	}
	if (ft_atoi(ident[0]) > 255 || ft_atoi(ident[1]) > 255
		|| ft_atoi(ident[2]) > 255 || ft_atoi(ident[0]) < 0
		|| ft_atoi(ident[1]) < 0 || ft_atoi(ident[2]) < 0)
	{
		ft_printf("Error : Invalid color\n");
		exit(0);
	}
}

int	read_cub_file2(char *file_name, t_cub *cub)
{
	int		fd;
	char	*line;
	char	**ident;

	fd = open(file_name, O_RDONLY);
	line = NULL;
	ident = NULL;
	if (!read_cub_file2_utils(fd, line, ident, cub))
	{
		ft_printf("Error : Map is before Floor and Ceiling colors\n");
		free_all(cub);
	}
	close(fd);
	return (1);
}
