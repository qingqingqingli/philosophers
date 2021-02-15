//
// Created by qli on 08/02/2021.
//

#include "philo_one.h"

int 	main(int argc, char **argv)
{
	t_setup_data setup;

	life_status = 1;
	if (argc == 5 || argc == 6)
	{
		process_argv_input(argc, argv, &setup);
		if (validate_setup_data(setup) == -1)
			return (-1);
		print_philo_data(setup);
		init_each_philo(&setup);
		init_fork_mutexes(&setup);
		set_philo_fork_mutexs(&setup);
		init_philo_threads(&setup);
	}
	else
	{
		printf("Arguments not correct.\n");
		return (-1);
	}
	return (0);
}
