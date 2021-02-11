//
// Created by qli on 09/02/2021.
//

#include "philo_one.h"
#include <stdlib.h>


void* start_action(void *arg)
{
	t_philosopher *philo;
	int i;

	i = 0;
	philo = arg;
//	while (i < 3)
//	{
		pthread_mutex_lock(philo->left_fork_mutex);
		printf("[%d] grab a left fork\n", philo->philo_number);
		pthread_mutex_lock(philo->right_fork_mutex);
		printf("[%d] grab a right fork\n", philo->philo_number);

		printf("[%d] is eating\n", philo->philo_number);
		usleep(80000000);
		pthread_mutex_unlock(philo->left_fork_mutex);
		pthread_mutex_unlock(philo->right_fork_mutex);
		i++;
//	}

	return (0);
}