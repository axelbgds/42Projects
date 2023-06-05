/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithms.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeaugra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 11:37:11 by abeaugra          #+#    #+#             */
/*   Updated: 2023/06/05 11:37:15 by abeaugra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int	julia(t_point z, t_point c)
{
	t_point		z_square;
	int			count;

	z_square.r = pow(z.r, 2);
	z_square.i = pow(z.i, 2);
	count = 0;
	while (z_square.r + z_square.i < 4 && count < MAX_ITER)
	{
		z.i = (2 * z.r * z.i) + c.i;
		z.r = z_square.r - z_square.i + c.r;
		z_square.r = pow(z.r, 2);
		z_square.i = pow(z.i, 2);
		count++;
	}
	return (count);
}

int	mandelbrot(t_point c, t_point v)
{
	t_point		z;
	t_point		z_square;
	int			count;

	(void)v;
	z.r = 0;
	z.i = 0;
	z_square.r = pow(z.r, 2);
	z_square.i = pow(z.i, 2);
	count = 0;
	while (z_square.r + z_square.i < 4 && count < MAX_ITER)
	{
		z.i = (2 * z.r * z.i) + c.i;
		z.r = z_square.r - z_square.i + c.r;
		z_square.r = pow(z.r, 2);
		z_square.i = pow(z.i, 2);
		count++;
	}
	return (count);
}

static int	create_color(double hue, int count)
{
	int	red;
	int	green;
	int	blue;

	red = sin(0.2 * count + hue + 0) * 127 + 128;
	green = sin(0.2 * count + hue + 2) * 127 + 128;
	blue = sin(0.2 * count + hue + 4) * 127 + 128;
	return (red << 16 | green << 8 | blue);
}

void	draw_fractal(t_data *data)
{
	int		x;
	int		y;
	double	scale;
	t_point	c;
	char	*put_pixel;

	x = -1;
	while (x++ < WIDTH)
	{
		y = -1;
		while (y++ < HEIGHT)
		{	
			scale = data->zoom / WIDTH;
			c.r = x * scale + data->x_offset;
			c.i = y * scale + data->y_offset;
			put_pixel = data->mlx->addr + (x * (data->mlx->bits_per_pixel / 8))
				+ (y * data->mlx->line_length);
			if (data->fractal(c, data->c) < MAX_ITER)
				*(unsigned int *)put_pixel = create_color(data->hue,
						data->fractal(c, data->c));
			else
				*(unsigned int *)put_pixel = 0x0000000;
		}
	}
}
