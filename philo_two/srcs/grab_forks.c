//
// Created by qli on 19/02/2021.
//

#include "../headers/grab_forks.h"

int 	lock_left_fork(t_philosopher *philo)
{
	pthread_mutex_lock(philo->left_fork_mutex);
	print_prompt(philo, "has taken a left fork\n");
	return (0);
}

int 	lock_right_fork(t_philosopher *philo)
{
	pthread_mutex_lock(philo->right_fork_mutex);
	print_prompt(philo, "has taken a right fork\n");
	return (0);
}
