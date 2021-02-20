//
// Created by qli on 17/02/2021.
//

#include "../headers/clean_up.h"

void 	clean_up_philos(t_philosopher *philos)
{
	free(philos);
}

void 	clean_up_setup_mutexes(t_setup *setup)
{
	int	i;

	i = 0;
	if (setup->fork_mutexs)
	{
		while (i < setup->number_of_philosophers)
		{
			pthread_mutex_destroy(&setup->fork_mutexs[i]);
			i++;
		}
		free(setup->fork_mutexs);
		pthread_mutex_destroy(&setup->write_mutex);
		pthread_mutex_destroy(&setup->status_mutex);
	}
}

int 	clean_up(t_setup *setup, t_philosopher *philos, int return_value)
{
	if (philos)
	{
		clean_up_setup_mutexes(setup);
		clean_up_philos(philos);
	}
	return (return_value);
}
