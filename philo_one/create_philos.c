//
// Created by qli on 09/02/2021.
//

#include "philo_one.h"
#include <stdlib.h>
long long int number_of_forks = 0;

void* print_something(void *arg)
{
	pthread_mutex_t mutex;
	t_philosopher 	*philo;
	long int 		time_diff;

	philo = arg;
	pthread_mutex_init(&mutex, NULL);
	if (number_of_forks >= 2)
	{
		pthread_mutex_lock(&mutex);
		number_of_forks -= 2;
		gettimeofday(&philo->current_time, NULL);
		time_diff = philo->current_time.tv_usec - philo->begin_time.tv_usec;
		printf("%ld %d is eating\n", time_diff, philo->philo_number);
		usleep(80000);
		number_of_forks += 2;
		pthread_mutex_unlock(&mutex);
	}
	return NULL;
}

void setup_philo_pthreads(t_philosopher **philos, t_setup_data setup)
{
	int i;

	i = 0;
	while (i < setup.number_of_philosophers)
	{
		gettimeofday(&philos[i]->begin_time, NULL);
		pthread_create(philos[i]->philo_thread, NULL, print_something, (void *)(philos[i]));
		pthread_join(*philos[i]->philo_thread, NULL);
		i++;
	}
}

void create_each_philo(t_philosopher **philos, t_setup_data setup)
{
	int i;

	i = 0;
	while (i < setup.number_of_philosophers)
	{
		philos[i] = (t_philosopher *)malloc(sizeof(t_philosopher));
		philos[i]->philo_thread = malloc(sizeof(pthread_t));
		philos[i]->time_to_eat = setup.time_to_eat;
		philos[i]->time_to_die = setup.time_to_die;
		philos[i]->time_to_sleep = setup.time_to_sleep;
		philos[i]->philo_number = i + 1;
		i++;
	}
}

int create_philos(t_philosopher **philos, t_setup_data setup)
{
	philos = (t_philosopher **)malloc(sizeof(t_philosopher *) * setup.number_of_philosophers);
	if (!philos)
		return (-1);
	number_of_forks = setup.number_of_philosophers;
	create_each_philo(philos, setup);
	setup_philo_pthreads(philos, setup);

	return (0);
}