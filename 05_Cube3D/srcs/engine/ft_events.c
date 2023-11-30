/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_events.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeaugra <abeaugra@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 09:21:08 by alsaez            #+#    #+#             */
/*   Updated: 2023/10/09 21:35:36 by abeaugra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

int	key_events(int key, t_cub *cub)
{
	if (key == XK_Escape)
	{
		free_all(cub);
		exit(0);
	}
	if (key == XK_w || key == XK_Up)
		cub->player.advance = 1;
	if (key == XK_a)
		cub->player.left = 1;
	if (key == XK_s || key == XK_Down)
		cub->player.retreat = 1;
	if (key == XK_d)
		cub->player.right = 1;
	if (key == XK_q || key == XK_Left)
		cub->player.l_rotate = 1;
	if (key == XK_e || key == XK_Right)
		cub->player.r_rotate = 1;
	if (key == XK_space)
		cub->player.exit = 1;
	return (0);
}

int	key_release(int key, t_cub *cub)
{
	if (key == XK_Escape)
	{
		free_all(cub);
		exit(0);
	}
	if (key == XK_w || key == XK_Up)
		cub->player.advance = 0;
	if (key == XK_a)
		cub->player.left = 0;
	if (key == XK_s || key == XK_Down)
		cub->player.retreat = 0;
	if (key == XK_d)
		cub->player.right = 0;
	if (key == XK_q || key == XK_Left)
		cub->player.l_rotate = 0;
	if (key == XK_e || key == XK_Right)
		cub->player.r_rotate = 0;
	if (key == XK_space)
		cub->player.exit = 0;
	return (0);
}

static void	mouse_events_utils(t_cub *cub, int *value, int x)
{
	cub->phangle -= *value - x;
	if (cub->phangle <= 0)
		cub->phangle += 360;
	if (cub->phangle > 360)
		cub->phangle -= 360;
	cub->dirx = -1 * -sin(((double)cub->phangle * M_PI) / 180);
	cub->diry = -1 * cos(((double)cub->phangle * M_PI) / 180);
	cub->planex = 1 * cos(((double)cub->phangle * M_PI) / 180);
	cub->planey = 1 * sin(((double)cub->phangle * M_PI) / 180);
	*value = 0;
}

int	mouse_events(int x, int y, t_cub *cub)
{
	static int	value = 0;

	mlx_mouse_hide(cub->mlx_ptr, cub->win_ptr);
	if (x > ((WIDTH / 2) + (WIDTH / 5)))
	{
		mlx_mouse_move(cub->mlx_ptr, cub->win_ptr, (WIDTH / 2), HEIGHT / 2);
		x = (WIDTH / 2);
		value = (WIDTH / 2);
	}
	if (x < ((WIDTH / 2) - (WIDTH / 5)))
	{
		mlx_mouse_move(cub->mlx_ptr, cub->win_ptr, (WIDTH / 2), HEIGHT / 2);
		value = WIDTH / 2;
		x = (WIDTH / 2);
	}
	if (y > (HEIGHT / 2) + (WIDTH / 5))
		mlx_mouse_move(cub->mlx_ptr, cub->win_ptr, (WIDTH / 2), HEIGHT / 2);
	if (y < (HEIGHT / 2) - (WIDTH / 5))
		mlx_mouse_move(cub->mlx_ptr, cub->win_ptr, (WIDTH / 2), HEIGHT / 2);
	if (value == 0)
		value = x;
	else
		mouse_events_utils(cub, &value, x);
	return (1);
}
