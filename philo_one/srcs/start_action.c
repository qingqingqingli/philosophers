//
// Created by qli on 17/02/2021.
//

#include "../headers/start_action.h"
#include "../headers/time_calculation.h"
#include "../headers/print.h"
#include "../headers/grab_forks.h"
#include "../headers/clean_up.h"

int 	grab_forks(t_philosopher *philo)
{
	if (philo->num % 2)
	{
		if (lock_left_fork(philo))
			return (1);
		if (lock_right_fork(philo))
		{
			pthread_mutex_unlock(philo->left_fork_mutex);
			return (1);
		}
	}
	else
	{
		if (lock_right_fork(philo))
			return (1);
		if (lock_left_fork(philo))
		{
			pthread_mutex_unlock(philo->right_fork_mutex);
			return (1);
		}
	}
	return (0);
}

int	philo_eat(t_philosopher *philo)
{
	if (pthread_mutex_lock(&philo->setup->check_status_mutex))
	{
		pthread_mutex_unlock(philo->left_fork_mutex);
		pthread_mutex_unlock(philo->right_fork_mutex);
		return (set_mutex_dead(philo->setup, 1));
	}
	print_prompt(philo, "is eating\n");
	gettimeofday(&philo->last_eat_time, NULL);
	pthread_mutex_unlock(&philo->setup->check_status_mutex);
	accurately_sleep(philo->setup->time_to_eat * 1000);
	philo->time_of_eaten++;
	pthread_mutex_unlock(philo->left_fork_mutex);
	pthread_mutex_unlock(philo->right_fork_mutex);
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
		if (grab_forks(philo) || philo_eat(philo) || \
		philo_sleep(philo) || philo_think(philo))
			return (NULL);
	}
	return (NULL);
}
