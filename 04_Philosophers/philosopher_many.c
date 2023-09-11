/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_many.c                                 		:+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeaugra <abeaugra@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 11:50:45 by abeaugra          #+#    #+#             */
/*   Updated: 2023/08/24 14:37:14 by abeaugra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	join_and_clear(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->num_philo)
	{
		pthread_join(data->philo[i].thd_id, NULL);
		i++;
	}
	clear_data(data);
}

static int	all_ate(t_data *data)
{
	int	i;

	i = 0;
	if (data->philo_must_eat <= 0)
		return (0);
	pthread_mutex_lock(&data->is_eating);
	while (i < data->num_philo)
	{
		if (data->philo[i].eating_count < data->philo_must_eat)
		{
			pthread_mutex_unlock(&data->is_eating);
			return (0);
		}
		i++;
	}
	pthread_mutex_unlock(&data->is_eating);
	return (1);
}

static void	catch_death_or_eat(t_data *data)
{
	int	i;

	i = 0;
	while (1)
	{
		if (all_ate(data) == 1)
			break ;
		pthread_mutex_lock(&data->is_eating);
		if (data->philo[i].last_eating_time > 0 && \
		get_time_ms() - data->philo[i].last_eating_time \
		> data->time_to_die)
		{
			philo_writer(&data->philo[i], "died 💀 Amen :🙏" );
			pthread_mutex_lock(&data->death_checker);
			data->died_philo = 1;
			pthread_mutex_unlock(&data->death_checker);
			pthread_mutex_unlock(&data->is_eating);
			break ;
		}
		pthread_mutex_unlock(&data->is_eating);
		i++;
		if (i == data->num_philo)
			i = 0;
	}
}

static void	*philo_many_func(void *void_philosopher)
{
	t_philo	*philosopher;
	t_data	*data;

	philosopher = (t_philo *)void_philosopher;
	data = philosopher->data;
	if (philosopher->id % 2 == 1)
		usleep(15000);
	while (1)
	{
		pthread_mutex_lock(&data->death_checker);
		if (data->died_philo == 1)
		{
			pthread_mutex_unlock(&data->death_checker);
			break ;
		}
		else
			pthread_mutex_unlock(&data->death_checker);
		if (data->philo_must_eat > 0
			&& philosopher->eating_count >= data->philo_must_eat)
			break ;
		philo_eat(data, philosopher);
		philo_sleep(data, philosopher);
		philo_think(philosopher);
	}
	return (NULL);
}

void	philo_many(t_data *data)
{
	int	i;

	i = 0;
	data->start_time = get_time_ms();
	while (i < data->num_philo)
	{
		if (pthread_create(&data->philo[i].thd_id, NULL, \
		philo_many_func, &data->philo[i]) != 0)
		{
			print_err("error : pthread_create");
			clear_data(data);
			return ;
		}
		i++;
	}
	catch_death_or_eat(data);
	join_and_clear(data);
}
