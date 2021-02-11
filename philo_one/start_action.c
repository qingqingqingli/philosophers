//
// Created by qli on 09/02/2021.
//

#include "philo_one.h"
#include <stdlib.h>

void grab_forks(t_philosopher *philo)
{
	pthread_mutex_lock(philo->left_fork_mutex);
	printf("[%d] grab a left fork\n", philo->philo_number);
	pthread_mutex_lock(philo->right_fork_mutex);
	printf("[%d] grab a right fork\n", philo->philo_number);
	printf("[%d] is eating\n", philo->philo_number);
	usleep(90000);
	pthread_mutex_unlock(philo->left_fork_mutex);
	pthread_mutex_unlock(philo->right_fork_mutex);
}

void philo_sleep(t_philosopher *philo)
{
	printf("[%d] is sleeping\n", philo->philo_number);
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