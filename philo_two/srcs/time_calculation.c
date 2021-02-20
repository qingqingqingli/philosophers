//
// Created by qli on 17/02/2021.
//

#include <unistd.h>
#include "../headers/time_calculation.h"

long int	get_elapsed_milli(struct timeval *previous, struct timeval *now)
{
	return (((now->tv_sec - previous->tv_sec) * 1000000 + \
	(now->tv_usec - previous->tv_usec)) / 1000);
}

long int	get_current_time_micro(void)
{
	struct timeval	current_time;

	gettimeofday(&current_time, NULL);
	return (current_time.tv_sec * 1000000 + current_time.tv_usec);
}

void	accurately_sleep(long int amount_to_sleep)
{
	long int	starting_time;

	starting_time = get_current_time_micro();
	while (get_current_time_micro() - starting_time < amount_to_sleep)
	{
		usleep(100);
	}
}
