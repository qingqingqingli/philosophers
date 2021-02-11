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


void grab_forks(t_philosopher *philo)
{
	long int dif;

	dif = 0;
	pthread_mutex_lock(philo->left_fork_mutex);
	dif = get_elapsed_time(philo);
	printf(GREEN "[%ld] \t [%d] \t grab a left fork\n", dif, philo->philo_number);

	pthread_mutex_lock(philo->right_fork_mutex);
	dif = get_elapsed_time(philo);
	printf(GREEN "[%ld] \t [%d] \t grab a right fork\n", dif, philo->philo_number);

	dif = get_elapsed_time(philo);
	printf(MAGENTA "[%ld] \t [%d] \t is eating\n", dif, philo->philo_number);

	usleep(9000);
	pthread_mutex_unlock(philo->left_fork_mutex);
	pthread_mutex_unlock(philo->right_fork_mutex);
}


void philo_sleep(t_philosopher *philo)
{
	long int dif;

	dif = get_elapsed_time(philo);
	printf(BLUE "[%ld] \t [%d] \t is sleeping\n", dif, philo->philo_number);
	printf(RESET);
	usleep(90000);
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