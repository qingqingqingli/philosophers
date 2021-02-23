//
// Created by qli on 23/02/2021.
//

#include <stdlib.h>
#include "../headers/fork_child_process.h"
#include "../headers/start_action.h"
#include <wait.h>
#include "../headers/check_status.h"

int	init_philo_threads(t_philosopher *philo)
{
	if (pthread_create(&philo->philo_status_thread, NULL, \
		check_status, philo))
			return (1);
	if (pthread_join(philo->philo_status_thread, NULL))
		return (1);
	return (0);
}

int	fork_philo_processes(t_philosopher *philos, int num)
{
	int	i;

	i = 0;
	while (i < num)
	{
		philos[i].fork_id = fork();
		if (philos[i].fork_id == -1)
			return (1); // need to update
		if (philos[i].fork_id == 0)
		{
			init_philo_threads(&philos[i]);
			start_action(&philos[i]);
			exit (0);
		}
		usleep(100);
		i++;
	}
	return (0);
}

void 	wait_for_child_processes(t_philosopher *philos, int num)
{
	int	i;
	int status;

	status = 0;
	i = 0;
	while (!waitpid(-1, &status, 0));
	printf("kill all processes\n");
	while (i < num)
	{
		kill(philos[i].fork_id, 9);
		i++;
	}
}
