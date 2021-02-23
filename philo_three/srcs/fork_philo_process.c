//
// Created by qli on 23/02/2021.
//

#include "../headers/fork_philo_process.h"
#include "../headers/check_status.h"
#include "../headers/start_action.h"

int	fork_philo_process(t_setup *setup, t_philosopher *philos)
{
	int	i;
	int	status;

	i = 0;
	status = 0;
	while (i < setup->number_of_philosophers)
	{
		philos[i].fork_id = fork();
		if (philos[i].fork_id == -1)
			return (-1);
		if (philos[i].fork_id == 0)
		{
			pthread_create(&philos[i].philo_status_thread, NULL, \
			check_status, &philos[i]);
			start_action(&philos[i]);
			pthread_join(philos[i].philo_status_thread, NULL);
		}
		usleep(100);
		i++;
	}
	while (1)
	{
		if (waitpid(-1, &status, 0) <= 0)
			break ;
	}
	return (0);
}
