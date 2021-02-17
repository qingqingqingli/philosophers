//
// Created by qli on 17/02/2021.
//

#include "../headers/initialise_philos.h"

int malloc_philos(t_philosopher **philos, long long int num)
{
	long long int i;

	i = 0;
	while(i < num)
	{
		philos[i] = (t_philosopher *)malloc(sizeof(t_philosopher));
		if (i == 3)
			return (-1);
		if (!philos[i])
			return (error_occurred);
		i++;
	}
	return (0);
}

int initialise_philos(t_setup *setup, t_philosopher **philos)
{
	if (malloc_philos(philos, setup->number_of_philosophers) == error_occurred)
		return (error_occurred);

	return (0);
}