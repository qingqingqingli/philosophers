//
// Created by qli on 08/02/2021.
//

#pragma once
#include <stdio.h>

typedef struct 				s_philo_data
{
	unsigned int 			number_of_philosophers;
	unsigned long long int 	time_to_die;
	unsigned long long int 	time_to_eat;
	unsigned long long int 	time_to_sleep;
	unsigned int 			number_of_times_each_philosopher_must_eat;
}							t_philo_data;

// ** SUPPORT FUNCTIONS ** //

int		ft_atoi(const char *str);

// ** SETUP ** //

void initialise_philo_states(int argc, char **argv, t_philo_data *philo_data);
int validate_philo_data(t_philo_data data);
void print_philo_data(t_philo_data data);