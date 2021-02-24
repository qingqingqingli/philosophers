//
// Created by qli on 24/02/2021.
//

#include "../headers/check_death.h"
#include "../headers/clean_up.h"

void	kill_all_process(t_philosopher *philos)
{
	int	i;

	i = 0;
	while (i < philos->setup->number_of_philosophers)
	{
		kill(philos[i].fork_id, 9);
		i++;
	}
}

void	*check_death(void *arg)
{
	t_philosopher	*philos;

	philos = arg;
	sem_wait(philos->setup->check_death_sema);
	sem_wait(philos->setup->death_block_sema);
	kill_all_process(philos);
	sem_post(philos->setup->death_block_sema);
	sem_post(philos->setup->check_death_sema);
	return (NULL);
}

int 	create_check_death_thread(t_setup *setup, t_philosopher *philos)
{
	if (pthread_create(&setup->check_death_thread, NULL, check_death, philos))
		return (1);
	return (0);
}
