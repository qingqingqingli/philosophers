//
// Created by qli on 17/02/2021.
//

#include "../headers/start_action.h"
#include "../headers/time_calculation.h"
#include "../headers/print.h"

int 	lock_left_fork(t_philosopher *philo)
{
	pthread_mutex_lock(philo->left_fork_mutex);
	print_prompt(philo, "has taken a left fork");
	return 0;
}

int 	lock_right_fork(t_philosopher *philo)
{
	pthread_mutex_lock(philo->right_fork_mutex);
	print_prompt(philo, "has taken a right fork");
	return 0;
}

int 	grab_forks(t_philosopher *philo)
{
	if (philo->num % 2)
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
	pthread_mutex_lock(&philo->status_mutex);
	print_prompt(philo, "is eating");
	gettimeofday(&philo->last_eat_time, NULL);
	pthread_mutex_unlock(&philo->status_mutex);
	usleep(philo->setup->time_to_eat * 1000);
	pthread_mutex_unlock(philo->left_fork_mutex);
	pthread_mutex_unlock(philo->right_fork_mutex);
	return 0;
}

int 	philo_sleep(t_philosopher *philo)
{
	print_prompt(philo, "is sleeping");
	usleep(philo->setup->time_to_sleep * 1000);
	return 0;
}

int 	philo_think(t_philosopher *philo)
{
	print_prompt(philo, "is thinking");
	return 0;
}

void*	start_action(void *arg)
{
	t_philosopher *philo;

	philo = arg;
	while (philo->setup->life_status)
	{
		if (grab_forks(philo) || philo_eat(philo) || philo_sleep(philo) || philo_think(philo))
			return NULL;
	}
	return NULL;
}
