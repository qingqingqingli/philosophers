//
// Created by qli on 17/02/2021.
//

#include <stdio.h>
#include "../headers/initialise_philos.h"
#include "../headers/start_action.h"
#include "../headers/check_status.h"

void setup_each_philo(t_setup *setup, t_philosopher *philos)
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
		pthread_mutex_init(&philos[i].status_mutex, NULL);
		i++;
	}
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

void	init_philo_threads(t_philosopher *philos, int num)
{
	int i;

	i = 0;
	while (i < num)
	{
		pthread_create(&philos[i].philo_thread, NULL, start_action, &philos[i]);
		pthread_create(&philos[i].philo_status_thread, NULL, check_status, &philos[i]);
		i++;
	}
	i = 0;
	while (i < num)
	{
		pthread_join(philos[i].philo_thread, NULL);
		pthread_join(philos[i].philo_status_thread, NULL);
		i++;
	}
}

void 	init_write_mutex(t_philosopher *philo)
{
	pthread_mutex_init(&philo->setup->write_mutex, NULL);
}

int 	initialise_philos(t_setup *setup, t_philosopher *philos)
{
	int num;

	num = setup->number_of_philosophers;
	setup_each_philo(setup, philos);
	set_philo_fork_mutexs(philos, num);
	init_write_mutex(philos);
	init_philo_threads(philos, num);
	return (0);
}