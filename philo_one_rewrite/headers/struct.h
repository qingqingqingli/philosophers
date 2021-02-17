//
// Created by qli on 17/02/2021.
//

#pragma once
#include <pthread.h> // threads
#include <sys/time.h> // gettimeofday

typedef struct 		s_setup
{
	int				number_of_philosophers;
	long long int 	time_to_die;
	long long int 	time_to_eat;
	long long int 	time_to_sleep;
	int				number_of_times_each_philosopher_must_eat;
	int 			number_to_eat_exist;
	int				life_status;
	pthread_mutex_t	*fork_mutexs;
}					t_setup;

typedef struct 		s_philosopher
{
	t_setup			*setup; 		// setup
	int 			num;			// initialised
	struct timeval	begin_time;		// initialised
	struct timeval	now;
	struct timeval	last_eat_time;  // initialised
	pthread_mutex_t *left_fork_mutex; // setup
	pthread_mutex_t *right_fork_mutex; // setup
	pthread_mutex_t status_mutex;		// initialised
	pthread_t 		philo_thread;
	pthread_t 		philo_status_thread;
}					t_philosopher;

enum values
{
	yes = 1,
	no = 0,
	alive = 1,
	dead = 0,
	error = -1
};