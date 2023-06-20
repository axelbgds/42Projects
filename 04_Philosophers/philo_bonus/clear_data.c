/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear_data.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spirnaz <spirnaz@student.42kocaeli.com.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 22:50:38 by spirnaz           #+#    #+#             */
/*   Updated: 2023/06/02 22:50:39 by spirnaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

static void	destroy_semaphores(t_data *data)
{
	sem_close(data->forks);
	sem_close(data->writer);
	sem_close(data->is_eating);
	sem_close(data->death_checker);
	sem_unlink("forks");
	sem_unlink("writer");
	sem_unlink("is_eating");
	sem_unlink("death_checker");
}

static void	free_data(t_data *data)
{
	if (data->philosophers != NULL)
		free(data->philosophers);
}

void	clear_data(t_data *data)
{
	destroy_semaphores(data);
	free_data(data);
}
