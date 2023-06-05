/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeaugra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 11:37:28 by abeaugra          #+#    #+#             */
/*   Updated: 2023/06/05 11:37:31 by abeaugra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol_bonus.h"

static void	set_image(char **argv, t_mlx *mlx)
{
	mlx->mlx = mlx_init();
	if (!(mlx->mlx))
	{
		perror("mlx_init error");
		exit(0);
	}
	mlx->title = ft_strjoin("Fractol: ", argv[1]);
	mlx->win = mlx_new_window(mlx->mlx, WIDTH, HEIGHT, mlx->title);
	mlx->img = mlx_new_image(mlx->mlx, WIDTH, HEIGHT);
	mlx->addr = mlx_get_data_addr(mlx->img, &mlx->bits_per_pixel,
			&mlx->line_length, &mlx->endian);
}

static int	select_fractal(char **argv, t_data *data, t_mlx *mlx)
{
	data->mlx = mlx;
	data->set = argv[1];
	if (!ft_strncmp(data->set, "Julia", 6))
	{
		data->fractal = &julia;
		data->c.r = ft_atod(argv[2]);
		data->c.i = ft_atod(argv[3]);
	}
	if (!ft_strncmp(data->set, "Mandelbrot", 11))
		data->fractal = &mandelbrot;
	if (!ft_strncmp(data->set, "Celtic", 7))
		data->fractal = &celtic;
	return (0);
}

static int	fractal_position(t_data *data)
{
	data->hue = 0.8;
	if (!ft_strncmp(data->set, "Julia", 6))
	{
		data->x_offset = -1.35;
		data->y_offset = -1.35;
		data->zoom = 2.75;
	}
	else if (!ft_strncmp(data->set, "Mandelbrot", 11))
	{
		data->x_offset = -2.15;
		data->y_offset = -1.5;
		data->zoom = 3.0;
	}
	else if (!ft_strncmp(data->set, "Celtic", 7))
	{
		data->x_offset = -2.6;
		data->y_offset = -2.0;
		data->zoom = 4.0;
	}
	return (0);
}

static void	set_window(t_data *data)
{
	mlx_mouse_hook(data->mlx->win, mouse_actions, data);
	mlx_key_hook(data->mlx->win, keyboard_actions, data);
	mlx_put_image_to_window(data->mlx->mlx, data->mlx->win,
		data->mlx->img, 0, 0);
	mlx_hook(data->mlx->win, 17, 0L, close_window, data);
	mlx_loop(data->mlx->mlx);
}

int	main(int argc, char **argv)
{
	t_mlx	mlx;
	t_data	data;

	if (argc < 2 || argc > 4
		|| ((ft_strncmp(argv[1], "Julia", 6) || argc != 4
				|| !ft_isdouble(argv[2]) || !ft_isdouble(argv[3]))
			&& (ft_strncmp(argv[1], "Mandelbrot", 11) || argc != 2)
			&& (ft_strncmp(argv[1], "Celtic", 7) || argc != 2)))
	{
		ft_printf("\nInvalid argument(s)");
		ft_printf("\n%s", "Usage: ./fractol Julia (-)double_num (-)double_num");
		ft_printf("\n%s", "   or: ./fractol Mandelbrot");
		ft_printf("\n%s\n", "   or: ./fractol Celtic");
		exit(1);
	}
	set_image(argv, &mlx);
	select_fractal(argv, &data, &mlx);
	fractal_position(&data);
	draw_fractal(&data);
	set_window(&data);
	return (0);
}
