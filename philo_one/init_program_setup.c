//
// Created by qli on 08/02/2021.
//

#include <stdlib.h>
#include "philo_one.h"
#include "libft/libft.h"

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
	return (0);
}

void init_each_philo(t_setup_data *setup)
{
	int i;

	i = 0;
	setup->philos = (malloc(sizeof(t_philosopher) * setup->number_of_philosophers));
	while (i < setup->number_of_philosophers)
	{
		setup->philos[i].philo_number = i + 1;
		setup->philos[i].time_to_sleep = setup->time_to_sleep;
		setup->philos[i].time_to_eat = setup->time_to_eat;
		setup->philos[i].time_to_die = setup->time_to_die;
		gettimeofday(&setup->philos[i].begin_time, NULL);
		i++;
	}
}

void	init_fork_mutexes(t_setup_data *setup)
{
	int i;

	i = 0;
	setup->fork_mutexs = malloc(sizeof(pthread_mutex_t) * setup->number_of_philosophers);
	while (i < setup->number_of_philosophers)
	{
		pthread_mutex_init(&setup->fork_mutexs[i], NULL);
		i++;
	}
}

void set_philo_fork_mutexs(t_setup_data *setup)
{
	int i;

	i = 0;
	setup->philos[i].left_fork_mutex = &setup->fork_mutexs[i];
	setup->philos[i].right_fork_mutex = &setup->fork_mutexs[setup->number_of_philosophers - 1];
	i++;
	while (i < setup->number_of_philosophers)
	{
		setup->philos[i].left_fork_mutex = &setup->fork_mutexs[i];
		setup->philos[i].right_fork_mutex = &setup->fork_mutexs[i - 1];
		i++;
	}

}

void init_philo_threads(t_setup_data *setup)
{
	int i;

	i = 0;
	setup->philo_threads = malloc(sizeof(pthread_t) * setup->number_of_philosophers);
	setup->philo_status_threads = malloc(sizeof(pthread_t) * setup->number_of_philosophers);
	while (i < setup->number_of_philosophers)
	{
		pthread_create(&setup->philo_threads[i], NULL, start_action, &setup->philos[i]);
		pthread_create(&setup->philo_status_threads[i], NULL, check_status, &setup->philos[i]);
		i++;
	}
}

void join_threads(t_setup_data *setup)
{
	int i;

	i = 0;
	while (i < setup->number_of_philosophers)
	{
		pthread_join(setup->philo_threads[i], NULL);
		// not sure about joining the threads of life_status
//		pthread_join(setup->philo_status_threads[i], NULL);
		i++;
	}
}

int init_program_setup(int argc, char **argv, t_setup_data *setup)
{
	if (argc == 5 || argc == 6)
	{
		process_argv_input(argc, argv, setup);
		if (validate_setup_data(*setup) == -1)
			return (-1);
		print_philo_data(*setup);
		init_each_philo(setup);
		init_fork_mutexes(setup);
		set_philo_fork_mutexs(setup);
		init_philo_threads(setup);
		join_threads(setup);
	}
	else
	{
		printf("Arguments not correct.\n");
		return (-1);
	}
	return (0);
}

