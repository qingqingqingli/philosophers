//
// Created by qli on 08/02/2021.
//

#include "philo_one.h"

int 	main(int argc, char **argv)
{
	t_setup_data setup_data;
	t_philosopher philo_data;

	if (init_program_setup(argc, argv, &setup_data) == -1)
		return (-1);
	create_philosophers(&philo_data, setup_data);
	return (0);
}
