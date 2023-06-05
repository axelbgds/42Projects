/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeaugra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 11:36:31 by abeaugra          #+#    #+#             */
/*   Updated: 2023/06/05 11:36:42 by abeaugra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol_bonus.h"

int	mouse_actions(int key, int x, int y, t_data *data)
{
	if (key == SCROLL_DOWN && data->zoom >= 4)
		return (0);
	if (key == SCROLL_UP)
	{
		data->zoom -= 0.03 * data->zoom;
		data->x_offset += ((double)(x - (WIDTH / 2)) *0.0001 * data->zoom)
			+ 0.01 * data->zoom;
		data->y_offset += ((double)(y - (HEIGHT / 2)) *0.0001 * data->zoom)
			+ 0.01 * data->zoom;
	}
	if (key == SCROLL_DOWN)
	{
		data->zoom += 0.03 * data->zoom;
		data->x_offset += ((double)(x - (WIDTH / 2)) *0.0001 * data->zoom)
			-0.01 * data->zoom;
		data->y_offset += ((double)(y - (HEIGHT / 2)) *0.0001 * data->zoom)
			-0.01 * data->zoom;
	}
	draw_fractal(data);
	mlx_do_sync(data->mlx->mlx);
	mlx_put_image_to_window(data->mlx->mlx, data->mlx->win,
		data->mlx->img, 0, 0);
	return (0);
}

int	close_window(t_data *data)
{
	mlx_destroy_image(data->mlx->mlx, data->mlx->img);
	mlx_destroy_window(data->mlx->mlx, data->mlx->win);
	mlx_destroy_display(data->mlx->mlx);
	free(data->mlx->mlx);
	free(data->mlx->title);
	exit(0);
}

int	keyboard_actions(int key, t_data *data)
{
	if (key == ESC)
		close_window(data);
	else if (key == SPACE)
		data->hue += 0.1;
	else if (key == UP)
		data->y_offset += -0.03 * data->zoom;
	else if (key == DOWN)
		data->y_offset += 0.03 * data->zoom;
	else if (key == RIGHT)
		data->x_offset += 0.03 * data->zoom;
	else if (key == LEFT)
		data->x_offset += -0.03 * data->zoom;
	draw_fractal(data);
	mlx_do_sync(data->mlx->mlx);
	mlx_put_image_to_window(data->mlx->mlx, data->mlx->win,
		data->mlx->img, 0, 0);
	return (0);
}
