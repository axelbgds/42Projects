/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeaugra <abeaugra@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 15:13:05 by alsaez            #+#    #+#             */
/*   Updated: 2023/10/06 14:11:35 by abeaugra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

void	init_all(t_cub *cub)
{
	cub->mlx_ptr = mlx_init();
	cub->win_ptr = mlx_new_window(cub->mlx_ptr, WIDTH, \
	HEIGHT, "Cub3D alsaez & abeaugran");
	cub->img.mlx_img = mlx_new_image(cub->mlx_ptr, WIDTH, HEIGHT);
	cub->img.addr = mlx_get_data_addr(cub->img.mlx_img,
			&cub->img.bpp, &cub->img.line_len, &cub->img.endian);
	cub->map.map = NULL;
	cub->map.ceiling = -1;
	cub->map.inv_ceilling = -1;
	cub->map.floor = -1;
	cub->map.texture_paths[0] = NULL;
	cub->map.texture_paths[1] = NULL;
	cub->map.texture_paths[2] = NULL;
	cub->map.texture_paths[3] = NULL;
	cub->map.player = '\0';
	cub->map.map_height = 0;
	cub->map.map_width = 0;
	cub->player.advance = 0;
	cub->player.retreat = 0;
	cub->player.left = 0;
	cub->player.right = 0;
	cub->player.l_rotate = 0;
	cub->player.r_rotate = 0;
	cub->player.exit = 0;
	cub->nb_spr = 0;
}

int	draw_game(t_cub *cub)
{
	int	x;

	x = 0;
	move(cub);
	while (x < WIDTH)
		calcul_camera(cub, x++);
	check_sprite(cub);
	sprite(cub);
	mini_map(cub);
	mlx_put_image_to_window(cub->mlx_ptr, cub->win_ptr,
		cub->img.mlx_img, 0, 0);
	return (0);
}

int	main(int ac, char **av)
{
	t_cub	cub;

	if (ac == 2)
	{
		init_all(&cub);
		if (read_cub_file(av[1], &cub) == -1)
		{
			ft_printf("Error : read file .cub\n");
			free_all(&cub);
		}
		cub.cam = malloc(sizeof(t_cam) * WIDTH);
		init_game(&cub);
		check_map(&cub);
		parse_sprite(&cub);
		mlx_hook(cub.win_ptr, 2, 1L << 0, key_events, &cub);
		mlx_hook(cub.win_ptr, 3, 1L << 1, key_release, &cub);
		mlx_hook(cub.win_ptr, 6, 1L << 6, mouse_events, &cub);
		mlx_loop_hook(cub.mlx_ptr, draw_game, &cub);
		mlx_hook(cub.win_ptr, 17, 0L, close_cross, &cub);
		mlx_loop(cub.mlx_ptr);
	}
	else
		ft_printf("%s", ERR_ARG);
	return (1);
}
