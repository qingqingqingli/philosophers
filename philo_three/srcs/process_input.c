//
// Created by qli on 17/02/2021.
//

#include "../headers/process_input.h"
#include "../headers/clean_up.h"
#include "../headers/libft_functions.h"

int	check_argc_all_digits(int argc, char **argv)
{
	int	num;
	int	i;

	i = 0;
	num = 1;
	while (num < argc)
	{
		i = 0;
		while (argv[num][i] != '\0')
		{
			if (ft_isdigit(argv[num][i]))
				i++;
			else
			{
				if (argv[num][i] == '+' && i == 0)
					i++;
				else
					return (-1);
			}
		}
		num++;
	}
	return (0);
}

int	process_setup_data(int argc, char **argv, t_setup *setup)
{
	setup->life_status = alive;
	setup->sema_status = alive;
	setup->fork_sema = NULL;
	setup->write_sema = NULL;
	setup->check_status_sema = NULL;
	setup->number_of_philosophers = ft_atoi(argv[1]);
	setup->time_to_die = ft_atoi(argv[2]);
	setup->time_to_eat = ft_atoi(argv[3]);
	setup->time_to_sleep = ft_atoi(argv[4]);
	if (argc == 6)
	{
		setup->number_of_times_each_philosopher_must_eat = ft_atoi(argv[5]);
		if (setup->number_of_times_each_philosopher_must_eat <= 0)
			return (-1);
	}
	else
		setup->number_of_times_each_philosopher_must_eat = 0;
	return (0);
}

int		validate_input_value(t_setup *setup)
{
	if (setup->number_of_philosophers <= 0 || setup->time_to_sleep <= 0 || \
	setup->time_to_die <= 0 || setup->time_to_eat <= 0)
		return (-1);
	return (0);
}

void	print_setup_date(t_setup setup)
{
	printf("number_of_philosophers = [%d]\n", setup.number_of_philosophers);
	printf("time_to_die = [%lld]\n", setup.time_to_die);
	printf("time_to_eat = [%lld]\n", setup.time_to_eat);
	printf("time_to_sleep = [%lld]\n", setup.time_to_sleep);
	printf("number_of_times_each_philosopher_must_eat = [%d]\n", \
	setup.number_of_times_each_philosopher_must_eat);
}

int	create_fork_semaphores(t_setup *setup)
{
	setup->fork_sema = sem_open(FORK_SEMA, O_CREAT, 0644, \
	setup->number_of_philosophers);
	if (setup->fork_sema == SEM_FAILED)
		return (set_sema_dead(setup, -1));
	sem_unlink(FORK_SEMA);
	return (0);
}

int	process_input(int argc, char **argv, t_setup *setup)
{
	if (argc != 5 && argc != 6)
	{
		printf("Arguments not correct.\n");
		return (-1);
	}
	if (check_argc_all_digits(argc, argv) == -1 || \
	process_setup_data(argc, argv, setup) == -1 || \
	validate_input_value(setup) == -1)
	{
		printf("Provided data not valid.\n");
		return (-1);
	}
	print_setup_date(*setup);
	if (create_fork_semaphores(setup) == -1)
		return (-1);
	return (0);
}
