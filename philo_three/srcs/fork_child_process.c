//
// Created by qli on 23/02/2021.
//

#include <stdlib.h>
#include "../headers/fork_child_process.h"
#include "../headers/start_action.h"
#include <wait.h>
#include "../headers/check_status.h"

int	fork_philo_processes(t_philosopher *philos, int num)
{
	int	i;
	int status;

	i = 0;
	status = 0;
	while (i < num)
	{
		philos[i].fork_id = fork();
		if (philos[i].fork_id == -1)
			return (1);
		if (philos[i].fork_id == 0)
		{
			if (pthread_create(&philos[i].philo_status_thread, NULL, \
		check_status, &philos[i]))
				exit (1);
			start_action(&philos[i]);
			if (pthread_join(philos[i].philo_status_thread, NULL))
				exit (1);
			exit (0);
		}
		usleep(100);
		i++;
	}
	while (1)
	{
		if (waitpid(-1, &status, 0) <= 0)
			break;
	}
	return (0);
}
