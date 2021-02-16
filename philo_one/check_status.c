//
// Created by qli on 12/02/2021.
//
#include <stdlib.h>
#include "philo_one.h"

void* check_status(void *arg)
{
	t_philosopher 	*philo;
	struct timeval	time_now;

	philo = arg;
	while (life_status)
	{
		pthread_mutex_lock(philo->status_mutex);
		gettimeofday(&time_now, NULL);
		if (get_elapsed_ms(&philo->last_eat_time, &time_now) / 1000 >= philo->time_to_die)
		{
			life_status = 0;
			printf("[%ld] \t [%d] \t has died\n", get_elapsed_ms(&philo->begin_time, &time_now) / 1000, philo->num);
			pthread_mutex_unlock(philo->status_mutex);
			return (NULL);
		}
		pthread_mutex_unlock(philo->status_mutex);
	}
	return (NULL);
}