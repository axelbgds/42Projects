/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elorenze <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/05 08:54:45 by elorenze          #+#    #+#             */
/*   Updated: 2022/02/05 10:33:51 by elorenze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "structs.h"
#include "ft_strlen.h"

int	args_validate(char *arg)
{
	int	num;

	num = 1;
	if (ft_strlen(arg) != 31)
		return (-1);
	while (arg[0])
	{
		if (num && (arg[0] < '1' || arg[0] > '4'))
			return (-1);
		if ((!num) && arg[0] != ' ')
			return (-1);
		arg++;
		num = (!num);
	}
	return (0);
}

int	args_parse(int argc, char **argv, t_runtime *runtime)
{
	int	i;

	i = 0;
	if (argc != 2)
		return (-1);
	if (args_validate(argv[1]) < 0)
		return (-1);
	while (i < 31)
	{
		runtime->seeking[i / 8][(i / 2) % 4] = argv[1][i] - '0';
		i += 2;
	}
	return (0);
}
