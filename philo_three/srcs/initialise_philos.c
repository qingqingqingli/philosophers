//
// Created by qli on 17/02/2021.
//

#include <stdio.h>
#include "../headers/initialise_philos.h"
#include "../headers/start_action.h"
#include "../headers/check_status.h"

int 	setup_each_philo(t_setup *setup, t_philosopher *philos)
{
	int	i;

	i = 0;
	while (i < setup->number_of_philosophers)
	{
		philos[i].setup = setup;
		philos[i].num = i + 1;
		philos[i].time_of_eaten = 0;
		gettimeofday(&philos[i].begin_time, NULL);
		gettimeofday(&philos[i].last_eat_time, NULL);
		i++;
	}
	return (0);
}

int	init_philo_threads(t_philosopher *philos, int num)
{
	int	i;

	i = 0;
	while (i < num)
	{
		if (pthread_create(&philos[i].philo_thread, NULL, \
		start_action, &philos[i]))
			return (-1);
		usleep(100);
		if (pthread_create(&philos[i].philo_status_thread, NULL, \
		check_status, &philos[i]))
			return (-1);
		i++;
	}
	i = 0;
	while (i < num)
	{
		if (pthread_join(philos[i].philo_thread, NULL))
			return (-1);
		if (pthread_join(philos[i].philo_status_thread, NULL))
			return (-1);
		i++;
	}
	return (0);
}

int 	init_write_mutex(t_philosopher *philo)
{

	philo->setup->status_sema = sem_open("status_sema", O_CREAT, 0644, 1);
	if (philo->setup->status_sema == SEM_FAILED)
		return (-1);
	sem_unlink("status_sema");
	philo->setup->write_sema = sem_open("write_sema", O_CREAT, 0644, 1);
	if (philo->setup->write_sema == SEM_FAILED)
		return (-1);
	sem_unlink("write_sema");

	return (0);
}

int 	initialise_philos(t_setup *setup, t_philosopher *philos)
{
	int	num;

	num = setup->number_of_philosophers;
	if (setup_each_philo(setup, philos) == -1)
		return (-1);
	if (init_write_mutex(philos) == -1 || init_philo_threads(philos, num) == -1)
		return (-1);
	return (0);
}
