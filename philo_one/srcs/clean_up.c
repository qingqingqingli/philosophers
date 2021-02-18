//
// Created by qli on 17/02/2021.
//

#include <stdio.h>
#include "../headers/clean_up.h"

void 	clean_up_philos(t_philosopher *philos)
{
	if (philos)
		free(philos);
}

void 	clean_up_mutexes(t_setup *setup, t_philosopher *philos)
{
	int i;

	i = 0;
	if (setup->fork_mutexs)
	{
		while (i < setup->number_of_philosophers)
		{
			pthread_mutex_destroy(&setup->fork_mutexs[i]);
			pthread_mutex_destroy(&philos[i].status_mutex);
			i++;
		}
		free(setup->fork_mutexs);
	}
	pthread_mutex_destroy(&setup->write_mutex);
}

int 	clean_up(t_setup *setup, t_philosopher *philos, int return_value)
{
	clean_up_mutexes(setup, philos);
	clean_up_philos(philos);
	return (return_value);
}