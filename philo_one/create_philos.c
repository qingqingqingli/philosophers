//
// Created by qli on 09/02/2021.
//

#include "philo_one.h"
#include <stdlib.h>
int number_of_forks = 2;
pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

void* print_something(void *arg)
{
	t_philosopher *tmp;
	tmp = arg;
	if (number_of_forks >= 2)
	{
		pthread_mutex_lock(&mutex);
		number_of_forks -= 2;
		gettimeofday(&tmp->current_time, NULL);
		printf("%ld %d is eating\n", tmp->current_time.tv_usec - tmp->begin_time.tv_usec, tmp->philo_number);
		usleep(800000);
		number_of_forks += 2;
		pthread_mutex_unlock(&mutex);
	}
	return NULL;
}

void setup_philo_pthreads(t_philosopher **philos, t_setup_data setup)
{
	int i;

	i = 0;
	philos = (t_philosopher **)malloc(sizeof(t_philosopher *) * setup.number_of_philosophers);
	while (i < setup.number_of_philosophers)
	{
		philos[i] = (t_philosopher *)malloc(sizeof(t_philosopher));
		philos[i]->philo_thread = malloc(sizeof(pthread_t));
		pthread_create(philos[i]->philo_thread, NULL, print_something, (void *)(philos[i]));
		philos[i]->philo_number = i + 1;
		gettimeofday(&philos[i]->begin_time, NULL);
		pthread_join(*philos[i]->philo_thread, NULL);
		i++;
	}
}

int create_philos(t_philosopher **philos, t_setup_data setup)
{
	setup_philo_pthreads(philos, setup);

	return (0);
}