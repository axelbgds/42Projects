/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_one.c                                  		:+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeaugra <abeaugra@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 12:35:15 by abeaugra          #+#    #+#             */
/*   Updated: 2023/08/24 14:36:40 by abeaugra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	*philo_one_func(void *void_philosopher)
{
	t_philo	*philosopher;
	t_data	*data;

	philosopher = (t_philo *)void_philosopher;
	data = philosopher->data;
	pthread_mutex_lock(&data->forks[0]);
	philo_writer(philosopher, "has taken a fork");
	pthread_mutex_unlock(&data->forks[0]);
	philo_wait(data, data->time_to_die);
	philo_writer(philosopher, "died");
	return (NULL);
}

void	philo_one(t_data *data)
{
	data->start_time = get_time_ms();
	if (pthread_create(&data->philo[0].thd_id, NULL, \
	philo_one_func, &data->philo[0]) != 0)
	{
		printf("error : pthread_create");
		clear_data(data);
		return ;
	}
	pthread_join(data->philo[0].thd_id, NULL);
	clear_data(data);
}
