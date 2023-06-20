/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spirnaz <spirnaz@student.42kocaeli.com.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 22:49:40 by spirnaz           #+#    #+#             */
/*   Updated: 2023/06/02 22:49:41 by spirnaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	main(int argc, char **argv)
{
	t_data	data;

	if (argc < 5 || argc > 6)
		return (print_error("error : argument count"));
	if (init_data(&data, argv) == 0)
		return (0);
	if (data.number_of_philosophers == 1)
	{
		philosopher_one(&data);
		return (0);
	}
	philosopher_many(&data);
	return (0);
}
