//
// Created by qli on 17/02/2021.
//

#include <stdio.h>
#include "../headers/check_status.h"
#include "../headers/support_functions.h"

void*	check_status(void *arg)
{
	t_philosopher	*philo;
	struct timeval	check;

	philo = arg;
	while(philo->setup->life_status)
	{
		pthread_mutex_lock(&philo->status_mutex);
		gettimeofday(&check, NULL);
		if (get_elapsed_milli(&philo->last_eat_time, &check) > philo->setup->time_to_die)
		{
			philo->setup->life_status = 0;
			printf(BLACK"[%d] \t [%d] \t has died\n"RESET"", get_elapsed_milli(&philo->begin_time, &check), philo->num);
			pthread_mutex_unlock(&philo->status_mutex);
			return (NULL);
		}
		pthread_mutex_unlock(&philo->status_mutex);
	}
	return (NULL);
}