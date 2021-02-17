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
	t_setup 		*setup;
	t_philosopher 	**philos;

	setup = malloc(sizeof(t_setup));
	if (!setup)
		return (error_occurred);
	if (argc == 5 || argc == 6)
	{
		if (process_input(argc, argv, setup) == error_occurred)
			return clean_up(setup, NULL, error_occurred);
		philos = (t_philosopher **)malloc(sizeof(t_philosopher *) * setup->number_of_philosophers);
		if (!philos)
			return clean_up(setup, philos, error_occurred);
		if (initialise_philos(setup, philos) == error_occurred)
			return clean_up(setup, philos, error_occurred);
	}
	else
	{
		printf("Arguments not correct.\n");
		return (error_occurred);
	}
	return (clean_up(setup, philos, 0));
}