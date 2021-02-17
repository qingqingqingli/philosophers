//
// Created by qli on 17/02/2021.
//

#include "../headers/initialise_philos.h"

int malloc_philos(t_philosopher **philos, long long int num)
{
	long long int i;

	i = 0;
	philos = (t_philosopher **)malloc(sizeof(t_philosopher *) * num);
	if (!philos)
		return (error_occurred);
	while(i < num)
	{
		philos[i] = (t_philosopher *)malloc(sizeof(t_philosopher));
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