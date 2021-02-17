//
// Created by qli on 17/02/2021.
//

#include "../headers/print.h"
#include "../headers/time_calculation.h"

int 	print_prompt(t_philosopher *philo, char *prompt)
{
	int ret;
	char *color[6]= {"\033[31m", "\033[32m", "\033[33m", "\033[34m", "\033[35m", "\033[36m"};

	ret = 0;
	if (!philo->setup->life_status)
		return (0);
	gettimeofday(&philo->now, NULL);
	ret = philo->num % 6;
	printf(color[ret]);
	printf("[%ld] \t [%d] \t ", get_elapsed_milli(&philo->begin_time, &philo->now), philo->num);
	printf("%s\n", prompt);
	printf(RESET);
	return (1);
}