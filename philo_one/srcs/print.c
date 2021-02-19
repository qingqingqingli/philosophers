//
// Created by qli on 17/02/2021.
//

#include "../headers/print.h"
#include "../headers/support_functions.h"

int 	print_prompt(t_philosopher *philo, char *prompt)
{
	char *color[6]= {"\033[31m", "\033[32m", "\033[33m", "\033[34m", "\033[35m", "\033[36m"};

	if (!philo->setup->life_status)
		return (1);
	pthread_mutex_lock(&philo->setup->write_mutex);
	gettimeofday(&philo->now, NULL);
	write(STDOUT_FILENO, color[philo->num % 6], ft_strlen(color[philo->num % 6]));
	write(STDOUT_FILENO, "[", 1);
	ft_putnbr_fd(get_elapsed_milli(&philo->begin_time, &philo->now), STDOUT_FILENO);
	write(STDOUT_FILENO, "] \t", 3);
	write(STDOUT_FILENO, "[", 1);
	ft_putnbr_fd(philo->num, STDOUT_FILENO);
	write(STDOUT_FILENO, "] \t", 3);
	write(STDOUT_FILENO, prompt, ft_strlen(prompt));
	write(STDOUT_FILENO, "\n", 1);
	pthread_mutex_unlock(&philo->setup->write_mutex);
	return (0);
}
