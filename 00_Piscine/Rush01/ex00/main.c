/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elorenze <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/05 08:55:06 by elorenze          #+#    #+#             */
/*   Updated: 2022/02/06 09:30:11 by elorenze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

#include "args.h"
#include "ft_memset.h"
#include "structs.h"
#include "seek_validator.h"
#include "filler.h"

void	display_map(t_runtime *runtime)
{
	int		x;
	int		y;
	char	c;

	y = 0;
	while (y < 4)
	{
		x = 0;
		while (x < 4)
		{
			c = runtime->map[x][y] + '0';
			write(1, &c, 1);
			if (x < 3)
				write(1, " ", 1);
			x++;
		}
		write(1, "\n", 1);
		y++;
	}
}

int	main(int argc, char **argv)
{	
	t_runtime	runtime;

	ft_memset(&runtime, 0, sizeof(runtime));
	if (args_parse(argc, argv, &runtime) < 0)
	{
		write(1, "Error\n", 6);
		return (1);
	}
	if (validate_seek(&runtime) < 0)
	{
		write(1, "Error\n", 6);
		return (1);
	}
	if (fill_map(&runtime) < 0)
	{
		write(1, "Error\n", 6);
		return (1);
	}
	else
	{
		display_map(&runtime);	
	}
	return (0);
}
