//
// Created by qli on 17/02/2021.
//

#include "../headers/start_action.h"
#include "../headers/support_functions.h"
#include "../headers/print.h"

int 	lock_left_fork(t_philosopher *philo)
{
	pthread_mutex_lock(philo->left_fork_mutex);
	print_prompt(philo, "has taken a left fork\n");
	return 0;
}

int 	lock_right_fork(t_philosopher *philo)
{
	pthread_mutex_lock(philo->right_fork_mutex);
	print_prompt(philo, "has taken a right fork\n");
	return 0;
}

int 	grab_forks(t_philosopher *philo)
{
	if (!philo->num % 2)
	{
		lock_left_fork(philo);
		lock_right_fork(philo);
	}
	else
	{
		lock_right_fork(philo);
		lock_left_fork(philo);
	}
	return 0;
}

int		philo_eat(t_philosopher *philo)
{
	pthread_mutex_lock(&philo->setup->status_mutex);
	print_prompt(philo, "is eating\n");
	gettimeofday(&philo->last_eat_time, NULL);
	pthread_mutex_unlock(&philo->setup->status_mutex);
	accurately_sleep(philo->setup->time_to_eat * 1000);
	philo->time_of_eaten++;
	pthread_mutex_unlock(philo->left_fork_mutex);
	pthread_mutex_unlock(philo->right_fork_mutex);
	if (philo->time_of_eaten == philo->setup->number_of_times_each_philosopher_must_eat)
		return (1);
	return 0;
}

int 	philo_sleep(t_philosopher *philo)
{
	if (print_prompt(philo, "is sleeping\n") == 1)
		return (1);
	accurately_sleep(philo->setup->time_to_sleep * 1000);
	return 0;
}

int 	philo_think(t_philosopher *philo)
{
	return (print_prompt(philo, "is thinking\n"));
}

void*	start_action(void *arg)
{
	t_philosopher *philo;

	philo = arg;
	while (philo->setup->life_status)
	{
		grab_forks(philo);
		philo_eat(philo);
		philo_sleep(philo);
		philo_think(philo);
	}
	return NULL;
}
