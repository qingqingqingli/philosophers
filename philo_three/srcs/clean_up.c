//
// Created by qli on 17/02/2021.
//

#include "../headers/clean_up.h"

int 	clean_up(t_philosopher *philos, int return_value)
{
	if (philos)
		free(philos);
	return (return_value);
}
