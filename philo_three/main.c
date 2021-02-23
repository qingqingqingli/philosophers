//
// Created by qli on 17/02/2021.
//

#include <stdlib.h>
#include <wait.h>
#include "headers/struct.h"
#include "headers/process_input.h"
#include "headers/initialise_philos.h"
#include "headers/clean_up.h"

void 	wait_for_child_processes(t_philosopher *philos, int num)
{
	int	i;
	int status;

	status = 0;
	i = 0;
	while (!waitpid(-1, &status, 0));
	printf("kill all processes\n");
	while (i < num)
	{
		kill(philos[i].fork_id, 9);
		i++;
	}
}

int 	main(int argc, char **argv)
{
	t_setup			setup;
	t_philosopher	*philos;

	if (process_input(argc, argv, &setup) == -1)
		return (clean_up(&setup, NULL, -1));
	philos = malloc(sizeof(t_philosopher) * setup.number_of_philosophers);
	if (!philos)
		return (clean_up(&setup, philos, -1));
	if (initialise_philos(&setup, philos) == -1)
		return (clean_up(&setup, philos, -1));
	wait_for_child_processes(philos, setup.number_of_philosophers);
	return (clean_up(&setup, philos, 0));
}
