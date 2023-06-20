/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher_many.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spirnaz <spirnaz@student.42kocaeli.com.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 22:51:06 by spirnaz           #+#    #+#             */
/*   Updated: 2023/06/02 22:51:08 by spirnaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

static void	wait_and_kill_process(t_data *data)
{
	int	waitpid_return;
	int	i;

	i = 0;
	while (i < data->number_of_philosophers)
	{
		waitpid(-1, &waitpid_return, 0);
		if (waitpid_return != 0)
		{
			i = 0;
			while (i < data->number_of_philosophers)
			{
				kill(data->philosophers[i].process_id, SIGKILL);
				i++;
			}
			break ;
		}
		i++;
	}
}

static void	*died_checker(void *void_philosopher)
{
	t_philosopher	*philosopher;
	t_data			*data;

	philosopher = (t_philosopher *)void_philosopher;
	data = philosopher->data;
	while (1)
	{
		sem_wait(data->is_eating);
		if (get_time_milliseconds() - \
		philosopher->last_eating_time > data->time_to_die)
			philosopher_died(data, philosopher);
		sem_post(data->is_eating);
		sem_wait(data->is_eating);
		if (data->philosopher_must_eat > 0 && \
			philosopher->eating_count >= data->philosopher_must_eat)
		{
			sem_post(data->is_eating);
			break ;
		}
		sem_post(data->is_eating);
	}
	return (NULL);
}

static void	process_handle(t_data *data, t_philosopher *philosopher)
{
	philosopher->last_eating_time = get_time_milliseconds();
	pthread_create(&philosopher->died_thread, NULL, died_checker, philosopher);
	if (philosopher->id % 2 == 1)
		usleep(15000);
	while (1)
	{
		if (data->philosopher_must_eat > 0 && \
			philosopher->eating_count >= data->philosopher_must_eat)
			break ;
		philosopher_eat(data, philosopher);
		philosopher_sleep(data, philosopher);
		philosopher_writer(philosopher, "is thinking");
	}
	pthread_join(philosopher->died_thread, NULL);
	if (data->died_any_philosopher == 1)
		exit(1);
	exit(0);
}

void	philosopher_many(t_data *data)
{
	int	i;

	i = 0;
	data->start_time = get_time_milliseconds();
	while (i < data->number_of_philosophers)
	{
		data->philosophers[i].process_id = fork();
		if (data->philosophers[i].process_id < 0)
		{
			printf("error : fork");
			i--;
			while (i >= 0)
			{
				kill(data->philosophers[i].process_id, SIGKILL);
				i--;
			}
			clear_data(data);
			return ;
		}
		if (data->philosophers[i].process_id == 0)
			process_handle(data, &data->philosophers[i]);
		i++;
	}
	wait_and_kill_process(data);
	clear_data(data);
}
