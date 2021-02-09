//
// Created by qli on 09/02/2021.
//

#include "philo_one.h"
#include <stdlib.h>

static pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;
int number_of_forks = 8;

void* print_something(void *arg)
{
	t_philosopher *tmp;
	tmp = arg;
	if (number_of_forks >= 2)
	{
		pthread_mutex_lock(&mutex);
		number_of_forks -= 2;
		gettimeofday(&tmp->current_time, NULL);
		printf("%ld %d is eating\n", tmp->current_time.tv_usec - tmp->begin_time.tv_usec, tmp->philo_number[0]);
		usleep(80000);
		number_of_forks += 2;
		pthread_mutex_unlock(&mutex);
	}
	return NULL;
}

int	create_pthreads(t_philosopher *philo, t_setup_data setup)
{
	int i;

	i = 0;
	philo->philo_threads = malloc(sizeof(pthread_t) * setup.number_of_philosophers);
	if (!philo->philo_threads)
		return (-1);
	gettimeofday(&philo->begin_time, NULL);
	philo->philo_number = malloc(sizeof(int) * setup.number_of_philosophers);
	while (i < setup.number_of_philosophers)
	{
		philo->philo_number[i] = i + 1;
		i++;
	}
	return (0);
}

void join_pthreads(t_philosopher *philo, t_setup_data setup)
{
	int i;

	i = 0;
	while (i < setup.number_of_philosophers)
	{
		pthread_join(philo->philo_threads[i], NULL);
		i++;
	}
}

void	take_action(t_philosopher *philo, t_setup_data setup)
{
	int i;

	i = 0;
	while (i < setup.number_of_philosophers)
	{
		pthread_create(&philo->philo_threads[i], NULL, print_something, (void *)philo);
		i++;
	}
}

int create_philos(t_philosopher *philo, t_setup_data setup)
{
	create_pthreads(philo, setup);
	take_action(philo, setup);
	join_pthreads(philo, setup);
	return (0);
}