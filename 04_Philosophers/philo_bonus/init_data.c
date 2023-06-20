/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spirnaz <spirnaz@student.42kocaeli.com.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 22:50:46 by spirnaz           #+#    #+#             */
/*   Updated: 2023/06/02 22:50:47 by spirnaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

static int	handle_must_eat(t_data *data, int argument)
{
	int	factor;

	factor = 0;
	if (argument > 1)
		return (argument);
	if (data->number_of_philosophers % 2 == 0)
		factor = 2;
	else
		factor = 3;
	if (factor * data->time_to_eat > data->time_to_die)
		return (0);
	return (argument);
}

static int	check_args(char **argv)
{
	int	i;
	int	philosophers;
	int	philosopher_must_eat;
	int	arg;

	philosophers = ft_atoi(argv[1]);
	if (philosophers < 1 || philosophers > __INT_MAX__)
		return (0);
	if (argv[5] != NULL)
	{
		philosopher_must_eat = ft_atoi(argv[5]);
		if (philosopher_must_eat <= 0 || philosopher_must_eat > __INT_MAX__)
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

static int	init_semaphores(t_data *data)
{
	sem_unlink("forks");
	sem_unlink("writer");
	sem_unlink("is_eating");
	sem_unlink("death_checker");
	data->forks = sem_open("forks", O_CREAT, S_IRWXU, \
	data->number_of_philosophers);
	data->writer = sem_open("writer", O_CREAT, S_IRWXU, 1);
	data->is_eating = sem_open("is_eating", O_CREAT, S_IRWXU, 1);
	data->death_checker = sem_open("death_checker", \
	O_CREAT, S_IRWXU, 1);
	if (data->forks == SEM_FAILED || data->writer == SEM_FAILED \
	|| data->is_eating == SEM_FAILED || data->death_checker == SEM_FAILED)
		return (print_error("error : sem_open"));
	return (1);
}

static void	init_philosophers(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->number_of_philosophers)
	{
		data->philosophers[i].id = i;
		data->philosophers[i].eating_count = 0;
		data->philosophers[i].last_eating_time = 0;
		data->philosophers[i].data = data;
		i++;
	}
}

int	init_data(t_data *data, char **argv)
{
	if (check_args(argv) == 0)
		return (print_error("error : invalid argument"));
	data->died_any_philosopher = 0;
	data->number_of_philosophers = ft_atoi(argv[1]);
	data->time_to_die = ft_atoi(argv[2]);
	data->time_to_eat = ft_atoi(argv[3]);
	data->time_to_sleep = ft_atoi(argv[4]);
	data->philosopher_must_eat = -42;
	if (argv[5] != NULL)
		data->philosopher_must_eat = handle_must_eat(data, ft_atoi(argv[5]));
	data->philosophers = malloc(sizeof(t_philosopher) \
	* data->number_of_philosophers);
	if (data->philosophers == NULL)
		return (print_error("error : data->philosophers malloc"));
	if (init_semaphores(data) == 0)
		return (0);
	init_philosophers(data);
	return (1);
}
