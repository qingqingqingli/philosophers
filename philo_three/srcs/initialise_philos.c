//
// Created by qli on 17/02/2021.
//

#include <stdio.h>
#include "../headers/initialise_philos.h"
#include "../headers/start_action.h"
#include "../headers/check_status.h"
#include "../headers/clean_up.h"

int 	setup_each_philo(t_setup *setup, t_philosopher *philos)
{
	int	i;

	i = 0;
	while (i < setup->number_of_philosophers)
	{
		philos[i].setup = setup;
		philos[i].release_fork = 0;
		philos[i].num = i + 1;
		philos[i].time_of_eaten = 0;
		gettimeofday(&philos[i].begin_time, NULL);
		gettimeofday(&philos[i].last_eat_time, NULL);
		i++;
	}
	return (0);
}

int 	init_write_and_status_sema(t_philosopher *philo)
{
	philo->setup->check_status_sema = sem_open(CHECK_STATUS_SEMA, \
	O_CREAT, MODE, 1);
	if (philo->setup->check_status_sema == SEM_FAILED)
		return (set_sema_dead(philo->setup, 1));
	sem_unlink(CHECK_STATUS_SEMA);
	philo->setup->write_sema = sem_open(WRITE_SEMA, O_CREAT, MODE, 1);
	if (philo->setup->write_sema == SEM_FAILED)
		return (set_sema_dead(philo->setup, 1));
	sem_unlink(WRITE_SEMA);
	return (0);
}

int 	initialise_philos(t_setup *setup, t_philosopher *philos)
{
	setup_each_philo(setup, philos);
	if (init_write_and_status_sema(philos))
		return (-1);
	return (0);
}
