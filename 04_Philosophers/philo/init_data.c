/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeaugra <abeaugra@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 10:49:38 by abeaugra          #+#    #+#             */
/*   Updated: 2023/08/24 14:40:11 by abeaugra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	check_args(char **argv)
{
	int	i;
	int	philo;
	int	philo_must_eat;
	int	arg;

	philo = ft_atoi(argv[1]);
	if (philo < 1 || philo > __INT_MAX__)
		return (0);
	if (argv[5] != NULL)
	{
		philo_must_eat = ft_atoi(argv[5]);
		if (philo_must_eat <= 0 || philo_must_eat > __INT_MAX__)
			return (0);
	}
	i = 2;
	while (i < 5)
	{
		arg = ft_atoi(argv[i]);
		if (arg <= 0 || arg > __INT_MAX__)
			return (0);
		i++;
	}
	return (1);
}

static int	init_mutexes(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->num_philo)
	{
		if (pthread_mutex_init(&data->forks[i], NULL) != 0)
			return (print_err("error : data->forks mutex_init"));
		i++;
	}
	if (pthread_mutex_init(&data->writer, NULL) != 0)
		return (print_err("error : data->writer mutex_init"));
	if (pthread_mutex_init(&data->is_eating, NULL) != 0)
		return (print_err("error : data->is_eating mutex_init"));
	if (pthread_mutex_init(&data->death_checker, NULL) != 0)
		return (print_err("error : data->death_checker mutex_init"));
	return (1);
}

static void	init_philos(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->num_philo)
	{
		data->philo[i].id = i;
		data->philo[i].eating_count = 0;
		data->philo[i].last_eating_time = 0;
		data->philo[i].lfork_id = i;
		data->philo[i].rfork_id \
		= (i + 1) % data->num_philo;
		data->philo[i].data = data;
		i++;
	}
}

int	init_data(t_data *data, char **argv)
{
	if (check_args(argv) == 0)
		return (print_err("error : invalid argument"));
	data->died_philo = 0;
	data->num_philo = ft_atoi(argv[1]);
	data->time_to_die = ft_atoi(argv[2]);
	data->time_to_eat = ft_atoi(argv[3]);
	data->time_to_sleep = ft_atoi(argv[4]);
	data->philo_must_eat = -42;
	if (argv[5] != NULL)
		data->philo_must_eat = ft_atoi(argv[5]);
	data->philo = \
	malloc(sizeof(t_philo) * data->num_philo);
	if (data->philo == NULL)
		return (print_err("error : data->philo malloc"));
	data->forks = \
	malloc(sizeof(pthread_mutex_t) * data->num_philo);
	if (data->forks == NULL)
		return (print_err("error : data->forks malloc"));
	if (init_mutexes(data) == 0)
		return (0);
	init_philos(data);
	return (1);
}
