//
// Created by qli on 17/02/2021.
//


#include "../headers/process_input.h"

// remove later
void print_setup_date(t_setup setup)
{
	printf("number_of_philosophers = [%lld]\n", setup.number_of_philosophers);
	printf("time_to_die = [%lld]\n", setup.time_to_die);
	printf("time_to_eat = [%lld]\n", setup.time_to_eat);
	printf("time_to_sleep = [%lld]\n", setup.time_to_sleep);
	printf("number_of_times_each_philosopher_must_eat = [%lld]\n", setup.number_of_times_each_philosopher_must_eat);
}

int validate_setup_data(t_setup setup)
{
	if (setup.number_of_philosophers <= 0 || setup.time_to_die <= 0 || setup.time_to_eat <= 0 || setup.time_to_sleep <= 0 || (setup.number_to_eat_exist == yes && setup.number_of_times_each_philosopher_must_eat <= 0))
	{
		printf("Provided data not valid.\n");
		return (-1);
	}
	return (0);
}

void process_setup_data(int argc, char **argv, t_setup *setup)
{
	setup->number_of_philosophers = ft_atoi(argv[1]);
	setup->time_to_die = ft_atoi(argv[2]);
	setup->time_to_eat = ft_atoi(argv[3]);
	setup->time_to_sleep = ft_atoi(argv[4]);
	if (argc == 6)
	{
		setup->number_to_eat_exist = yes;
		setup->number_of_times_each_philosopher_must_eat = ft_atoi(argv[5]);
	}
	else
		setup->number_to_eat_exist = no;
}

void initialise_setup(t_setup *setup)
{
	setup->number_of_philosophers = 0;
	setup->time_to_die = 0;
	setup->time_to_eat = 0;
	setup->time_to_sleep = 0;
	setup->number_to_eat_exist = no;
	setup->number_of_times_each_philosopher_must_eat = 0;
	setup->life_status = alive;
}

int create_fork_mutexes(t_setup *setup)
{
	int	i;
	int ret;

	i = 0;
	ret = 0;
	setup->fork_mutexs = malloc(sizeof(pthread_mutex_t) * setup->number_of_philosophers);
	if (!setup->fork_mutexs)
		return (-1);
	while (i < setup->number_of_philosophers)
	{
		ret = pthread_mutex_init(&setup->fork_mutexs[i], NULL);
		if (ret)
			return (error_occurred);
		i++;
	}
	return (0);
}

int destroy_mutexes(pthread_mutex_t *mutexs)
{
	pthread_mutex_destroy(mutexs);
	free(mutexs);
	return (error_occurred);
}

int process_input(int argc, char **argv, t_setup *setup)
{
	initialise_setup(setup);
	process_setup_data(argc, argv, setup);
	if (validate_setup_data(*setup) == error_occurred)
		return (error_occurred);
	print_setup_date(*setup); // remove later
	if (create_fork_mutexes(setup) == error_occurred)
		return (destroy_mutexes(setup->fork_mutexs));
	return (0);
}