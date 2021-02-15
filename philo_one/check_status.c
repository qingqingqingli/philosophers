//
// Created by qli on 12/02/2021.
//
#include <stdlib.h>
#include "philo_one.h"

void* check_status(void *arg)
{
	t_philosopher 	*philo;
	long int		dif;

	philo = arg;
	dif = 0;
	if (philo->last_eat_time.tv_usec)
	{
		while (life_status)
		{
			gettimeofday(&philo->check_status_time, NULL);
			dif = get_elapsed_ms(&philo->last_eat_time, &philo->check_status_time) / 1000;
			if (dif >= philo->time_to_die)
			{
				printf("[%ld] \t [%d] \t has died\n",
					   get_elapsed_ms(&philo->current_time, &philo->check_status_time) / 1000, philo->num);
				life_status = 0;
				break ;
			}
		}
	}
	return (NULL);
}