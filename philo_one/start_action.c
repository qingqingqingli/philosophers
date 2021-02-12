//
// Created by qli on 09/02/2021.
//

#include "philo_one.h"
#include <stdlib.h>

long int get_elapsed_time(t_philosopher *philo)
{
	long int dif;

	dif = 0;
	gettimeofday(&philo->current_time, NULL);
	dif = (philo->current_time.tv_sec - philo->begin_time.tv_sec) * 1000000 + philo->current_time.tv_usec - philo->begin_time.tv_usec;
	return dif / 1000; // convert to microseconds
}

void grab_left_fork_first(t_philosopher *philo)
{
	long int dif;

	dif = 0;
	// left
	pthread_mutex_lock(philo->left_fork_mutex);
	dif = get_elapsed_time(philo);
	printf(GREEN "[%ld] \t [%d] \t has taken a left fork"RESET"\n", dif, philo->philo_number);
	// right
	pthread_mutex_lock(philo->right_fork_mutex);
	dif = get_elapsed_time(philo);
	printf(GREEN "[%ld] \t [%d] \t has taken a right fork"RESET"\n", dif, philo->philo_number);
}

void grab_right_fork_first(t_philosopher *philo)
{
	long int dif;

	dif = 0;
	// right
	pthread_mutex_lock(philo->right_fork_mutex);
	dif = get_elapsed_time(philo);
	printf(GREEN"[%ld] \t [%d] \t has taken a right fork"RESET"\n", dif, philo->philo_number);
	// left
	pthread_mutex_lock(philo->left_fork_mutex);
	dif = get_elapsed_time(philo);
	printf(GREEN"[%ld] \t [%d] \t has taken a left fork"RESET"\n", dif, philo->philo_number);
}

void grab_forks(t_philosopher *philo)
{
	long int dif;

	dif = 0;
	if (philo->philo_number % 2 == 1)
		grab_left_fork_first(philo);
	else
		grab_right_fork_first(philo);

	dif = get_elapsed_time(philo);
	printf(MAGENTA "[%ld] \t [%d] \t is eating"RESET"\n", dif, philo->philo_number);

	usleep(philo->time_to_eat); // eat for time_to_eat
	pthread_mutex_unlock(philo->left_fork_mutex);
	pthread_mutex_unlock(philo->right_fork_mutex);
}


void philo_sleep(t_philosopher *philo)
{
	long int dif;

	dif = get_elapsed_time(philo);
	printf(BLUE "[%ld] \t [%d] \t is sleeping"RESET"\n", dif, philo->philo_number);
	usleep(philo->time_to_sleep); // sleep for time_to_sleep
	dif = get_elapsed_time(philo);
	printf(YELLOW "[%ld] \t [%d] \t is thinking"RESET"\n", dif, philo->philo_number);
}

void* start_action(void *arg)
{
	t_philosopher *philo;
	int i;

	i = 0;
	philo = arg;
	while (1)
	{
		grab_forks(philo);
		philo_sleep(philo);
	}
}