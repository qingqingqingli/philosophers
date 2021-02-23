//
// Created by qli on 17/02/2021.
//

#include <stdio.h>
#include <stdlib.h>
#include "../headers/check_status.h"
#include "../headers/time_calculation.h"
#include "../headers/print.h"

//int	check_status(t_philosopher	*philo)
//{
//	struct timeval	check;
//
//	if (sem_wait(philo->setup->check_status_sema))
//		exit (0);
//	gettimeofday(&check, NULL);
//	if (get_elapsed_milli(&philo->last_eat_time, &check) > philo->setup->time_to_die)
//	{
//		print_prompt(philo, "has died.\n");
//		sem_post(philo->setup->check_status_sema);
//		exit (0);
//	}
//	sem_post(philo->setup->check_status_sema);
//	return (1);
//}

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
		{
			print_prompt(philo, "has died.\n");
			philo->setup->life_status = dead;
			sem_post(philo->setup->check_status_sema);
			return (NULL);
		}
		sem_post(philo->setup->check_status_sema);
	}
	return (NULL);
}
