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
	printf("%s", color[philo->num % 6]);
	printf("[%ld] \t [%d] \t %s\n", get_elapsed_milli(&philo->begin_time, &philo->now), philo->num, prompt);
	pthread_mutex_unlock(&philo->setup->write_mutex);
	return (0);
}
