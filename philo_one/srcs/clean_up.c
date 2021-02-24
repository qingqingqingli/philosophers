//
// Created by qli on 17/02/2021.
//

#include "../headers/clean_up.h"
#include "../headers/libft_functions.h"

int	set_mutex_dead(t_setup *setup, int return_val)
{
	setup->mutexes_status = dead;
	setup->life_status = dead;
	return (return_val);
}

void 	clean_up_philos(t_philosopher *philos)
{
	free(philos);
}

void 	clean_up_setup_mutexes(t_setup *setup)
{
	int	i;

	i = 0;
	if (setup->fork_mutexs)
	{
		while (i < setup->number_of_philosophers)
		{
			pthread_mutex_destroy(&setup->fork_mutexs[i]);
			i++;
		}
		free(setup->fork_mutexs);
		pthread_mutex_destroy(&setup->write_mutex);
		pthread_mutex_destroy(&setup->check_status_mutex);
	}
}

int 	clean_up(t_setup *setup, t_philosopher *philos, int return_value)
{
	if (philos)
	{
		if (!setup->mutexes_status)
		{
			write(STDERR_FILENO, MUTEX_ERROR, ft_strlen(MUTEX_ERROR));
			return_value = -1;
		}
		clean_up_setup_mutexes(setup);
		clean_up_philos(philos);
	}
	return (return_value);
}
