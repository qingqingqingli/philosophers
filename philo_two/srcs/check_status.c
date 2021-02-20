//
// Created by qli on 17/02/2021.
//

#include <stdio.h>
#include "../headers/check_status.h"
#include "../headers/time_calculation.h"
#include "../headers/print.h"

void	*check_status(void *arg)
{
	t_philosopher	*philo;
	struct timeval	check;

	philo = arg;
	while (philo->setup->life_status)
	{
		sem_wait(philo->setup->status_sema);
		gettimeofday(&check, NULL);
		if (get_elapsed_milli(&philo->last_eat_time, &check) > \
		philo->setup->time_to_die)
		{
			print_prompt(philo, "has died.\n");
			philo->setup->life_status = dead;
			sem_post(philo->setup->status_sema);
			return (NULL);
		}
		sem_post(philo->setup->status_sema);
	}
	return (NULL);
}
