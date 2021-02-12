//
// Created by qli on 08/02/2021.
//

#include "philo_one.h"

int 	main(int argc, char **argv)
{
	t_setup_data setup_data;
	int i;

	i = 0;

	if (init_program_setup(argc, argv, &setup_data) == -1)
		return (-1);
	return (0);
}
