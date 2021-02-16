//
// Created by qli on 08/02/2021.
//

#pragma once
#include <stdio.h> // printf
#include <unistd.h> // usleep
#include <sys/time.h> // gettimeofday
#include "libft/libft.h"
#include <pthread.h> // threads

int life_status;
pthread_mutex_t check_status_mutex;

// ** COLOR ** //

#define RESET			"\033[0m"
#define BLACK			"\033[30m"
#define RED				"\033[31m"
#define GREEN			"\033[32m"
#define YELLOW			"\033[33m"
#define BLUE			"\033[34m"
#define MAGENTA			"\033[35m"
#define CYAN			"\033[36m"

// ** DATA STRUCT ** //

typedef struct 		s_philosopher
{
	int 			num;
	struct timeval	begin_time;
	struct timeval	current_time;
	struct timeval	last_eat_time;
	struct timeval	time_now;
	pthread_mutex_t *left_fork_mutex;
	pthread_mutex_t *right_fork_mutex;
	long long int 	time_to_die;
	long long int 	time_to_eat;
	long long int 	time_to_sleep;
//	int 			life_status;
}					t_philosopher;

typedef struct 		s_setup_data
{
	long long int	number_of_philosophers;
	long long int 	time_to_die;
	long long int 	time_to_eat;
	long long int 	time_to_sleep;
	long long int	number_of_times_each_philosopher_must_eat;
	pthread_mutex_t	*fork_mutexs;
	pthread_t		*philo_threads;
	pthread_t 		*philo_status_threads;
	t_philosopher	*philos;
}					t_setup_data;

// ** support.c ** //
void 		print_philo_data(t_setup_data data);
long int 	get_elapsed_ms(struct timeval *previous, struct timeval *now);

// ** create_philosophers.c ** //
void* 		start_action(void *arg);

// ** check_status.c ** //
void* 		check_status(void *arg);

// ** init_program_setup.c ** //
void 		process_argv_input(int argc, char **argv, t_setup_data *setup);
int 		validate_setup_data(t_setup_data setup);
void 		init_each_philo(t_setup_data *setup);
void		init_fork_mutexes(t_setup_data *setup);
void 		set_philo_fork_mutexs(t_setup_data *setup);
void 		init_philo_threads(t_setup_data *setup);
