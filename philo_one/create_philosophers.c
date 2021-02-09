//
// Created by qli on 09/02/2021.
//

#include "philo_one.h"
#include <stdlib.h>

int malloc_philosophers(t_philosopher *philo, t_setup_data setup)
{
	int i;

	i = 0;
	philo->philo_array = (int *)malloc(sizeof(int) * setup.number_of_philosophers);
	if (!philo->philo_array)
		return (-1);
	while (i < setup.number_of_philosophers)
	{
		philo->philo_array[i] = i;
		i++;
	}
	return (0);
}

void philo_print_output(t_philosopher *philo, t_setup_data setup)
{
	int i;
	struct timeval 	begin_time;
	struct timeval 	finish_time;

	i = 0;
	gettimeofday(&begin_time, NULL);
	while (i < setup.number_of_philosophers)
	{
		gettimeofday(&finish_time, NULL);
		printf("%ld ", finish_time.tv_usec - begin_time.tv_usec);
		printf("%d ", i + 1);
		printf("has taken a fork\n");
		printf("%ld ", finish_time.tv_usec - begin_time.tv_usec);
		printf("%d ", i + 1);
		printf("is eating\n");
		i++;
	}
}

int create_philosophers(t_philosopher *philo, t_setup_data setup)
{
	malloc_philosophers(philo, setup);
	philo_print_output(philo, setup);
	return (0);
}