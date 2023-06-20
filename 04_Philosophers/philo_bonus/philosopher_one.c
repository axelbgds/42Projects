/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher_one.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spirnaz <spirnaz@student.42kocaeli.com.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 22:51:13 by spirnaz           #+#    #+#             */
/*   Updated: 2023/06/02 22:51:14 by spirnaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

static void	philosopher_one_func(void *void_philosopher)
{
	t_philosopher	*philosopher;
	t_data			*data;

	philosopher = (t_philosopher *)void_philosopher;
	data = philosopher->data;
	sem_wait(data->forks);
	philosopher_writer(philosopher, "has taken a fork");
	sem_post(data->forks);
	philosopher_wait(data, data->time_to_die);
	philosopher_writer(philosopher, "died");
	clear_data(data);
	exit(EXIT_SUCCESS);
}

void	philosopher_one(t_data *data)
{
	int	waitpid_return;

	data->start_time = get_time_milliseconds();
	data->philosophers[0].process_id = fork();
	if (data->philosophers[0].process_id < 0)
	{
		printf("error : fork");
		clear_data(data);
		return ;
	}
	if (data->philosophers[0].process_id == 0)
	{
		philosopher_one_func(&data->philosophers[0]);
	}
	waitpid(data->philosophers[0].process_id, &waitpid_return, 0);
	if (waitpid_return != 0)
		kill(data->philosophers[0].process_id, SIGKILL);
	clear_data(data);
}
