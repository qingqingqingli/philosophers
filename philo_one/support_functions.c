//
// Created by qli on 08/02/2021.
//

#include "philo_one.h"

void print_philo_data(t_setup_data data)
{
	printf(YELLOW "number_of_philosophers = [%lld]\n", data.number_of_philosophers);
	printf("time_to_die = [%lld]\n", data.time_to_die);
	printf("time_to_eat = [%lld]\n", data.time_to_eat);
	printf("time_to_sleep = [%lld]\n", data.time_to_sleep);
	printf("number_of_times_each_philosopher_must_eat = [%lld]\n", data.number_of_times_each_philosopher_must_eat);
	printf(RESET);
}

long int get_elapsed_ms(struct timeval *previous, struct timeval *now)
{
	return ((now->tv_sec - previous->tv_sec) * 1000000 + (now->tv_usec - previous->tv_usec));
}