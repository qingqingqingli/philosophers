//
// Created by qli on 17/02/2021.
//

#include <stdio.h>
#include "../headers/check_status.h"
#include "../headers/support_functions.h"
#include "../headers/print.h"

void*	check_status(void *arg)
{
	t_philosopher	*philo;
	struct timeval	check;

	philo = arg;
	while(philo->setup->life_status && philo->setup->mutex_status)
	{
		pthread_mutex_lock(&philo->setup->status_mutex);
		gettimeofday(&check, NULL);
		if (get_elapsed_milli(&philo->last_eat_time, &check) > philo->setup->time_to_die || !philo->setup->mutex_status)
		{
			print_prompt(philo, "has died.\n");
			philo->setup->life_status = 0;
			pthread_mutex_unlock(&philo->setup->status_mutex);
			return (NULL);
		}
		pthread_mutex_unlock(&philo->setup->status_mutex);
	}
	return (NULL);
}