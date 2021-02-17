//
// Created by qli on 08/02/2021.
//

#include "philo_one.h"

int 	main(int argc, char **argv)
{
	t_common 	common;
	t_philo 	*philo;

	if (argc == 5 || argc == 6)
	{
		process_argv_input(argc, argv, &common);
		if (validate_setup_data(common) == -1)
			return (-1);
		print_philo_data(common);
		init_fork_mutexes(&common);
		init_each_philo(philo, &common);
		set_philo_fork_mutexs(philo, &common);
		init_philo_threads(philo, common);
	}
	else
	{
		printf("Arguments not correct.\n");
		return (-1);
	}
	return (0);
}
