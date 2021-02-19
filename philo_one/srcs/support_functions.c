//
// Created by qli on 17/02/2021.
//

#include <unistd.h>
#include "../headers/support_functions.h"

long int get_elapsed_milli(struct timeval *previous, struct timeval *now)
{
	return ((now->tv_sec - previous->tv_sec) * 1000000 + (now->tv_usec - previous->tv_usec)) / 1000;
}

long int get_current_time_micro()
{
	struct timeval	current_time;

	gettimeofday(&current_time, NULL);
	return (current_time.tv_sec * 1000000 + current_time.tv_usec);
}

void 	accurately_sleep(long int amount_to_sleep)
{
	long int starting_time;

	starting_time = get_current_time_micro();
	while (get_current_time_micro() - starting_time < amount_to_sleep)
	{
		usleep(1000);
	}
}

int		ft_atoi(const char *str)
{
	long int i;
	long int neg;
	long int output;

	i = 0;
	neg = 1;
	output = 0;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-')
		neg = neg * -1;
	if (str[i] == '+' || str[i] == '-')
		i++;
	while (str[i] != '\0' && str[i] >= '0' && str[i] <= '9')
	{
		if (output * 10 + str[i] - '0' < output && neg == 1)
			return (-1);
		if (output * 10 + str[i] - '0' < output && neg == -1)
			return (0);
		output = output * 10 + str[i] - '0';
		i++;
		if (str[i] < '0' || str[i] > '9')
			return ((int)output * neg);
	}
	return ((int)output * neg);
}

int	ft_isdigit(int c)
{
	if (c <= '9' && c >= '0')
	{
		return (1);
	}
	return (0);
}
