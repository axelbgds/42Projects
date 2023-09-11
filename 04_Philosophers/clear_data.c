/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear_data.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeaugra <abeaugra@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 10:49:22 by abeaugra          #+#    #+#             */
/*   Updated: 2023/08/24 14:58:56 by abeaugra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	destroy_mutexes(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->num_philo)
	{
		pthread_mutex_destroy(&data->forks[i]);
		i++;
	}
	pthread_mutex_destroy(&data->writer);
	pthread_mutex_destroy(&data->is_eating);
	pthread_mutex_destroy(&data->death_checker);
}

static void	free_data(t_data *data)
{
	if (data->forks != NULL)
		free(data->forks);
	if (data->philo != NULL)
		free(data->philo);
}

void	clear_data(t_data *data)
{
	destroy_mutexes(data);
	free_data(data);
}
