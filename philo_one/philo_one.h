//
// Created by qli on 08/02/2021.
//

#pragma once
#include <stdio.h> // printf
#include <unistd.h> // usleep
#include <sys/time.h> // gettimeofday
#include "libft/libft.h"
#include <pthread.h> // threads

#define RESET			"\033[0m"
#define BLACK			"\033[30m"
#define RED				"\033[31m"
#define GREEN			"\033[32m"
#define YELLOW			"\033[33m"
#define BLUE			"\033[34m"
#define MAGENTA			"\033[35m"
#define CYAN			"\033[36m"
#define WHITE			"\033[37m"
#define BOLDBLACK		"\033[1m\033[30m"
#define BOLDRED			"\033[1m\033[31m"
#define BOLDGREEN		"\033[1m\033[32m"
#define BOLDYELLOW		"\033[1m\033[33m"
#define BOLDBLUE		"\033[1m\033[34m"
#define BOLDMAGENTA		"\033[1m\033[35m"
#define BOLDCYAN		"\033[1m\033[36m"
#define BOLDWHITE		"\033[1m\033[37m"

// ** DATA STRUCT ** //

typedef struct 		s_philosopher
{
	int 			philo_number; //init in init_program_setup
	struct timeval	begin_time;
	struct timeval	current_time;
	struct timeval	last_eat_time;
	struct timeval	check_status_time;
	pthread_mutex_t *left_fork_mutex;
	pthread_mutex_t *right_fork_mutex;
	long long int 	time_to_die; //init in init_program_setup
	long long int 	time_to_eat; //init in init_program_setup
	long long int 	time_to_sleep; //init in init_program_setup
}					t_philosopher;

typedef struct 		s_setup_data
{
	long long int	number_of_philosophers; //init in init_program_setup
	long long int 	time_to_die; //init in init_program_setup
	long long int 	time_to_eat; //init in init_program_setup
	long long int 	time_to_sleep; //init in init_program_setup
	long long int	number_of_times_each_philosopher_must_eat; //init in init_program_setup
	pthread_mutex_t	*fork_mutexs; //init in init_program_setup
	pthread_t		*philo_threads; //init in init_program_setup
	pthread_t 		*philo_status_threads; //init in init_program_setup
	t_philosopher	*philos; //init in init_program_setup
}					t_setup_data;

// ** support.c ** //
void 	print_philo_data(t_setup_data data);
long int get_elapsed_milliseconds(struct timeval *previous, struct timeval *now);

// ** init_program_setup.c ** //
int 	init_program_setup(int argc, char **argv, t_setup_data *setup);

// ** create_philosophers.c ** //
void* 	start_action(void *arg);

// ** check_status.c ** //
void* check_status(void *arg);