/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeaugra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 12:38:42 by abeaugra          #+#    #+#             */
/*   Updated: 2023/06/05 12:38:43 by abeaugra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "../libft/libft.h"
# include "../minilix/mlx.h"
# include <math.h>
# include <stdio.h>

# define WIDTH 800
# define HEIGHT 800
# define MAX_ITER 150

# define SCROLL_UP 4
# define SCROLL_DOWN 5
# define SPACE 32
# define ESC 65307

typedef struct s_mlx {
	void	*mlx;
	char	*title;
	void	*win;
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}		t_mlx;

typedef struct s_point {
	double	r;
	double	i;
}		t_point;

typedef struct s_data {
	t_mlx	*mlx;
	char	*set;
	int		(*fractal)(t_point, t_point);
	t_point	c;
	double	hue;
	double	x_offset;
	double	y_offset;
	double	zoom;
}		t_data;

// algorithms.c
int		julia(t_point z, t_point c);
int		mandelbrot(t_point c, t_point v);
void	draw_fractal(t_data *data);

// actions.c
int		mouse_actions(int key, int x, int y, t_data *data);
int		close_window(t_data *data);
int		keyboard_actions(int key, t_data *data);

#endif
