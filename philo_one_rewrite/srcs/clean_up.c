//
// Created by qli on 17/02/2021.
//

#include "../headers/clean_up.h"

void 	clean_up_setup(t_setup *setup)
{
	if (setup->fork_mutexs)
		free(setup->fork_mutexs);
	if (setup)
		free(setup);
}

void 	clean_up_philos(t_philosopher **philos, long long int num)
{
	int i;

	i = 0;
	if (philos)
	{
		while (i < num)
		{
			free(philos[i]);
			i++;
		}
		free(philos);
	}
}

int 	clean_up(t_setup *setup, t_philosopher **philos)
{
	clean_up_philos(philos, setup->number_of_philosophers);
	clean_up_setup(setup);
	return (error_occurred);
}