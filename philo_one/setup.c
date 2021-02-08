//
// Created by qli on 08/02/2021.
//

#include "philo_one.h"

void initialise_philo_states(int argc, char **argv, t_philo_data *philo_data)
{
	philo_data->number_of_philosophers = ft_atoi(argv[1]);
	philo_data->time_to_die = ft_atoi(argv[2]);
	philo_data->time_to_eat = ft_atoi(argv[3]);
	philo_data->time_to_sleep = ft_atoi(argv[4]);
	if (argc == 6)
		philo_data->number_of_times_each_philosopher_must_eat = ft_atoi(argv[5]);
	else
		philo_data->number_of_times_each_philosopher_must_eat = -1;
}

int validate_philo_data(t_philo_data data)
{
	if (data.number_of_philosophers <= 0 || data.time_to_die <= 0 || data.time_to_eat <= 0 || data.time_to_sleep <= 0 || data.number_of_times_each_philosopher_must_eat == 0)
		return (-1);
	return 0;
}