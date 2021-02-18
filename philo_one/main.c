//
// Created by qli on 17/02/2021.
//

#include <stdio.h>
#include <stdlib.h>
#include "headers/struct.h"
#include "headers/process_input.h"
#include "headers/initialise_philos.h"
#include "headers/clean_up.h"

int 	main(int argc, char **argv)
{
	t_setup 		setup;
	t_philosopher 	*philos;

	if (process_input(argc, argv, &setup) == error)
		return clean_up(&setup, NULL, error);
	philos = malloc(sizeof(t_philosopher) * setup.number_of_philosophers);
	if (!philos)
		return (clean_up(&setup, philos, error));
	if (initialise_philos(&setup, philos) == error)
		return clean_up(&setup, philos, error);
	return (clean_up(&setup, philos, 0));
}