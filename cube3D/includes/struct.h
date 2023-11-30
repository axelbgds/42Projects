/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeaugra <abeaugra@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 21:03:15 by abeaugra          #+#    #+#             */
/*   Updated: 2023/10/09 21:35:50 by abeaugra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

# include "./cub3D.h"

typedef struct s_tex
{
	int		width;
	int		height;
	void	*img;
	int		*addr;
	int		color;
	int		bpp;
	int		line_len;
	int		endian;
}	t_tex;

typedef struct s_spr
{
	double	x;
	double	y;
	double	spritex;
	double	spritey;
	double	dist;
	double	invert;
	double	transx;
	double	transy;
	int		spr_screenx;
	int		spr_hgt;
	int		spr_wth;
	int		draw_starty;
	int		draw_endy;
	int		draw_startx;
	int		draw_endx;
	int		tex_x;
	int		tex_y;
	int		tex;
}	t_spr;

typedef struct s_img
{
	void	*mlx_img;
	char	*addr;
	int		bpp;
	int		line_len;
	int		endian;
}	t_img;

typedef struct s_map
{
	char		**map;
	char		*texture_paths[4];
	int			map_width;
	int			map_height;
	char		player;
	void		*mlx;
	double		x;
	double		y;
	int			inv_ceilling;
	int			ceiling;
	int			floor;
	t_tex		*text;
}	t_map;

typedef struct s_player
{
	t_map	minimap;
	double	angle;
	double	speed;
	int		advance;
	int		retreat;
	int		left;
	int		right;
	int		l_rotate;
	int		r_rotate;
	int		exit;
}	t_player;

typedef struct s_cam
{
	double	camerax;
	double	cameray;
	double	raydirx;
	double	raydiry;
	double	d_distx;
	double	d_disty;
	double	s_distx;
	double	s_disty;
	double	hit;
	int		stepx;
	int		stepy;
	double	w_dist;
	double	w_x;
	int		mapx;
	int		mapy;
	double	line_height;
	int		side;
	int		tex_num;
	int		tex_x;
	int		tex_y;
	double	tex_pos;
	int		draw_start;
	int		draw_end;
}	t_cam;

typedef struct s_cub
{
	void		*mlx_ptr;
	void		*win_ptr;
	int			phangle;
	int			pvangle;
	double		dirx;
	double		diry;
	double		planex;
	double		planey;
	double		posx;
	double		posy;
	int			error;
	int			nb_spr;
	int			*spr_odr;
	t_player	player;
	t_map		map;
	t_img		img;
	t_cam		*cam;
	t_spr		*spr;
}	t_cub;

#endif
