//
// Created by qli on 17/02/2021.
//

#include <stdio.h>
#include "../headers/clean_up.h"
#include "../headers/libft_functions.h"

int	set_sema_dead(t_setup *setup, int return_val)
{
	setup->sema_status = dead;
	setup->life_status = dead;
	return (return_val);
}

void 	clean_up_philos(t_philosopher *philos)
{
	free(philos);
}

void 	clean_up_setup_semaphores(t_setup *setup)
{
	if (setup->fork_sema)
		sem_close(setup->fork_sema);
	if (setup->write_sema)
		sem_close(setup->write_sema);
	if (setup->check_status_sema)
		sem_close(setup->check_status_sema);
	if (setup->check_death_sema)
		sem_close(setup->check_death_sema);
}

int 	clean_up(t_setup *setup, t_philosopher *philos, int return_value)
{
	if (philos)
	{
		if (!setup->sema_status)
		{
			write(STDERR_FILENO, SEMA_ERROR, ft_strlen(SEMA_ERROR));
			return_value = -1;
		}
		clean_up_setup_semaphores(setup);
		clean_up_philos(philos);
	}
	return (return_value);
}
