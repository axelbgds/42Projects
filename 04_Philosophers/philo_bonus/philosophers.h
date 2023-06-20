/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spirnaz <spirnaz@student.42kocaeli.com.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 22:51:17 by spirnaz           #+#    #+#             */
/*   Updated: 2023/06/02 22:51:18 by spirnaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <semaphore.h>
# include <fcntl.h>
# include <sys/stat.h>
# include <signal.h>

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <pthread.h>
# include <sys/time.h>
# include <sys/wait.h>

typedef struct s_philosopher
{
	pid_t			process_id;
	int				id;
	int				eating_count;
	time_t			last_eating_time;
	pthread_t		died_thread;
	struct s_data	*data;
}					t_philosopher;

typedef struct s_data
{
	int				number_of_philosophers;
	time_t			time_to_die;
	time_t			time_to_eat;
	time_t			time_to_sleep;
	int				philosopher_must_eat;
	int				died_any_philosopher;
	time_t			start_time;
	sem_t			*forks;
	sem_t			*writer;
	sem_t			*is_eating;
	sem_t			*death_checker;
	t_philosopher	*philosophers;
}					t_data;

int		ft_atoi(char *str);
int		print_error(char *message);
time_t	get_time_milliseconds(void);
int		init_data(t_data *data, char **argv);
void	clear_data(t_data *data);
void	philosopher_wait(t_data *data, time_t wait_time);
void	philosopher_writer(t_philosopher *philosopher, char *message);
void	philosopher_eat(t_data *data, t_philosopher *philosopher);
void	philosopher_sleep(t_data *data, t_philosopher *philosopher);
void	philosopher_died(t_data *data, t_philosopher *philosopher);
void	philosopher_one(t_data *data);
void	philosopher_many(t_data *data);

#endif
