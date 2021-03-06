//
// Created by qli on 17/02/2021.
//

#include <stdio.h>
#include <stdlib.h>
#include "../headers/check_status.h"
#include "../headers/time_calculation.h"
#include "../headers/print.h"

void 	*handle_philo_death(t_philosopher *philo)
{
	gettimeofday(&philo->now, NULL);
	philo->setup->life_status = dead;
	if (sem_wait(philo->setup->death_block_sema))
	{
		philo->setup->sema_status = dead;
		philo->setup->life_status = dead;
		return (NULL);
	}
	printf(BLACK"[%ld]\t[%d] \thas died.\n", \
	get_elapsed_milli(&philo->begin_time, &philo->now), philo->num);
	sem_post(philo->setup->check_death_sema);
	if (philo->release_fork)
		sem_post(philo->setup->fork_sema);
	sem_post(philo->setup->check_status_sema);
	return (NULL);
}

void	*check_status(void *arg)
{
	t_philosopher	*philo;
	struct timeval	check;

	philo = arg;
	while (philo->setup->life_status)
	{
		if (sem_wait(philo->setup->check_status_sema))
		{
			philo->setup->sema_status = dead;
			philo->setup->life_status = dead;
			return (NULL);
		}
		gettimeofday(&check, NULL);
		if (get_elapsed_milli(&philo->last_eat_time, &check) > \
		philo->setup->time_to_die)
			return (handle_philo_death(philo));
		sem_post(philo->setup->check_status_sema);
	}
	return (NULL);
}
