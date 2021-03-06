//
// Created by qli on 17/02/2021.
//

#include <stdlib.h>
#include "headers/struct.h"
#include "headers/process_input.h"
#include "headers/initialise_philos.h"
#include "headers/clean_up.h"

int 	main(int argc, char **argv)
{
	t_setup			setup;
	t_philosopher	*philos;

	if (process_input(argc, argv, &setup) == -1)
		return (clean_up(&setup, NULL, -1));
	philos = malloc(sizeof(t_philosopher) * setup.number_of_philosophers);
	if (!philos)
		return (clean_up(&setup, philos, -1));
	printf("time\tindex\taction\n");
	if (initialise_philos(&setup, philos) == -1)
		return (clean_up(&setup, philos, -1));
	return (clean_up(&setup, philos, 0));
}
