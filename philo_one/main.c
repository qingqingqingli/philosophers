//
// Created by qli on 08/02/2021.
//

#include "philo_one.h"

int main(int argc, char **argv)
{
	t_philo_data philo_data;
	if (argc == 5 || argc == 6)
	{
		initialise_philo_states(argc, argv, &philo_data);
		if (validate_philo_data(philo_data) == NOT_VALID)
		{
			printf("Provided data not valid.\n");
			return (-1);
		}
		print_philo_data(philo_data);
	}
	else
	{
		printf("Arguments not correct.\n");
		return (-1);
	}
	return (0);
}
