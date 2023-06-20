/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher_actions.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spirnaz <spirnaz@student.42kocaeli.com.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 22:51:02 by spirnaz           #+#    #+#             */
/*   Updated: 2023/06/02 22:51:03 by spirnaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

/// @brief Zaman geçirilmesi gereken yerlerde kullanılır.
/// Filozof, milisaniye (ms) cinsinden belirtilen zaman boyunca duraklatılır.
/// Uyku sırasında simülasyonun bitip bitmediğini periyodik olarak kontrol eder.
/// @param data Simülasyonun verilerini tutar.
/// @param wait_time Filozofun bekletileceği zaman (ms)
void	philosopher_wait(t_data *data, time_t wait_time)
{
	time_t	limit;

	limit = get_time_milliseconds() + wait_time;
	while (get_time_milliseconds() < limit)
	{
		sem_wait(data->death_checker);
		if (data->died_any_philosopher == 1)
		{
			sem_post(data->death_checker);
			break ;
		}
		sem_post(data->death_checker);
	}
}

void	philosopher_writer(t_philosopher *philosopher, char *message)
{
	t_data	*data;

	data = philosopher->data;
	sem_wait(data->death_checker);
	if (data->died_any_philosopher == 0)
	{
		sem_wait(data->writer);
		printf("%ld %d %s\n", get_time_milliseconds() - data->start_time, \
		philosopher->id + 1, message);
		sem_post(data->writer);
	}
	sem_post(data->death_checker);
}

void	philosopher_eat(t_data *data, t_philosopher *philosopher)
{
	sem_wait(data->forks);
	philosopher_writer(philosopher, "has taken a fork");
	sem_wait(data->forks);
	philosopher_writer(philosopher, "has taken a fork");
	sem_wait(data->is_eating);
	philosopher_writer(philosopher, "is eating");
	philosopher->last_eating_time = get_time_milliseconds();
	sem_post(data->is_eating);
	philosopher_wait(data, data->time_to_eat);
	sem_wait(data->is_eating);
	philosopher->eating_count++;
	sem_post(data->is_eating);
	sem_post(data->forks);
	sem_post(data->forks);
}

void	philosopher_sleep(t_data *data, t_philosopher *philosopher)
{
	philosopher_writer(philosopher, "is sleeping");
	philosopher_wait(data, data->time_to_sleep);
}

void	philosopher_died(t_data *data, t_philosopher *philosopher)
{
	philosopher_writer(philosopher, "died");
	sem_wait(data->writer);
	data->died_any_philosopher = 1;
	sem_post(data->is_eating);
	exit(1);
}
