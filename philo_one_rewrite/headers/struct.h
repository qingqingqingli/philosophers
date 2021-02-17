//
// Created by qli on 17/02/2021.
//

#pragma once
#include <pthread.h> // threads
#include <sys/time.h> // gettimeofday

typedef struct 		s_setup
{
	long long int	number_of_philosophers;
	long long int 	time_to_die;
	long long int 	time_to_eat;
	long long int 	time_to_sleep;
	long long int	number_of_times_each_philosopher_must_eat;
	int 			number_to_eat_exist;
	int				life_status;
	pthread_mutex_t	*fork_mutexs;
}					t_setup;

typedef struct 		s_philosopher
{
	t_setup			*setup;
	int 			num;
	struct timeval	begin_time;
	struct timeval	last_eat_time;
	pthread_mutex_t *status_mutex;
	pthread_t 		*philo_thread;
	pthread_t 		*philo_status_thread;
}					t_philosopher;

enum values
{
	yes = 1,
	no = 0,
	alive = 1,
	dead = 0,
	error_occurred = -1
};