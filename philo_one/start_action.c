//
// Created by qli on 09/02/2021.
//

#include "philo_one.h"
#include <stdlib.h>

void grab_left_fork_first(t_philosopher *philo)
{

	// left first
	pthread_mutex_lock(philo->left_fork_mutex);
	gettimeofday(&philo->current_time, NULL);
	printf(GREEN "[%ld] \t [%d] \t has taken a left fork"RESET"\n",
		   get_elapsed_microseconds(&philo->begin_time, &philo->current_time) / 1000, philo->philo_number);
	// right second
	pthread_mutex_lock(philo->right_fork_mutex);
	gettimeofday(&philo->current_time, NULL);
	printf(GREEN "[%ld] \t [%d] \t has taken a right fork"RESET"\n",
		   get_elapsed_microseconds(&philo->begin_time, &philo->current_time) / 1000, philo->philo_number);
}

void grab_right_fork_first(t_philosopher *philo)
{
	// right first
	pthread_mutex_lock(philo->right_fork_mutex);
	gettimeofday(&philo->current_time, NULL);
	printf(GREEN"[%ld] \t [%d] \t has taken a right fork"RESET"\n",
		   get_elapsed_microseconds(&philo->begin_time, &philo->current_time) / 1000, philo->philo_number);
	// left second
	pthread_mutex_lock(philo->left_fork_mutex);
	gettimeofday(&philo->current_time, NULL);
	printf(GREEN"[%ld] \t [%d] \t has taken a left fork"RESET"\n",
		   get_elapsed_microseconds(&philo->begin_time, &philo->current_time) / 1000, philo->philo_number);
}

void grab_forks(t_philosopher *philo)
{
	if (philo->philo_number % 2 == 1)
		grab_left_fork_first(philo);
	else
		grab_right_fork_first(philo);

	gettimeofday(&philo->current_time, NULL);
	printf(MAGENTA "[%ld] \t [%d] \t is eating"RESET"\n",
		   get_elapsed_microseconds(&philo->begin_time, &philo->current_time) / 1000, philo->philo_number);
	gettimeofday(&philo->last_eat_time, NULL); // mark the time when philo starts last meal

	usleep(philo->time_to_eat * 1000); // eat for time_to_eat
	pthread_mutex_unlock(philo->left_fork_mutex);
	pthread_mutex_unlock(philo->right_fork_mutex);
}

void philo_sleep(t_philosopher *philo)
{
	gettimeofday(&philo->current_time, NULL);
	printf(BLUE "[%ld] \t [%d] \t is sleeping"RESET"\n",
		   get_elapsed_microseconds(&philo->begin_time, &philo->current_time) / 1000, philo->philo_number);

	usleep(philo->time_to_sleep * 1000); // sleep for time_to_sleep

	gettimeofday(&philo->current_time, NULL);
	printf(YELLOW "[%ld] \t [%d] \t is thinking"RESET"\n",
	get_elapsed_microseconds(&philo->begin_time, &philo->current_time) / 1000, philo->philo_number);
}

void* start_action(void *arg)
{
	t_philosopher *philo;
	int i;

	i = 0;
	philo = arg;
	while (1)
	{
		printf("[%d] life status [%d]\n", philo->philo_number, philo->life_status);
		if (philo->life_status == 0)
			return ((void *)-1);
		grab_forks(philo);
		philo_sleep(philo);
	}
	return NULL;
}