/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeaugra <abeaugra@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 10:14:28 by abeaugra          #+#    #+#             */
/*   Updated: 2023/08/24 14:59:04 by abeaugra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <pthread.h>
# include <sys/time.h>

typedef struct s_philo
{
	pthread_t		thd_id;
	int				id;
	int				lfork_id;
	int				rfork_id;
	int				eating_count;
	time_t			last_eating_time;
	struct s_data	*data;
}					t_philo;

typedef struct s_data
{
	int				num_philo;
	time_t			time_to_die;
	time_t			time_to_eat;
	time_t			time_to_sleep;
	int				philo_must_eat;
	time_t			start_time;
	int				died_philo;
	pthread_mutex_t	*forks;
	pthread_mutex_t	writer;
	pthread_mutex_t	is_eating;
	pthread_mutex_t	death_checker;
	t_philo			*philo;
}					t_data;

int		ft_atoi(char *str);
int		print_err(char *message);
time_t	get_time_ms(void);
int		init_data(t_data *data, char **argv);
void	clear_data(t_data *data);
void	philo_wait(t_data *data, time_t wait_time);
void	philo_writer(t_philo *philosopher, char *message);
void	philo_eat(t_data *data, t_philo *philosopher);
void	philo_sleep(t_data *data, t_philo *philosopher);
void	philo_think(t_philo *philosopher);
void	philo_one(t_data *data);
void	philo_many(t_data *data);

#endif
