/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher_actions.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeaugra <abeaugra@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 11:45:03 by abeaugra          #+#    #+#             */
/*   Updated: 2023/08/24 14:40:54 by abeaugra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/// @brief Zaman geçirilmesi gereken yerlerde kullanılır.
/// Filozof, milisaniye (ms) cinsinden belirtilen zaman boyunca duraklatılır.
/// Uyku sırasında simülasyonun bitip bitmediğini periyodik olarak kontrol eder.
/// @param data Simülasyonun verilerini tutar.
/// @param wait_time Filozofun bekletileceği zaman (ms)
void	philo_wait(t_data *data, time_t wait_time)
{
	time_t	limit;

	limit = get_time_ms() + wait_time;
	while (get_time_ms() < limit)
	{
		pthread_mutex_lock(&data->death_checker);
		if (data->died_philo == 1)
		{
			pthread_mutex_unlock(&data->death_checker);
			break ;
		}
		pthread_mutex_unlock(&data->death_checker);
	}
}

void	philo_writer(t_philo *philosopher, char *message)
{
	t_data	*data;

	data = philosopher->data;
	pthread_mutex_lock(&data->death_checker);
	if (data->died_philo == 0)
	{
		pthread_mutex_lock(&data->writer);
		printf("%ld %d %s\n", get_time_ms() - data->start_time, \
		philosopher->id + 1, message);
		pthread_mutex_unlock(&data->writer);
	}
	pthread_mutex_unlock(&data->death_checker);
}

void	philo_eat(t_data *data, t_philo *philosopher)
{
	pthread_mutex_lock(&data->forks[philosopher->lfork_id]);
	philo_writer(philosopher, "has taken a fork");
	pthread_mutex_lock(&data->forks[philosopher->rfork_id]);
	philo_writer(philosopher, "has taken a fork");
	pthread_mutex_lock(&data->is_eating);
	philo_writer(philosopher, "is eating");
	philosopher->last_eating_time = get_time_ms();
	pthread_mutex_unlock(&data->is_eating);
	philo_wait(data, data->time_to_eat);
	pthread_mutex_lock(&data->is_eating);
	philosopher->eating_count++;
	pthread_mutex_unlock(&data->is_eating);
	pthread_mutex_unlock(&data->forks[philosopher->lfork_id]);
	pthread_mutex_unlock(&data->forks[philosopher->rfork_id]);
}

void	philo_sleep(t_data *data, t_philo *philosopher)
{
	philo_writer(philosopher, "is sleeping");
	philo_wait(data, data->time_to_sleep);
}

void	philo_think(t_philo *philosopher)
{
	philo_writer(philosopher, "is thinking");
}
