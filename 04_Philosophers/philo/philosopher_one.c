/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher_one.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spirnaz <spirnaz@student.42kocaeli.com.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 22:50:32 by spirnaz           #+#    #+#             */
/*   Updated: 2023/06/02 22:50:33 by spirnaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

static void	*philosopher_one_func(void *void_philosopher)
{
	t_philosopher	*philosopher;
	t_data			*data;

	philosopher = (t_philosopher *)void_philosopher;
	data = philosopher->data;
	pthread_mutex_lock(&data->forks[0]);
	philosopher_writer(philosopher, "has taken a fork");
	pthread_mutex_unlock(&data->forks[0]);
	philosopher_wait(data, data->time_to_die);
	philosopher_writer(philosopher, "died");
	return (NULL);
}

void	philosopher_one(t_data *data)
{
	data->start_time = get_time_milliseconds();
	if (pthread_create(&data->philosophers[0].thread_id, NULL, \
	philosopher_one_func, &data->philosophers[0]) != 0)
	{
		printf("error : pthread_create");
		clear_data(data);
		return ;
	}
	pthread_join(data->philosophers[0].thread_id, NULL);
	clear_data(data);
}
