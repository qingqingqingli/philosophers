//
// Created by qli on 17/02/2021.
//

#include "../headers/start_action.h"
#include "../headers/time_calculation.h"
#include "../headers/print.h"
#include "../headers/clean_up.h"

int 	grab_forks(t_philosopher *philo)
{
	sem_wait(philo->setup->fork_sema);
	print_prompt(philo, "has taken a fork\n");
	sem_wait(philo->setup->fork_sema);
	print_prompt(philo, "has taken a fork\n");
	return (0);
}

int	philo_eat(t_philosopher *philo)
{
	sem_wait(philo->setup->check_status_sema);
	print_prompt(philo, "is eating\n");
	gettimeofday(&philo->last_eat_time, NULL);
	sem_post(philo->setup->check_status_sema);
	accurately_sleep(philo->setup->time_to_eat * 1000);
	philo->time_of_eaten++;
	sem_post(philo->setup->fork_sema);
	sem_post(philo->setup->fork_sema);
	if (philo->time_of_eaten == \
	philo->setup->number_of_times_each_philosopher_must_eat)
		return (1);
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

void	*start_action(void *arg)
{
	t_philosopher	*philo;

	philo = arg;
	while (philo->setup->life_status)
	{
		grab_forks(philo);
		if (philo_eat(philo))
			return (NULL);
		philo_sleep(philo);
		philo_think(philo);
	}
	return (NULL);
}
