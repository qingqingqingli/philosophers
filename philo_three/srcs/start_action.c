//
// Created by qli on 17/02/2021.
//

#include "../headers/start_action.h"
#include "../headers/time_calculation.h"
#include "../headers/print.h"
#include "../headers/clean_up.h"

int 	grab_forks(t_philosopher *philo)
{
	if (sem_wait(philo->setup->fork_sema))
		return (set_sema_dead(philo->setup, 1));
	print_prompt(philo, "has taken a fork\n");
	if (sem_wait(philo->setup->fork_sema))
		return (set_sema_dead(philo->setup, 1));
	print_prompt(philo, "has taken a fork\n");
	return (0);
}

int	philo_eat(t_philosopher *philo)
{

	print_prompt(philo, "is eating\n");
	gettimeofday(&philo->last_eat_time, NULL);
	accurately_sleep(philo->setup->time_to_eat * 1000);
	philo->time_of_eaten++;
	sem_post(philo->setup->fork_sema);
	sem_post(philo->setup->fork_sema);
	if (philo->time_of_eaten == \
	philo->setup->number_of_times_each_philosopher_must_eat)
	{
		print_prompt(philo, "has died.\n");
		sem_post(philo->setup->check_status_sema);
		exit (0);
	}
	return (0);
}

int 	philo_sleep(t_philosopher *philo)
{
	if (print_prompt(philo, "is sleeping\n") == 1)
		return (1);
	accurately_sleep(philo->setup->time_to_sleep * 1000);
	return (0);
}

int 	philo_think(t_philosopher *philo)
{
	return (print_prompt(philo, "is thinking\n"));
}

int 	start_action(t_philosopher	*philo)
{
	while (philo->setup->life_status)
	{
<<<<<<< HEAD
		if (grab_forks(philo) || philo_eat(philo) || \
		philo_sleep(philo) || philo_think(philo))
			exit (0);
=======
		if (check_status(philo))
			grab_forks(philo);
		if (check_status(philo))
			philo_eat(philo);
		if (check_status(philo))
			philo_sleep(philo);
		if (check_status(philo))
			philo_think(philo);
>>>>>>> parent of dbe587a... philo_three - create separate fork files
	}
	return (0);
}
