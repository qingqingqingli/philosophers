//
// Created by qli on 08/02/2021.
//

#include <stdlib.h>
#include "philo_one.h"
#include "libft/libft.h"

void process_argv_input(int argc, char **argv, t_common *common)
{
	common->number_of_philosophers = ft_atoi(argv[1]);
	common->time_to_die = ft_atoi(argv[2]);
	common->time_to_eat = ft_atoi(argv[3]);
	common->time_to_sleep = ft_atoi(argv[4]);
	if (argc == 6)
		common->number_of_times_each_philosopher_must_eat = ft_atoi(argv[5]);
	else
		common->number_of_times_each_philosopher_must_eat = -1;
	common->life_status = 1;
}

int validate_setup_data(t_common common)
{
	if (common.number_of_philosophers <= 0 || common.time_to_die <= 0 || common.time_to_eat <= 0 || common.time_to_sleep <= 0 || common.number_of_times_each_philosopher_must_eat == 0)
	{
		printf("Provided data not valid.\n");
		return (-1);
	}
	return (0);
}

void init_each_philo(t_philo *philo, t_common *common)
{
	int i;

	i = 0;
	philo = malloc(sizeof(t_philo) * common->number_of_philosophers);
	while (i < common->number_of_philosophers)
	{
		philo[i].num = i + 1;
		philo[i].status_mutex = malloc(sizeof(pthread_mutex_t));
		pthread_mutex_init(philo[i].status_mutex, NULL);
		gettimeofday(&philo[i].begin_time, NULL);
		gettimeofday(&philo[i].last_eat_time, NULL);
		philo[i].common = common;
		i++;
	}
}

void	init_fork_mutexes(t_common *common)
{
	int i;

	i = 0;
	common->fork_mutexs = malloc(sizeof(pthread_mutex_t) * common->number_of_philosophers);
	while (i < common->number_of_philosophers)
	{
		pthread_mutex_init(&common->fork_mutexs[i], NULL);
		i++;
	}
}

void set_philo_fork_mutexs(t_philo *philo, t_common *common)
{
	int i;

	i = 0;
	philo[i].left_fork_mutex = &common->fork_mutexs[i];
	philo[i].right_fork_mutex = &common->fork_mutexs[common->number_of_philosophers - 1];
	i++;
	while (i < common->number_of_philosophers)
	{
		philo[i].left_fork_mutex = &common->fork_mutexs[i];
		philo[i].right_fork_mutex = &common->fork_mutexs[i - 1];
		i++;
	}
}

void init_philo_threads(t_philo *philo, t_common common)
{
	int i;

	i = 0;
	while (i < common.number_of_philosophers)
	{
		philo->action_thread = malloc(sizeof(pthread_t) * common.number_of_philosophers);
		philo->status_thread = malloc(sizeof(pthread_t) * common.number_of_philosophers);
		pthread_create(philo[i].action_thread, NULL, start_action, &philo[i]);
		pthread_create(philo[i].status_thread, NULL, check_status, &philo[i]);
		i++;
	}
	i = 0;
	while (i < common.number_of_philosophers)
	{
		pthread_join(*philo[i].action_thread, NULL);
		pthread_join(*philo[i].status_thread, NULL);
		i++;
	}
}