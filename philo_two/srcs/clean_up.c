//
// Created by qli on 17/02/2021.
//

#include "../headers/clean_up.h"

void 	clean_up_philos(t_philosopher *philos)
{
	free(philos);
}

void 	clean_up_setup_semaphores(t_setup *setup)
{
	pthread_mutex_destroy(&setup->write_mutex); // need to replace
	pthread_mutex_destroy(&setup->status_mutex); // need to replace
}

int 	clean_up(t_setup *setup, t_philosopher *philos, int return_value)
{
	if (philos)
	{
		clean_up_setup_semaphores(setup);
		clean_up_philos(philos);
	}
	return (return_value);
}
