/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeaugra <abeaugra@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 10:49:40 by abeaugra          #+#    #+#             */
/*   Updated: 2023/08/24 14:40:29 by abeaugra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char **argv)
{
	t_data	data;

	if (argc < 5 || argc > 6)
		return (print_err("error : argument count"));
	if (init_data(&data, argv) == 0)
		return (0);
	if (data.num_philo == 1)
	{
		philo_one(&data);
		return (0);
	}
	philo_many(&data);
	return (0);
}
