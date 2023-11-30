/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeaugra <abeaugra@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 19:14:48 by abeaugra          #+#    #+#             */
/*   Updated: 2023/10/02 22:26:15 by abeaugra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

static void	check_map_utils(t_cub *cub, int i, int j)
{
	if (i == cub->map.map_height - 1)
	{
		ft_printf("Error : Map isn't a valid map\n");
		free_all(cub);
	}
	if (!((cub->map.map[i - 1][j] && cub->map.map[i + 1][j]
		&& cub->map.map[i][j - 1] && cub->map.map[i][j + 1])
			&& ((cub->map.map[i][j + 1] == '1' || cub->map.map[i][j + 1] == '0'
			|| cub->map.map[i][j + 1] == cub->map.player
			|| cub->map.map[i][j + 1] == 'D' || cub->map.map[i][j + 1] == 'Z')
			&& (cub->map.map[i][j - 1] == '1' || cub->map.map[i][j - 1] == '0'
			|| cub->map.map[i][j - 1] == cub->map.player
			|| cub->map.map[i][j - 1] == 'D' || cub->map.map[i][j - 1] == 'Z')
			&& (cub->map.map[i + 1][j] == '1' || cub->map.map[i + 1][j] == '0'
			|| cub->map.map[i + 1][j] == cub->map.player
			|| cub->map.map[i + 1][j] == 'D' || cub->map.map[i + 1][j] == 'Z')
			&& (cub->map.map[i - 1][j] == '1' || cub->map.map[i - 1][j] == '0'
			|| cub->map.map[i - 1][j] == cub->map.player || cub->map.map[i - 1]
				[j] == 'D' || cub->map.map[i - 1][j] == 'Z'))))
	{
		ft_printf("Error : Map isn't a valid map\n");
		free_all(cub);
	}
}

void	check_map(t_cub *cub)
{
	int	i;
	int	j;

	i = -1;
	while (cub->map.map[++i])
	{
		j = -1;
		while (cub->map.map[i][++j])
		{
			if ((i == 0) && (cub->map.map[i][j] != '1'
				&& cub->map.map[i][j] != ' ' && cub->map.map[i][j] != '\t'))
			{
				ft_printf("Error2 : Map isn't a valid map\n");
				free_all(cub);
			}
			else if ((i > 0 && j > 0) && (cub->map.map[i][j] == '0'
				|| cub->map.map[i][j] == cub->map.player
				|| cub->map.map[i][j] == 'Z'))
				check_map_utils(cub, i, j);
			else if ((i > 0 && j > 0) && cub->map.map[i][j] == 'D')
				check_door(cub, i, j);
		}
	}
	distinct_player(cub);
}

void	distinct_player(t_cub *cub)
{
	int	i;
	int	j;
	int	flag;

	flag = 0;
	i = -1;
	while (cub->map.map[++i])
	{
		j = -1;
		while (cub->map.map[i][++j])
		{
			if (cub->map.map[i][j] == cub->map.player)
			{
				if (flag == 0)
					flag = 1;
				else
				{
					ft_printf("Error : Too many players\n");
					free_all(cub);
				}
			}
		}
	}
}

static void	read_cub_file3_utils(t_cub *cub, char *file_name, char *line, int i)
{
	int	fd;
	int	j;

	while (i < cub->map.map_height)
		cub->map.map[i++] = ft_calloc(sizeof(char), (size_t)cub->map.map_width);
	fd = open(file_name, O_RDONLY);
	i = 0;
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		j = 0;
		while (line[j] && (line[j] == ' ' || line[j] == '\t'))
			j++;
		if (line[j] == '1' || line[j] == '0')
		{
			j = -1;
			while (++j < (int)ft_strlen(line) - 1)
				cub->map.map[i][j] = line[j];
			i++;
		}
		free(line);
	}
	close(fd);
}

void	read_cub_file3(char *file_name, t_cub *cub)
{
	int		fd;
	char	*line;
	int		i;

	fd = open(file_name, O_RDONLY);
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		i = 0;
		while (line[i] && (line[i] == ' ' || line[i] == '\t'))
			i++;
		if (line[i] == '1' || line[i] == '0')
		{
			cub->map.map_height++;
			if ((int)ft_strlen(line) > cub->map.map_width)
				cub->map.map_width = (int)ft_strlen(line);
		}
		free(line);
	}
	close(fd);
	cub->map.map = malloc(sizeof(char *) * (size_t)(cub->map.map_height + 1));
	cub->map.map[cub->map.map_height] = NULL;
	read_cub_file3_utils(cub, file_name, line, 0);
}
