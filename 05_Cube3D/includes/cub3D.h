/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeaugra <abeaugra@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 13:08:01 by alsaez            #+#    #+#             */
/*   Updated: 2023/10/06 14:43:15 by abeaugra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "struct.h"
# include "../srcs/libft/libft.h"
# include "../minilibx-linux/mlx.h"
# include <X11/X.h>
# include <X11/keysym.h>
# include <math.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stdio.h>
# include <stdbool.h>

// MLX
# define HEIGHT 1080
# define WIDTH 1520

// Directions
# define D_N  "NO"
# define D_E  "EA"
# define D_W  "WE"
# define D_S  "SO"

// Surfaces
# define SUF_FLOOR    "F"
# define SUF_CEIL  "C"

// Error Messages
# define ERR_ARG      "Wrong number of arguments\n"
# define ERR_MAP_NAME "Invalid map name\n"
# define ERR_RGB      "Invalid color value\n"

// Utils
void	init_game(t_cub *data);
void	pxl_to_img(t_cub *cub, int x, int y, unsigned int color);
int		rgba_to_int(int r, int g, int b, int a);

// Error Messages
void	free_line_and_ident(char *line, char **ident);
void	free_split(char **ident);
void	free_all(t_cub *cub);
void	free_map(t_map *map);

// Raycasting
void	calcul_camera(t_cub *cub, int x);
void	camera(t_cub *cub, int x);
void	init_textur(t_cub *cub, int x, int y);
void	init_texture(t_cub *cub);
void	raycast(t_cub *cub, int x);
void	raycast2(t_cub *cub, int x);
void	raycast3(t_cub *cub, int x);
void	raycast4(t_cub *cub, int x);
void	raycast5(t_cub *cub, int x);
void	print_image(t_cub *cub, int x);

// Parsing
int		read_cub_file(char *file_name, t_cub *cub);
int		read_cub_file2(char *file_name, t_cub *cub);
int		read_cub_file_utils(t_cub *cub, char *file_name);
void	store_texture_path(char *identifier, char *path, t_cub *cub);
void	read_cub_file3(char *file_name, t_cub *cub);
void	check_map(t_cub *cub);
void	distinct_player(t_cub *cub);
void	check_texture(t_cub *cub);
void	check_colors(char **ident);

// Key Events
int		close_cross(t_cub *cub);
int		key_events(int key, t_cub *cub);
int		key_release(int key, t_cub *cub);
void	move(t_cub *cub);
void	move_front(t_cub *cub);
void	move_back(t_cub *cub);
void	move_left(t_cub *cub);
void	move_right(t_cub *cub);
void	move_cam_left(t_cub *cub);
void	move_cam_right(t_cub *cub);

// BONUS
void	draw_square(t_cub *cub, int min);
void	draw_player(t_cub *cub, int min);
void	draw_map(t_cub *cub, int i, int j, int min);
void	draw_dir(t_cub *cub, int min);
void	mini_map(t_cub *cub);
int		mouse_events(int x, int y, t_cub *cub);
void	init_mob(t_cub *cub);
void	check_door(t_cub *cub, int i, int j);
void	open_door(t_cub *cub);
void	draw_wall(t_cub *cub, int i, int j, int min);
void	sprite(t_cub *cub);
void	ft_sort_sprite(t_cub *cub);
void	check_sprite(t_cub *cub);
void	parse_sprite(t_cub *cub);

#endif
