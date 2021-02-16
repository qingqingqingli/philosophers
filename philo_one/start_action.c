//
// Created by qli on 09/02/2021.
//

#include "philo_one.h"
#include <stdlib.h>

void grab_left_fork_first(t_philosopher *philo)
{
	pthread_mutex_lock(philo->left_fork_mutex);
	gettimeofday(&philo->current_time, NULL);
	if (life_status)
		printf(GREEN "[%ld] \t [%d] \t has taken a left fork"RESET"\n", get_elapsed_ms(&philo->begin_time, &philo->current_time) / 1000, philo->num);
	else
	{
		pthread_mutex_unlock(philo->left_fork_mutex);
		return;
	}
	pthread_mutex_lock(philo->right_fork_mutex);
	gettimeofday(&philo->current_time, NULL);
	if (life_status)
		printf(GREEN "[%ld] \t [%d] \t has taken a right fork"RESET"\n",
		   get_elapsed_ms(&philo->begin_time, &philo->current_time) / 1000, philo->num);
	else
	{
		pthread_mutex_unlock(philo->left_fork_mutex);
		pthread_mutex_unlock(philo->right_fork_mutex);
		return;
	}
}

void grab_right_fork_first(t_philosopher *philo)
{
	pthread_mutex_lock(philo->right_fork_mutex);
	gettimeofday(&philo->current_time, NULL);
	if (life_status)
		printf(GREEN "[%ld] \t [%d] \t has taken a right fork"RESET"\n", get_elapsed_ms(&philo->begin_time, &philo->current_time) / 1000, philo->num);
	else
	{
		pthread_mutex_unlock(philo->right_fork_mutex);
		return;
	}
	pthread_mutex_lock(philo->left_fork_mutex);
	gettimeofday(&philo->current_time, NULL);
	if (life_status)
		printf(GREEN "[%ld] \t [%d] \t has taken a left fork"RESET"\n", get_elapsed_ms(&philo->begin_time, &philo->current_time) / 1000, philo->num);
	else
	{
		pthread_mutex_unlock(philo->left_fork_mutex);
		pthread_mutex_unlock(philo->right_fork_mutex);
		return;
	}
}

void grab_forks(t_philosopher *philo)
{

	if (philo->num % 2 == 1)
		grab_left_fork_first(philo);
	else
		grab_right_fork_first(philo);

	gettimeofday(&philo->current_time, NULL);
	if (life_status)
		printf(MAGENTA "[%ld] \t [%d] \t is eating"RESET"\n", get_elapsed_ms(&philo->begin_time, &philo->current_time) / 1000, philo->num);
	else
	{
		pthread_mutex_unlock(philo->left_fork_mutex);
		pthread_mutex_unlock(philo->right_fork_mutex);
	}
	pthread_mutex_lock(philo->status_mutex);
	gettimeofday(&philo->last_eat_time, NULL);
	pthread_mutex_unlock(philo->status_mutex);
	usleep(philo->time_to_eat * 1000);
	pthread_mutex_unlock(philo->left_fork_mutex);
	pthread_mutex_unlock(philo->right_fork_mutex);

}

void philo_sleep(t_philosopher *philo)
{
	if (!life_status)
		return;
	gettimeofday(&philo->current_time, NULL);
	if (life_status)
		printf(BLUE "[%ld] \t [%d] \t is sleeping"RESET"\n",
		   get_elapsed_ms(&philo->begin_time, &philo->current_time) / 1000, philo->num);
	else
		return;
	usleep(philo->time_to_sleep * 1000);

	gettimeofday(&philo->current_time, NULL);
	if (life_status)
		printf(YELLOW "[%ld] \t [%d] \t is thinking"RESET"\n",
		   get_elapsed_ms(&philo->begin_time, &philo->current_time) / 1000, philo->num);
	else
		return;
}

void* start_action(void *arg)
{
	t_philosopher *philo;

	philo = arg;
	while (life_status)
	{
		if (!life_status)
			return NULL;
		grab_forks(philo);
		philo_sleep(philo);
	}
	return NULL;
}