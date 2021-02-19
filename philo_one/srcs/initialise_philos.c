//
// Created by qli on 17/02/2021.
//

#include <stdio.h>
#include "../headers/initialise_philos.h"
#include "../headers/start_action.h"
#include "../headers/check_status.h"

int 	setup_each_philo(t_setup *setup, t_philosopher *philos)
{
	int i;

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

void set_philo_fork_mutexs(t_philosopher *philos, int num)
{
	int i;

	i = 0;
	philos[i].left_fork_mutex = &philos->setup->fork_mutexs[i];
	philos[i].right_fork_mutex = &philos->setup->fork_mutexs[num - 1];
	i++;
	while (i < num)
	{
		philos[i].left_fork_mutex = &philos->setup->fork_mutexs[i];
		philos[i].right_fork_mutex = &philos->setup->fork_mutexs[i - 1];
		i++;
	}
}

int		init_philo_threads(t_philosopher *philos, int num)
{
	int i;

	i = 0;
	while (i < num)
	{
		if (pthread_create(&philos[i].philo_thread, NULL, start_action, &philos[i]))
			return (-1);
		if (pthread_create(&philos[i].philo_status_thread, NULL, check_status, &philos[i]))
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
	if (pthread_mutex_init(&philo->setup->status_mutex, NULL))
		return (-1);
	if (pthread_mutex_init(&philo->setup->write_mutex, NULL))
		return (-1);
	return (0);
}

int 	initialise_philos(t_setup *setup, t_philosopher *philos)
{
	int num;

	num = setup->number_of_philosophers;
	if (setup_each_philo(setup, philos) == -1)
		return (-1);
	set_philo_fork_mutexs(philos, num);
	if (init_write_mutex(philos) == -1 || init_philo_threads(philos, num) == -1)
		return (-1);
	return (0);
}