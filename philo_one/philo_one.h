//
// Created by qli on 08/02/2021.
//

#pragma once
#include <stdio.h>

#define NOT_VALID	-1

typedef struct 		s_philo_data
{
	int 			number_of_philosophers;
	long long int 	time_to_die;
	long long int 	time_to_eat;
	long long int 	time_to_sleep;
	int 			number_of_times_each_philosopher_must_eat;
}					t_philo_data;

// ** SUPPORT FUNCTIONS ** //

int		ft_atoi(const char *str);

// ** SETUP ** //

void initialise_philo_states(int argc, char **argv, t_philo_data *philo_data);
int validate_philo_data(t_philo_data data);
void print_philo_data(t_philo_data data);