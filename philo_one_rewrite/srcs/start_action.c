//
// Created by qli on 17/02/2021.
//

#include "../headers/start_action.h"
#include "../headers/time_calculation.h"

void 	lock_left_fork(t_philosopher *philo)
{
	pthread_mutex_lock(philo->left_fork_mutex);
	gettimeofday(&philo->now, NULL);
	printf("[%ld] \t [%d] \t has taken a left fork\n", get_elapsed_milli(&philo->begin_time, &philo->now), philo->num);
}

void 	lock_right_fork(t_philosopher *philo)
{
	pthread_mutex_lock(philo->right_fork_mutex);
	gettimeofday(&philo->now, NULL);
	printf("[%ld] \t [%d] \t has taken a left fork\n", get_elapsed_milli(&philo->begin_time, &philo->now), philo->num);
}

void 	grab_forks(t_philosopher *philo)
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
}

void	philo_eat(t_philosopher *philo)
{
	pthread_mutex_lock(&philo->status_mutex);
	gettimeofday(&philo->now, NULL);
	printf("[%ld] \t [%d] \t is eating\n", get_elapsed_milli(&philo->begin_time, &philo->now), philo->num);
	gettimeofday(&philo->last_eat_time, NULL);
	pthread_mutex_unlock(&philo->status_mutex);
	usleep(philo->setup->time_to_eat * 1000);
	pthread_mutex_unlock(philo->left_fork_mutex);
	pthread_mutex_unlock(philo->right_fork_mutex);
}

void 	philo_sleep(t_philosopher *philo)
{
	gettimeofday(&philo->now, NULL);
	printf("[%ld] \t [%d] \t is sleeping\n", get_elapsed_milli(&philo->begin_time, &philo->now), philo->num);
	usleep(philo->setup->time_to_sleep * 1000);
}

void 	philo_think(t_philosopher *philo)
{
	gettimeofday(&philo->now, NULL);
	printf("[%ld] \t [%d] \t is thinking\n", get_elapsed_milli(&philo->begin_time, &philo->now), philo->num);
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
