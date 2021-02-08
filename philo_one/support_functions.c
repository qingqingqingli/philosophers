//
// Created by qli on 08/02/2021.
//
#include "philo_one.h"

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

void print_philo_data(t_philo_data data)
{
	printf("number_of_philosophers = [%d]\n", data.number_of_philosophers);
	printf("time_to_die = [%lld]\n", data.time_to_die);
	printf("time_to_eat = [%lld]\n", data.time_to_eat);
	printf("time_to_sleep = [%lld]\n", data.time_to_sleep);
	printf("number_of_times_each_philosopher_must_eat = [%d]\n", data.number_of_times_each_philosopher_must_eat);
}