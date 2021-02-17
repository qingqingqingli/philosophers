//
// Created by qli on 08/02/2021.
//

#pragma once
#include <stdio.h> // printf
#include <unistd.h> // usleep
#include <sys/time.h> // gettimeofday
#include "libft/libft.h"
#include <pthread.h> // threads

// ** COLOR ** //

#define RESET			"\033[0m"
#define BLACK			"\033[30m"
#define RED				"\033[31m"
#define GREEN			"\033[32m"
#define YELLOW			"\033[33m"
#define BLUE			"\033[34m"
#define MAGENTA			"\033[35m"
#define CYAN			"\033[36m"


typedef struct 		s_common
{
	long long int	number_of_philosophers; // init
	long long int 	time_to_die; // init
	long long int 	time_to_eat; // init
	long long int 	time_to_sleep; // init
	long long int	number_of_times_each_philosopher_must_eat; // init
	int				life_status; // init
	pthread_mutex_t	*fork_mutexs;
}					t_common;

typedef struct 		s_philo
{
	int 			num; // init
	struct timeval	begin_time;// init
	struct timeval	current_time;
	struct timeval	last_eat_time; // init
	// mutextes
	pthread_mutex_t *left_fork_mutex;
	pthread_mutex_t *right_fork_mutex;
	pthread_mutex_t *status_mutex;
	//threads
	pthread_t		*action_thread;
	pthread_t 		*status_thread;
	// pointer to common
	t_common 		*common;
}					t_philo;

// ** support.c ** //
void print_philo_data(t_common data);
long int 	get_elapsed_ms(struct timeval *previous, struct timeval *now);

// ** create_philosophers.c ** //
void* 		start_action(void *arg);

// ** check_status.c ** //
void* 		check_status(void *arg);

// ** init_program_setup.c ** //
void process_argv_input(int argc, char **argv, t_common *common);
int validate_setup_data(t_common common);
void init_each_philo(t_philo *philo, t_common *common);
void	init_fork_mutexes(t_common *common);
void set_philo_fork_mutexs(t_philo *philo, t_common *common);
void init_philo_threads(t_philo *philo, t_common common);
