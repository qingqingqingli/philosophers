//
// Created by qli on 08/02/2021.
//

#include "philo_one.h"

void process_argv_input(int argc, char **argv, t_setup_data *setup)
{
	setup->number_of_philosophers = ft_atoi(argv[1]);
	setup->time_to_die = ft_atoi(argv[2]);
	setup->time_to_eat = ft_atoi(argv[3]);
	setup->time_to_sleep = ft_atoi(argv[4]);
	if (argc == 6)
		setup->number_of_times_each_philosopher_must_eat = ft_atoi(argv[5]);
	else
		setup->number_of_times_each_philosopher_must_eat = -1;
}

int validate_setup_data(t_setup_data setup)
{
	if (setup.number_of_philosophers <= 0 || setup.time_to_die <= 0 || setup.time_to_eat <= 0 || setup.time_to_sleep <= 0 || setup.number_of_times_each_philosopher_must_eat == 0)
	{
		printf("Provided data not valid.\n");
		return (-1);
	}
	return 0;
}

int init_program_setup(int argc, char **argv, t_setup_data *setup)
{
	if (argc == 5 || argc == 6)
	{
		process_argv_input(argc, argv, setup);
		if (validate_setup_data(*setup) == NOT_VALID)
			return (-1);
		print_philo_data(*setup);
		return (0);
	}
	printf("Arguments not correct.\n");
	return (-1);
}

