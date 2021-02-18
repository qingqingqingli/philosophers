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

int destroy_mutexes(pthread_mutex_t *mutexs)
{
	pthread_mutex_destroy(mutexs);
	free(mutexs);
	return (-1);
}

//void 	clean_up_setup(t_setup *setup)
//{
//	if (setup->fork_mutexs)
//		free(setup->fork_mutexs);
//}

int 	clean_up(t_philosopher *philos, int return_value)
{
	clean_up_philos(philos);
//	clean_up_setup(setup);
	return (return_value);
}